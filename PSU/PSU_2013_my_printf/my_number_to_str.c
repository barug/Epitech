/*
** my_number_to_str.c for my number to str in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Nov  6 13:45:43 2014 barthelemy gouby
** Last update Fri Nov 14 16:25:28 2014 barthelemy gouby
*/

#include <stdlib.h>

char	*str_maker(char isneg, char *out, int div, int nb)
{
  int	i;

  i = 0;
  if (isneg == '-')
    {
      out[i] = '-';
      i++;
    }
  while (div > 0)
    {
      out[i] = nb / div + 48;
      nb = nb % div;
      div = div / 10;
      i++;
    }
  out[i] = 0;
  return (out);
}

char	*my_numbr_to_str(int nb)
{
  int	div;
  char	*out;
  int	size;
  char	isneg;

  div = 1;
  size = 0;
  isneg = 0;
  if (nb < 0)
    {
      isneg = '-';
      nb = nb * -1;
    }
  while (nb / div > 9)
    {
      div = div * 10;
      size++;
    }
  out = malloc((size + 1) * sizeof(char));
  if (out == NULL)
    return (0);
  out = str_maker(isneg, out, div, nb);
  return (out);
}
