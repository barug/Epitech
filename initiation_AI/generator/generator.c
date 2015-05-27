/*
** generator.c for maze_generator in /home/barthe_g/rendu/initiation_AI
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Apr  8 14:10:34 2015 barthelemy gouby
** Last update Sun May 17 16:15:27 2015 Barthelemy Gouby
*/

#include <stdlib.h>
#include <time.h>
#include "my.h"
#include "maze_generator.h"

t_unvistd		find_unvisited_cells(t_maze **maze, t_progress *progress,
				      int height, int width)
{
  t_unvistd	unvistd;
  int		x;
  int		y;

  x = progress->current_cell->x;
  y = progress->current_cell->y;
  unvistd.nbr = 0;
  if (x - 2 >= 0 && maze[y][x - 2].state == UNVISTD)
    {
      unvistd.cells[unvistd.nbr] =&(maze[y][x - 2]);
      ++unvistd.nbr;
    }
  if (x + 2 < width && maze[y][x + 2].state == UNVISTD)
    {
      unvistd.cells[unvistd.nbr] = &(maze[y][x + 2]);
      ++unvistd.nbr;
    }
  if (y - 2 >= 0 && maze[y - 2][x].state == UNVISTD)
    {
      unvistd.cells[unvistd.nbr] = &(maze[y - 2][x]);
      ++unvistd.nbr;
    }
  if (y + 2 < height && maze[y + 2][x].state == UNVISTD)
    {
      unvistd.cells[unvistd.nbr] = &(maze[y + 2][x]);
      ++unvistd.nbr;
    }
  return (unvistd);
}

void		open_wall(t_maze **maze, t_progress *progress, t_maze *cell_to_visit)
{
  if (cell_to_visit->x > progress->current_cell->x)
    maze[progress->current_cell->y][progress->current_cell->x + 1].state = OPEN;
  if (cell_to_visit->x < progress->current_cell->x)
    maze[progress->current_cell->y][progress->current_cell->x - 1].state = OPEN;
  if (cell_to_visit->y > progress->current_cell->y)
    maze[progress->current_cell->y + 1][progress->current_cell->x].state = OPEN;
  if (cell_to_visit->y < progress->current_cell->y)
    maze[progress->current_cell->y - 1][progress->current_cell->x].state = OPEN;
}

int		visit_random_cell(t_maze **maze, t_progress *progress,
				  int height, int width)
{
  t_unvistd	unvistd;
  t_maze	*cell_to_visit;
  int		random;
  int		i;

  i = 0;
  random = 0;
  unvistd = find_unvisited_cells(maze, progress, height, width);
  if (unvistd.nbr == 0)
    return (1);
  while (i < unvistd.nbr)
    ++i;
  random = rand() % (unvistd.nbr);
  cell_to_visit = unvistd.cells[random];
  open_wall(maze, progress, cell_to_visit);
  cell_to_visit->state = VISTD;
  cell_to_visit->cell_before = progress->current_cell;
  progress->current_cell = cell_to_visit;
  ++progress->cells_visited;
  return (0);
}

int		generator(t_maze **maze, int height, int width)
{
  t_progress	progress;

  progress.cells_to_visit = (width / 2 + width % 2) * (height / 2 + height % 2);
  progress.cells_visited = 1;
  progress.current_cell = &maze[0][0];
  progress.current_cell->state = VISTD;
  while (42)
    {
      if (progress.cells_visited == progress.cells_to_visit)
	return (0);
      if (visit_random_cell(maze, &progress, height, width) == 1)
	progress.current_cell = progress.current_cell->cell_before;
    }
  return (-1);
}
