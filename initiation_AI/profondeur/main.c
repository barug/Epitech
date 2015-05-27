/*
** main.c for maze_solver in /home/barthe_g/rendu/initiation_AI/maze_solver
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Apr 23 14:16:52 2015 Barthelemy Gouby
** Last update Tue May 26 19:45:40 2015 Barthelemy Gouby
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "maze_solver.h"

char	**get_maze(int fd)
{
  char	**maze;
  int	x;
  int	y;
  char	c;

  x = 0;
  y = 0;
  if ((maze = malloc((y + 2) * sizeof(char *))) == NULL)
    return (NULL);
  maze[y] = NULL;
  while (read(fd, &c, 1))
    {
      if (c == '\n')
	{
	  maze[y++][x] = '\0';
	  x = 0;
	  if ((maze = realloc(maze, (y + 2) * sizeof(char *))) == NULL)
	    return (NULL);
	  maze[y] = NULL;
	}
      else
	{
	  if ((maze[y] = realloc(maze[y], (x + 2) * sizeof(char))) == NULL)
	    return (NULL);
	  if (c == 'X')
	    maze[y][x++] = WALL;
	  else if (c == '*')
	    maze[y][x++] = UNVSTD;
	}
    }
  maze[y + 1] = NULL;
  return (maze);
}

int	write_maze(char **maze)
{
  int	x;
  int	y;
  int	fd;

  x = 0;
  y = 0;
  if ((fd = open("./result", O_RDWR | O_CREAT,
		 S_IRUSR | S_IWUSR | S_IRGRP)) == -1)
    return (-1);
  while (maze[y])
    {
      while (maze[y][x])
        {
	  if (maze[y][x] == WALL)
	    write(fd, "X", 1);
          if (maze[y][x] == UNVSTD || maze[y][x] == VSTD)
	    write(fd, "*", 1);
          if (maze[y][x] == PATH)
	    write(fd, "o", 1);
          ++x;
        }
      write(fd, "\n", 1);
      x = 0;
      ++y;
    }
  return (0);
}

t_cell		*find_unvisited_cell(char **maze, t_cell *current_cell, t_dimensions *dimensions)
{
  int		x;
  int		y;
  t_cell	*next_cell;
  
  x = current_cell->x;
  y = current_cell->y;
  next_cell = malloc(sizeof(t_cell));
  if (x - 1 >= 0 && maze[y][x - 1] == UNVSTD)
    {
      maze[y][x - 1] = PATH;
      next_cell->x = x - 1;
      next_cell->y = y;
      next_cell->cell_before = current_cell;
      return (next_cell);
    }
  if (x + 1 < dimensions->width && maze[y][x + 1] == UNVSTD)
    {
      maze[y][x + 1] = PATH;
      next_cell->x = x + 1;
      next_cell->y = y;
      next_cell->cell_before = current_cell;
      return (next_cell);
    }
  if (y - 1 >= 0 && maze[y - 1][x] == UNVSTD)
    {
      maze[y - 1][x] = PATH;
      next_cell->x = x;
      next_cell->y = y - 1;
      next_cell->cell_before = current_cell;
      return (next_cell);
    }
  if (y + 1 < dimensions->height && maze[y + 1][x] == UNVSTD)
    {
      maze[y + 1][x] = PATH;
      next_cell->x = x;
      next_cell->y = y + 1;
      next_cell->cell_before = current_cell;
      return (next_cell);
    }
  return (NULL);
}

t_dimensions	get_height_and_width(char **maze)
{
  t_dimensions	dimensions;
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (maze[y])
    ++y;
  while (maze[0][x])
    ++x;
  dimensions.height = y;
  dimensions.width = x;
  return (dimensions);
}

int		depth_first_search(char **maze, t_dimensions *dimensions)
{
  t_cell	*current_cell;
  t_cell	*next_cell;

  current_cell = malloc(sizeof(t_cell));
  current_cell->y = 0;
  current_cell->x = 0;
  current_cell->cell_before = NULL;
  while (current_cell->y != (dimensions->height - 1) || current_cell->x != (dimensions->width - 1))
    {
      if ((next_cell = find_unvisited_cell(maze, current_cell, dimensions)) == NULL && current_cell->cell_before != NULL)
	{
	  maze[current_cell->y][current_cell->x] = VSTD;
	  current_cell = current_cell->cell_before;
	}
      else
	current_cell = next_cell;
    }
  return (0);
}

int		main(int argc, char **argv)
{
  int		fd;
  char		**maze;
  t_dimensions	dimensions;

  if (argc < 2)
    {
      my_printf("usage: ./profondeur [maze_name]\n");
      return (0);
    }
  if ((fd = open(argv[1],O_RDONLY)) == -1)
    return (-1);
  if ((maze = get_maze(fd)) == NULL)
    return (-1);
  dimensions = get_height_and_width(maze);
  depth_first_search(maze, &dimensions);
  write_maze(maze);  
  return (0);
}
