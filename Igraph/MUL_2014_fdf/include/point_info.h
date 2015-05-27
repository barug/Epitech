/*
** point_info.h for point_info in /home/barthe_g/rendu/MUL_2014_fdf/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Dec  1 17:56:59 2014 barthelemy gouby
** Last update Thu Dec  4 17:46:53 2014 barthelemy gouby
*/

#ifndef POINTINFO_H_
# define POINTINFO_H_

typedef struct	s_point_info
{
  int	x;
  int	y;
  int	z;
}		t_point_info;	

#endif /* !POINTINFO_H_ */

#ifndef MAPINFO_H_
# define MAPINFO_H_

typedef struct	s_map_info
{
  int	nbr_of_lines;
  int   size_of_lines;
  int	max_height;
}		t_map_info;

#endif /* !MAPINFO_H_ */
