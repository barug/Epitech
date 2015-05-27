/*
** maze_solver.h for maze_solver in /home/barthe_g/rendu/initiation_AI/maze_solver/include
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Apr 23 16:51:32 2015 Barthelemy Gouby
** Last update Sun May 17 20:20:22 2015 Barthelemy Gouby
*/

#ifndef MAZESOLV_H_
# define MAZESOLV_H_

# define VSTD (0x1)
# define UNVSTD (0x2)
# define WALL (0x3)
# define PATH (0x4)

typedef struct	s_dimensions
{
  int		height;
  int		width;
}		t_dimensions;

typedef struct	s_cell
{
  int		x;
  int		y;
  struct s_cell	*cell_before;
}		t_cell;

#endif /* !MAZESOLV_H_ */
