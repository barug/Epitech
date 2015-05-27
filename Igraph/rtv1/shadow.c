/*
** shadow.c for rtv1 in /home/barthe_g/rendu/igraph/B2/MUL_2014_rtv1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Mar 15 23:03:14 2015 barthelemy gouby
** Last update Sun Mar 15 23:17:48 2015 barthelemy gouby
*/

#include "rtv1.h"

int		find_if_shadow(t_pov *intersection_p,
                               t_object *objects, t_coordinate *lightvector)
{
  t_intersect	intersect;
  int		i;

  i = 0;
  while (i < OBJECTS_NB)
    {
      intersect = calculate_intersection(intersection_p,
                                         lightvector, &(objects[i]));
      if (intersect.k > ZERO && intersect.k < 1)
        return (1);
      i++;
    }
  return (0);
}
