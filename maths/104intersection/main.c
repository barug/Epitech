/*
** main.c for main.c in /home/barthe_g/rendu/104intersection
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Dec 17 12:43:00 2014 barthelemy gouby
** Last update Thu Dec 18 15:14:27 2014 barthelemy gouby
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "mathinclude.h"
#include "my.h"

void		set_parameters(t_coordinate *point, t_coordinate *vector, double *parameter, char **argv)
{
  point->x = my_getnbr(argv[2]);
  point->y = my_getnbr(argv[3]);
  point->z = my_getnbr(argv[4]);
  vector->x = my_getnbr(argv[5]);
  vector->y = my_getnbr(argv[6]);
  vector->z = my_getnbr(argv[7]);
  *parameter = my_getnbr(argv[8]);
}

void		display_solutions(t_coordinate **solutions)
{
  int		i;

  i = 0;
  while (solutions != NULL && solutions[i] != NULL)
    i++;
  printf("nombres de points d'intersection: %i\n", i);
  if (i >= 1)
    printf("point 1: (%f, %f, %f)\n", solutions[0]->x, solutions[0]->y, solutions[0]->z);
  if (i == 2)
    printf("point 2: (%f, %f, %f)\n", solutions[1]->x, solutions[1]->y, solutions[1]->z);
  i = 0;
  while (solutions != NULL && solutions[i] != NULL)
    free(solutions[i++]);
  if (solutions != NULL)
    free(solutions);
}

t_coordinate	**calculate_solutions(t_coordinate *point,t_coordinate *vector, double parameter, char **argv)
{
  t_coordinate	**solutions;
	
  if (my_getnbr(argv[1]) == 1)
    {
      printf("sphere de rayon %f\n", parameter);
      solutions = sphere(point, vector, parameter);
    }
  if (my_getnbr(argv[1]) == 2)
    {
      printf("cylindre de rayon %f\n", parameter);
      solutions = cylinder(point, vector, parameter);
    }
  if (my_getnbr(argv[1]) == 3)
    {
      printf("cylindre d'angle %f\n", parameter);
      solutions = cone(point, vector, parameter);
    }
  return  (solutions);
}

int		main(int argc, char **argv)
{
  t_coordinate	point;
  t_coordinate	vector;
  t_coordinate	**solutions;
  double       	parameter;

  if (argc != 9)
    return (0);
  set_parameters(&point, &vector, &parameter, argv);
  solutions = calculate_solutions(&point, &vector, parameter, argv);
  printf("droite passant par le point (%f, %f, %f), de vecteur directeur (%f, %f, %f)\n"
	 , point.x, point.y, point.z, vector.x, vector.y, vector.z);
  display_solutions(solutions); 
  return (0);
}
