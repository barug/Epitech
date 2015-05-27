/*
** my_putnbr_base.c for my_putnbr_base in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:38:02 2014 barthelemy gouby
** Last update Fri Nov 14 17:12:30 2014 barthelemy gouby
*/

#include <stdlib.h>

int     length(int nbr, int s)
{
  int   n;

  n = 0;
  while (nbr != 0)
    {
      nbr = nbr / s;
      n = n + 1;
    }
}

int	my_putnbr_base(int nbr, char *base)
{
  char  *out;
  int   i;
  int   a;
  int   size;

  i = 0;
  size = 0;
  while (base[size] != 0)
    size = size + 1;
  out = malloc(length(nbr, size));
  if (out == NULL)
    return (0);
  if (out == 0)
    return (0);
  while (nbr != 0)
    {
      a = nbr % size;
      out[i] = base[a];
      i = i + 1;
      nbr = nbr / size;
    }
  my_revstr(out);
  my_putstr(out);
}
