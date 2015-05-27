/*
** equations.c for equations in /home/barthe_g/rendu/104intersection
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Dec 18 14:29:47 2014 barthelemy gouby
** Last update Thu Dec 18 14:37:52 2014 barthelemy gouby
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "mathinclude.h"
#include "my.h"

t_coordinate    **get_solutions(double *lambda1, double *lambda2,
				t_coordinate *point, t_coordinate *vector)
{
  t_coordinate  **solutions;

  solutions = malloc (3 * sizeof(t_coordinate*));
  if (solutions == NULL)
    return (NULL);
  solutions[0] = malloc(sizeof(t_coordinate));
  if (solutions[0] == NULL)
    return (NULL);
  solutions[0]->x = point->x + *lambda1 * vector->x;
  solutions[0]->y = point->y + *lambda1 * vector->y;
  solutions[0]->z = point->z + *lambda1 * vector->z;
  solutions[1] = malloc(sizeof(t_coordinate));
  if (solutions[1] == NULL)
    return (NULL);
  if (lambda2 != NULL)
    {
      solutions[2] = malloc(sizeof(t_coordinate));
      if (solutions[2] == NULL)
        return (NULL);
      solutions[1]->x = point->x + *lambda2 * vector->x;
      solutions[1]->y = point->y + *lambda2 * vector->y;
      solutions[1]->z = point->z + *lambda2 * vector->z;
      solutions[2] = NULL;
    }
  else
    solutions[1] = NULL;
  return(solutions);
}

t_coordinate    **sphere(t_coordinate *point,
			 t_coordinate *vector, int parameter)
{
  int           a;
  int           b;
  int           c;
  int           delta;
  double        lambda1;
  double        lambda2;
  t_coordinate  **solutions;

  a = SQUARE(vector->x) + SQUARE(vector->y) + SQUARE(vector->z);
  b = 2 * (point->x * vector->x + point->y * vector->y + point->z * vector->z);
  c = SQUARE(point->x) + SQUARE(point->y) + SQUARE(point->z) - SQUARE(parameter);
  delta = SQUARE(b) - 4 * a * c;
  if (delta < 0)
    solutions = NULL;
  if (delta == 0)
    {
      lambda1 = - b / (2 * a);
      solutions = get_solutions(&lambda1, NULL, point, vector);
    }
  if (delta > 0)
    {
      lambda1 = (-b - sqrt(delta)) / (2 * a);
      lambda2 = (-b + sqrt(delta)) / (2 * a);
      solutions = get_solutions(&lambda1, &lambda2, point, vector);
    }
  return (solutions);
}

t_coordinate    **cylinder(t_coordinate *point,
			   t_coordinate *vector, int parameter)
{
  int           a;
  int           b;
  int           c;
  int           delta;
  double        lambda1;
  double        lambda2;
  t_coordinate  **solutions;

  a = SQUARE(vector->x) + SQUARE(vector->y);
  b = 2 * (point->x * vector->x + point->y * vector->y);
  c = SQUARE(point->x) + SQUARE(point->y) - SQUARE(parameter);
  delta = SQUARE(b) - 4 * a * c;
  if (delta < 0)
    solutions = NULL;
  if (delta == 0)
    {
      lambda1 = - b / (2 * a);
      solutions = get_solutions(&lambda1, NULL, point, vector);
    }
  if (delta > 0)
    {
      lambda1 = (-b - sqrt(delta)) / (2 * a);
      lambda2 = (-b + sqrt(delta)) / (2 * a);
      solutions = get_solutions(&lambda1, &lambda2, point, vector);
    }
  return (solutions);
}

t_coordinate    **cone(t_coordinate *point,
		       t_coordinate *vector, double parameter)
{
  int           a;
  int           b;
  int           c;
  int           delta;
  double        lambda1;
  double        lambda2;
  t_coordinate  **solutions;

  parameter = parameter * (PI / 180);
  a = SQUARE(vector->x) + SQUARE(vector->y) -
    SQUARE(vector->z) / SQUARE(tan(parameter));
  b = 2 * (point->x * vector->x + point->y *
	   vector->y - point->z * vector->z / SQUARE(tan(parameter)));
  c = SQUARE(point->x) + SQUARE(point->y) -
    SQUARE(point->z) / SQUARE(tan(parameter));
  delta = SQUARE(b) - 4 * a * c;
  if (delta < 0)
    solutions = NULL;
  if (delta == 0)
    {
      lambda1 = - b / (2 * a);
      solutions = get_solutions(&lambda1, NULL, point, vector);
    }
  if (delta > 0)
    {
      lambda1 = (-b - sqrt(delta)) / (2 * a);
      lambda2 = (-b + sqrt(delta)) / (2 * a);
      solutions = get_solutions(&lambda1, &lambda2, point, vector);
    }
  return (solutions);
}
