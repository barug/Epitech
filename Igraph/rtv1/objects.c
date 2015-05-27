/*
** objects.c for rtv1 in /home/barthe_g/rendu/igraph/B2/MUL_2014_rtv1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Mar 10 12:11:06 2015 barthelemy gouby
** Last update Sun Mar 15 23:19:37 2015 barthelemy gouby
*/

#include <math.h>
#include "my.h"
#include "rtv1.h"

void		get_intersection(t_intersect *intersect, double delta,
				 double a, double b)
{
  double	k1;
  double	k2;

  if (delta == 0)
    intersect->k = - b / (2 * a);
  if (delta > ZERO)
    {
      k1 = (-b - sqrt(delta)) / (2 * a);
      k2 = (-b + sqrt(delta)) / (2 * a);
      if (k1 < k2 && k1 > ZERO)
        intersect->k = k1;
      else if (k2 > ZERO)
        intersect->k = k2;
    }
}

t_intersect	sphere(t_pov pov, t_coordinate rayvector,
                       t_object *object)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  t_intersect	intersect;

  intersect.k = 0;
  intersect.object = object;
  transform_pov(&pov, &rayvector, object);
  a = SQUARE(rayvector.x) + SQUARE(rayvector.y) + SQUARE(rayvector.z);
  b = 2 * (pov.x * rayvector.x + pov.y * rayvector.y + pov.z * rayvector.z);
  c = SQUARE(pov.x) + SQUARE(pov.y) + SQUARE(pov.z)
    - SQUARE(object->parameter);
  delta = SQUARE(b) - 4 * a * c;
  get_intersection(&intersect, delta, a, b);
  return (intersect);
}

t_intersect	cone(t_pov pov,
                       t_coordinate rayvector, t_object *object)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	parameter;
  t_intersect	intersect;

  intersect.k = 0;
  intersect.object = object;
  transform_pov(&pov, &rayvector, object);
  parameter = object->parameter * (PI / 180);
  a = SQUARE(rayvector.x) + SQUARE(rayvector.y) -
    SQUARE(rayvector.z) / SQUARE(tan(parameter));
  b = 2 * (pov.x * rayvector.x + pov.y *
           rayvector.y - pov.z * rayvector.z / SQUARE(tan(parameter)));
  c = SQUARE(pov.x) + SQUARE(pov.y) -
    SQUARE(pov.z) / SQUARE(tan(parameter));
  delta = SQUARE(b) - 4 * a * c;
  get_intersection(&intersect, delta, a, b);
  return (intersect);
}

t_intersect	cylinder(t_pov pov,
                           t_coordinate rayvector, t_object *object)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  t_intersect	intersect;

  intersect.k = 0;
  intersect.object = object;
  transform_pov(&pov, &rayvector, object);
  a = SQUARE(rayvector.x) + SQUARE(rayvector.y);
  b = 2 * (pov.x * rayvector.x + pov.y * rayvector.y);
  c = SQUARE(pov.x) + SQUARE(pov.y) - SQUARE(object->parameter);
  delta = SQUARE(b) - 4 * a * c;
  get_intersection(&intersect, delta, a, b);
  return (intersect);
}

t_intersect	plane(t_pov pov, t_coordinate rayvector, t_object *object)
{
  double	k;
  t_intersect	intersect;

  transform_pov(&pov, &rayvector, object);
  k = - (pov.z / rayvector.z);
  if (k < ZERO)
    {
      intersect.k = 0;
      return (intersect);
    }
  intersect.k = k;
  intersect.object = object;
  return (intersect);
}
