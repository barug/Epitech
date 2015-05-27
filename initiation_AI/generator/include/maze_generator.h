/*
** maze_generator.h for maze_generator in /home/barthe_g/rendu/initiation_AI/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Apr  8 15:51:00 2015 barthelemy gouby
** Last update Thu Apr  9 14:54:00 2015 barthelemy gouby
*/

#ifndef MAZEGEN_H_
# define MAZEGEN_H_

#define CELL		1
#define WALL		2
#define VISTD		3
#define UNVISTD		4
#define OPEN		5
#define	CLOSED		6

typedef struct		s_maze
{
  char			type;
  char			state;
  int			x;
  int			y;
  struct s_maze		*cell_before;
}			t_maze;

typedef struct		s_progress
{
  int			cells_to_visit;
  int			cells_visited;
  t_maze		*current_cell;
}			t_progress;

typedef struct		s_unvistd
{
  t_maze		*cells[4];
  int			nbr;
}			t_unvistd;

int			generator(t_maze **maze, int height, int width);

#endif /* !MAZEGEN_H_ */
