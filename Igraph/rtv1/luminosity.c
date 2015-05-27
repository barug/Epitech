/*
** luminosity.c for rtv1 in /home/barthe_g/rendu/igraph/B2/MUL_2014_rtv1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Mar 10 17:18:01 2015 barthelemy gouby
** Last update Sun Mar 15 23:12:27 2015 barthelemy gouby
*/		

#include <stdio.h>
#include <math.h>
#include "rtv1.h"

int		make_luminosity(t_coordinate *lightvector,
				t_coordinate *normal_vect,
				t_object *object)
{
  double	cos_a;
  int		color;
  unsigned char	*cast;

  color = object->color;
  cast = (unsigned char*)(&color);
  cos_a = (lightvector->x * normal_vect->x + lightvector->y * normal_vect->y
	   + lightvector->z * normal_vect->z) /
    (sqrt(SQUARE(lightvector->x) + SQUARE(lightvector->y)
	  + SQUARE(lightvector->z))
     * sqrt(SQUARE(normal_vect->x) + SQUARE(normal_vect->y)
	    + SQUARE(normal_vect->z)));
  cast[0] = cast[0] * cos_a;
  cast[1] = cast[1] * cos_a;
  cast[2] = cast[2] * cos_a;
  cast[3] = cast[3] * cos_a;
  return (color);
}

int		luminosity_sphere(t_pov *intersection_p,
				  t_coordinate *lightvector,
				  t_object *object)
{
  t_coordinate	normal_vect;

  normal_vect.x = intersection_p->x - object->x;
  normal_vect.y = intersection_p->y - object->y;
  normal_vect.z = intersection_p->z - object->z;
  return (make_luminosity(lightvector, &normal_vect, object));
}

int		luminosity_cone(t_pov *intersection_p,
				t_coordinate *lightvector,
				t_object *object)
{
  t_coordinate  normal_vect;

  normal_vect.x = intersection_p->x - object->x;
  normal_vect.y = intersection_p->y - object->y;
  normal_vect.z = intersection_p->z - object->z;
  rotate_x(&(normal_vect.y), &(normal_vect.z), - object->anglex);
  rotate_y(&(normal_vect.x), &(normal_vect.z), - object->angley);
  rotate_x(&(normal_vect.x), &(normal_vect.y), - object->anglez);
  normal_vect.z = - object->parameter * normal_vect.z;
  rotate_x(&(normal_vect.y), &(normal_vect.z), object->anglex);
  rotate_y(&(normal_vect.x), &(normal_vect.z), object->angley);
  rotate_x(&(normal_vect.x), &(normal_vect.y), object->anglez);
  return (make_luminosity(lightvector, &normal_vect, object));
}
int             luminosity_plane(t_pov *intersection_p,
				 t_coordinate *lightvector,
				 t_object *object)
{
  t_coordinate  normal_vect;

  normal_vect.x= 0;
  normal_vect.y= 0;
  normal_vect.z= 1;
  intersection_p = intersection_p;
  rotate_x(&(normal_vect.y), &(normal_vect.z), object->anglex);
  rotate_y(&(normal_vect.x), &(normal_vect.z), object->angley);
  rotate_x(&(normal_vect.x), &(normal_vect.y), object->anglez);
  return (make_luminosity(lightvector, &normal_vect, object));
}

int             luminosity_cylinder(t_pov *intersection_p,
				    t_coordinate *lightvector,
				    t_object *object)
{
  t_coordinate  normal_vect;

  normal_vect.x = intersection_p->x - object->x;
  normal_vect.y = intersection_p->y - object->y;
  normal_vect.z = intersection_p->y - object->z;
  rotate_x(&(normal_vect.y), &(normal_vect.z), - object->anglex);
  rotate_y(&(normal_vect.x), &(normal_vect.z), - object->angley);
  rotate_x(&(normal_vect.x), &(normal_vect.y), - object->anglez);
  normal_vect.z = 0;
  rotate_x(&(normal_vect.y), &(normal_vect.z), object->anglex);
  rotate_y(&(normal_vect.x), &(normal_vect.z), object->angley);
  rotate_x(&(normal_vect.x), &(normal_vect.y), object->anglez);
  return (make_luminosity(lightvector, &normal_vect, object));
}
