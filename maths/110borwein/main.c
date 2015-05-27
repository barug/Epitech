/*
** main.c for borwein in /home/barthe_g/rendu/maths/B2/110borwein
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Apr 16 14:50:12 2015 Barthelemy Gouby
** Last update Sun Apr 19 22:12:20 2015 Barthelemy Gouby
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "110borwein.h"

long double	f(int n, long double x)
{
  long double	i;
  long double	result;

  i = 1.0;
  result = sin(x) / x;
  while (i <= n)
    {
      result *= sin(x / ((2 * i) + 1)) / (x / ((2 * i) + 1));
      i += 1.0;
    }
  return (result);
}

long double	rectangle(int n)
{
  long double	i;
  long double	sum;
  long double	result;

  sum = 0.0;
  i = 0.0;
  while (i < N)
    {
      sum += f(n, A + i * H);
      i += 1.0;
    }
  result = (B - A) / N * sum;
  return (result);
}

long double	trapeze(int n)
{
  int		i;
  long double	sum;
  long double	result;

  i = 1;
  sum = 0.0;
  while (i < N)
    {
      sum += f(n, A + i * H);
      ++i;
    }
  result = ((B - A) / (2 * N)) * (f(n, A) + f(n, B) + 2 * sum);
  return (result);
}

long double	simpson(int n)
{
  int		i;
  long double	sum1;
  long double	sum2;
  long double	result;

  i = 0;
  sum1 = 0.0;
  sum2 = 0.0;
   while (i < N)
    {
      sum1 += f(n, A + i * H + H / 2);
      ++i;
    }
   i = 1;
  while (i < N)
    {
      sum2 += f(n, A + i * H);
      ++i;
    }
  result = ((B - A) / (6 * N)) * (f(n, A) + f(n, B) + 2 * sum2 + 4 * sum1);
  return (result);
}

int		main(int argc, char **argv)
{
  int		n;
  long double	result;

  if (argc != 2)
    return (-1);
  n = atoi(argv[1]);
  result = rectangle(n);
  printf("méthode des rectangles\nIO = %.10Lf\n", result);
  printf("diff = %.10Lf\n", result - M_PI / 2);
  result = trapeze(n);
  printf("méthode des trapèzes\nIO = %.10Lf\n", result);
  printf("diff = %.10Lf\n", result - M_PI / 2);
  result = simpson(n);
  printf("méthode de Simpson\nIO = %.10Lf\n", result);
  printf("diff = %.10Lf\n", result - M_PI / 2);
  return (0);
}
