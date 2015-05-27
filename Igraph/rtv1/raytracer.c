/*
** raytracer.c for rtv1 in /home/barthe_g/rendu/igraph/B2/MUL_2014_rtv1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Mar  4 13:28:49 2015 barthelemy gouby
** Last update Sun Mar 15 23:18:39 2015 barthelemy gouby
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "rtv1.h"

t_intersect		calculate_intersection(t_pov *pov, t_coordinate *rayvector,
					       t_object *object)
{
  t_intersect	intersect;

  if (my_strcmp(object->type, "sphere") == 0)
    intersect = sphere(*pov, *rayvector, object);
  if (my_strcmp(object->type, "plane") == 0)
    intersect = plane(*pov, *rayvector, object);
  if (my_strcmp(object->type, "cone") == 0)
    intersect = cone(*pov, *rayvector, object);
  if (my_strcmp(object->type, "cylinder") == 0)
    intersect = cylinder(*pov, *rayvector, object);
  return (intersect);
}

t_coordinate		*calculate_vector(t_pov *pov, t_pixel *pixel,
					  t_coordinate *rayvector)
{
  rayvector->x = 500;
  rayvector->y = (WIN_WIDTH / 2) - pixel->x;
  rayvector->z = (WIN_HEIGHT / 2) - pixel->y;
  rotate_x(&(rayvector->y), &(rayvector->z), pov->anglex);
  rotate_y(&(rayvector->x), &(rayvector->z), pov->angley);
  rotate_z(&(rayvector->x), &(rayvector->y), pov->anglez);
  return (rayvector);
}

int		find_color(t_intersect *intersectsaved, t_pov *pov,
			   t_coordinate *rayvector, t_coordinate *lightsource,
			   t_object *objects)
{
  t_pov		intersection_p;
  t_coordinate	lightvector;

  intersection_p.x = pov->x + intersectsaved->k * rayvector->x;
  intersection_p.y = pov->y + intersectsaved->k * rayvector->y;
  intersection_p.z = pov->z + intersectsaved->k * rayvector->z;
  lightvector.x = lightsource->x - intersection_p.x;
  lightvector.y = lightsource->y - intersection_p.y;
  lightvector.z = lightsource->z - intersection_p.z;
  if (find_if_shadow(&intersection_p, objects, &lightvector) == 1)
    return (0x00000000);
  if (my_strcmp(intersectsaved->object->type, "sphere") == 0)
    return (luminosity_sphere(&intersection_p, &lightvector,
			      intersectsaved->object));
  if (my_strcmp(intersectsaved->object->type, "cone") == 0)
    return (luminosity_cone(&intersection_p, &lightvector,
			    intersectsaved->object));
  if (my_strcmp(intersectsaved->object->type, "plane") == 0)
    return (luminosity_sphere(&intersection_p, &lightvector,
			      intersectsaved->object));
  if (my_strcmp(intersectsaved->object->type, "cylinder") == 0)
    return (luminosity_cylinder(&intersection_p, &lightvector,
				intersectsaved->object));
  return (0x00000000);
}

int		calculate_pixel(t_pov *pov, t_pixel *pixel,
				t_object *objects, t_coordinate *lightsource)
{
  t_coordinate	rayvector;
  int		i;
  int		color;
  t_intersect	intersect;
  t_intersect	intersectsaved;

  intersectsaved.k = 0.0;
  i = 0;
  calculate_vector(pov, pixel, &rayvector);
  color = 0x00000000;
  while (i < OBJECTS_NB)
    {
      intersect = calculate_intersection(pov, &rayvector, &objects[i]);
      if ((intersect.k < intersectsaved.k && intersect.k > 0) ||
	  (intersect.k > 0  && intersectsaved.k == 0))
	intersectsaved = intersect;
      i++;
    }
  if (intersectsaved.k != 0)
    color = find_color(&intersectsaved, pov, &rayvector, lightsource, objects);
  return (color);
}

 int		raytracer(t_imgdata *imgdata, t_pov *pov,
			  t_object *objects, t_coordinate *lightsource)
{
  t_pixel	pixel;
  int		color;

  pixel.x = 0;
  pixel.y = 0;
  while (pixel.y < WIN_HEIGHT)
    {
      while (pixel.x < WIN_WIDTH)
	{
	  color = calculate_pixel(pov, &pixel, objects, lightsource);
	  my_pixel_put_to_image(imgdata, pixel.x, pixel.y, color);
	  pixel.x++;
	}
      pixel.x = 0;
      pixel.y++;
    }
  return (0);
}
