/*
** my_putnbr_base_uns.c for my_putnbr_base_uns in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Nov 12 15:39:40 2014 barthelemy gouby
** Last update Thu Nov 13 13:30:44 2014 barthelemy gouby
*/

#include <stdlib.h>

int     my_putnbr_base_uns(unsigned int nbr, char *base)
{
  char  *out;
  int   i;
  int   a;
  int   size;
  int	l;

  l = 0;
  i = 0;
  size = 0;
  while (base[size] != 0)
    size = size + 1;
  out = malloc(length(nbr, size));
  if (out == 0)
    return (0);
  while (nbr != 0)
    {
      a = nbr % size;
      out[i] = base[a];
      i = i + 1;
      nbr = nbr / size;
      l++;
    }
  my_revstr(out);
  my_putstr(out);
  return (l);
}
