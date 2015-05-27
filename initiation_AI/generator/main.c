/*
** main.c for maze_generator in /home/barthe_g/rendu/initiation_AI
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Apr  6 13:52:52 2015 barthelemy gouby
** Last update Sun May 17 16:43:34 2015 Barthelemy Gouby
*/

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "maze_generator.h"

t_maze		**pre_generator(int height, int width)
{
  t_maze	**maze;
  int		x;
  int		y;
  char		wall;
  char		alternate;

  x = 0;
  y = 0;
  wall = 0;
  alternate = 0;
  maze = malloc((height + 1) * sizeof(t_maze*));
  while (y < height)
    {
      maze[y] = malloc((width + 1) * sizeof(t_maze));
      while (x < width)
	{
	  if (alternate == 0 && wall == 0)
	    {
	      maze[y][x].type = CELL;
	      maze[y][x].state = UNVISTD;
	      maze[y][x].cell_before = NULL;
	      maze[y][x].x = x;
	      maze[y][x].y = y;
	    }
	  else
	    {
	      maze[y][x].type = WALL;
	      maze[y][x].state = CLOSED;
	      maze[y][x].cell_before = NULL;
	      maze[y][x].x = x;
	      maze[y][x].y = y;
	    }
	  if (wall == 0)
	    wall = 1;
	  else
	    wall = 0;
	  ++x;
	}
      maze[y][x].type = 0;
      x = 0;
      wall = 0;
      if (alternate == 0)
	alternate = 1;
      else
	alternate = 0;
      ++y;
    }
  maze[y] = NULL;
  return (maze);
}

int		opening_check(int op_y, int op_x, int width, int height, t_maze **maze)
{
  int		adjacent_cells;

  adjacent_cells = 0;
  if (op_x - 1 >= 0 && maze[op_y][op_x - 1].type == CELL)
    ++adjacent_cells;
  if (op_x + 1 < width && maze[op_y][op_x + 1].type == CELL)
    ++adjacent_cells;
  if (op_y - 1 >= 0 && maze[op_y - 1][op_x].type == CELL)
    ++adjacent_cells;
  if (op_y + 1 < height && maze[op_y + 1][op_x].type == CELL)
    ++adjacent_cells;
  if (adjacent_cells == 2)
    return (0);
  return (1);
}

int		imperfect_gen(int height, int width, t_maze **maze)
{
  int		openings;
  int		op_x;
  int		op_y;

  openings = (height + width) / 5;
  while (openings)
    {
      op_x = rand() % width;
      op_y = rand() % height;
      while (maze[op_y][op_x].type != WALL || maze[op_y][op_x].state != CLOSED
	     || opening_check(op_y, op_x, width, height, maze) == 1)
	{
	  op_x = rand() % width;
	  op_y = rand() % height;
	}
      maze[op_y][op_x].state = OPEN;
      --openings;
    }
  return (0);
}

int		write_maze_to_file(t_maze **maze, char *name, int width)
{
  int		fd;
  int		x;
  int		y;

  x = 0;
  y = 0;
  if ((fd = open(name, O_RDWR | O_CREAT,
		 S_IRUSR | S_IWUSR | S_IRGRP)) == -1)
    return (-1);
  while (maze[y])
    {
      while (maze[y][x].type)
	{
          if ((maze[y][x].type == WALL && maze[y][x].state == CLOSED) ||
              (maze[y][x].type == CELL && maze[y][x].state == UNVISTD ))
            {
	      write(fd, "X", 1);
	    }
	  if ((maze[y][x].type == CELL && maze[y][x].state == VISTD)
	      || (maze[y][x].type == WALL && maze[y][x].state == OPEN))
            {
	      write(fd, "*", 1);
            }
          ++x;
	}
      if (y < width - 1)
	write(fd, "\n", 1);
      x = 0;
      ++y;
    }
  return (0);
}

void		add_solution(t_maze **maze, int height, int width)
{
  maze[height - 1][width - 1].type = CELL;
  maze[height- 1][width - 1].state = VISTD;
  maze[height - 2][width - 1].type = CELL;
  maze[height - 2][width - 1].state = VISTD;
  maze[height - 1][width - 2].type = CELL;
  maze[height - 1][width - 2].state = VISTD;
}

int		main(int argc, char **argv)
{
  int		height;
  int		width;
  t_maze	**maze;

  if (argc < 4)
    {
      printf("usage: ./generator [height] [width] [name]\n");
      return (0);
    }
  height = atoi(argv[1]);
  width = atoi(argv[2]);
  if (width < 5 || height < 5)
    {
      my_printf("values must be > 5\n");
      return (0);
    }
  srand(time(NULL));
  maze = pre_generator(height, width);
  generator(maze, height, width);
  imperfect_gen(height, width, maze);
  if ((height % 2) == 0 || (width % 2) == 0)
    add_solution(maze, height, width);
  if (write_maze_to_file(maze, argv[3], width) == -1)
    return (-1);
  return (0);
}
