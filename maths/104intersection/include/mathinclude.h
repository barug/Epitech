/*
** coordinate.h for coordinate.h in /home/barthe_g/rendu/104intersection/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Dec 17 12:48:09 2014 barthelemy gouby
** Last update Thu Mar  5 12:19:30 2015 barthelemy gouby
*/

#ifndef MATHINCLUDE_H_
# define MATHINCLUDE_H_

# define SQUARE(nb) ((nb) * (nb))
# define PI 3.1415926

typedef struct  s_coordinate
{
  double        x;
  double        y;
  double        z;
}               t_coordinate;

t_coordinate    **get_solutions(double *lambda1, double *lambda2,
                                t_coordinate *point, t_coordinate *vector);
t_coordinate    **sphere(t_coordinate *point,
                         t_coordinate *vector, int parameter);
t_coordinate    **cylinder(t_coordinate *point,
                           t_coordinate *vector, int parameter);
t_coordinate    **cone(t_coordinate *point,
                       t_coordinate *vector, double parameter);

#endif /* !MATHINCLUDE_H_ */
