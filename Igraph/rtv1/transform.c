/*
** transform.c for rtv1 in /home/barthe_g/rendu/igraph/B2/MUL_2014_rtv1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Mar  9 16:24:43 2015 barthelemy gouby
** Last update Sun Mar 15 22:53:08 2015 barthelemy gouby
*/

#include <math.h>
#include "rtv1.h"

void		rotate_x(double *y, double *z, double angle)
{
  double	angle_rad;
  double	save_y;
  double	save_z;

  save_y = *y;
  save_z = *z;
  angle_rad = angle * (PI / 180);
  *y = cos(angle_rad) * (save_y) - sin(angle_rad) * (save_z);
  *z = sin(angle_rad) * (save_y) + cos(angle_rad) * (save_z);
}

void		rotate_y(double *x, double *z, double angle)
{
  double	angle_rad;
  double	save_x;
  double	save_z;

  save_x = *x;
  save_z = *z;
  angle_rad = angle * (PI / 180);
  *x = cos(angle_rad) * (save_x) + sin(angle_rad) * (save_z);
  *z = - sin(angle_rad) * (save_x) + cos(angle_rad) * (save_z);
}

void            rotate_z(double *x, double *y, double angle)
{
  double        angle_rad;
  double        save_x;
  double        save_y;

  save_x = *x;
  save_y = *y;
  angle_rad = angle * (PI / 180);
  *x = cos(angle_rad) * (save_x) - sin(angle_rad) * (save_y);
  *y = sin(angle_rad) * (save_x) + cos(angle_rad) * (save_y);
}

void		transform_pov(t_pov *tmp_pov, t_coordinate *tmp_vect,
			      t_object *object)
{
  tmp_pov->x = tmp_pov->x - object->x;
  tmp_pov->y = tmp_pov->y - object->y;
  tmp_pov->z = tmp_pov->z - object->z;
  rotate_x(&(tmp_pov->y), &(tmp_pov->z), - object->anglex);
  rotate_y(&(tmp_pov->x), &(tmp_pov->z), - object->angley);
  rotate_z(&(tmp_pov->x), &(tmp_pov->y), - object->anglez);
  rotate_x(&(tmp_vect->y), &(tmp_vect->z), - object->anglex);
  rotate_y(&(tmp_vect->x), &(tmp_vect->z), - object->angley);
  rotate_z(&(tmp_vect->x), &(tmp_vect->y), - object->anglez);
}
