
/*
** main.c for maze_solver in /home/barthe_g/rendu/initiation_AI/maze_solver
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Apr 23 14:16:52 2015 Barthelemy Gouby
** Last update Sun May 17 20:58:22 2015 Barthelemy Gouby
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
	  else if (c != 'X' && c != '*')
	    {
	      my_printf("invalid maze\n");
	      return (NULL);
	    }
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

int		add_cell_to_list(t_cell **list, t_cell *cell_before, int x, int y)
{
  t_cell	*tmp;
  t_cell	*new_cell;

  new_cell = malloc(sizeof(t_cell));
  new_cell->x = x;
  new_cell->y = y;
  new_cell->cell_before = cell_before;
  new_cell->next = NULL;
  tmp = *list;
  if (tmp == NULL)
    {
      *list = new_cell;
      return (0);
    }
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_cell;
  return (0);
}

void		find_unvisited_cells(char **maze, t_cell *graph, t_cell **to_visit, t_dimensions *dimensions)
{
  int		x;
  int		y;

  x = graph->x;
  y = graph->y;
  if (x - 1 >= 0 && maze[y][x - 1] == UNVSTD)
    {
      add_cell_to_list(to_visit, graph, x - 1, y);
      maze[y][x - 1] = VSTD;
    }
  if (x + 1 < dimensions->width && maze[y][x + 1] == UNVSTD)
    {
      add_cell_to_list(to_visit, graph, x + 1, y);
      maze[y][x + 1] = VSTD;
    }
  if (y - 1 >= 0 && maze[y - 1][x] == UNVSTD)
    {
      add_cell_to_list(to_visit, graph, x, y - 1);
      maze[y - 1][x] = VSTD;
    }
  if (y + 1 < dimensions->height && maze[y + 1][x] == UNVSTD)
    {
      add_cell_to_list(to_visit, graph, x, y + 1);
      maze[y + 1][x] = VSTD;
    }
}

t_dimensions	*get_and_check_height_and_width(char **maze)
{
  t_dimensions	*dimensions;
  int		x;
  int		y;

  x = 0;
  y = 0;
  dimensions = malloc(sizeof(t_dimensions));
  while (maze[y])
    ++y;
  while (maze[0][x])
    ++x;
  dimensions->height = y;
  dimensions->width = x;
  y = 0;
  x = 0;
  while (maze[y])
    {
      while (maze[y][x])
	++x;
      if (x != dimensions->width)
	{
	  my_printf("invalid maze\n");
	  return (NULL);
	}
      x = 0;
      ++y;
    }
  return (dimensions);
}

int		breadth_first_search(char **maze)
{
  t_cell	*graph;
  t_cell	*to_visit;
  t_dimensions	*dimensions;

  to_visit = NULL;
  if ((dimensions = get_and_check_height_and_width(maze)) == NULL)
    return (-1);
  graph = malloc(sizeof(t_cell));
  graph->x = 0;
  graph->y = 0;
  graph->cell_before = NULL;
  graph->next = NULL;
  while (graph->x != (dimensions->width - 1) || graph->y != (dimensions->height - 1))
    {
      find_unvisited_cells(maze, graph, &to_visit, dimensions);
      if (to_visit == NULL)
	{
	  my_printf("there is no solution\n");
	  return (-1);
	}
      graph = to_visit;
      to_visit = to_visit->next;
    }
  while (graph != NULL)
    {
      maze[graph->y][graph->x] = PATH;
      graph = graph->cell_before;
    }
  return (0);
}	

int	main(int argc, char **argv)
{
  int	fd;
  char	**maze;

  if (argc < 2)
    {
      my_printf("usage: ./maze_solver [maze_name]\n");
      return (0);
    }
  if ((fd = open(argv[1],O_RDONLY)) == -1)
    return (-1);
  if ((maze = get_maze(fd)) == NULL)
    return (-1);
  if (breadth_first_search(maze) == -1)
    return (-1);
  write_maze(maze);  
  return (0);
}
