/*
** my_put_nbr.c for my_put_nbr in /home/dupard_e/oklm
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Oct  2 19:35:35 2014 Erwan Dupard
** Last update Sun Nov 23 13:38:28 2014 Erwan Dupard
*/

#include "./my.h"

int		my_ifnbless(int *nb)
{
  int		i;

  i = 0;
  if (*nb < 0)
    {
      *nb = -(*nb);
      my_putchar('-');
      i++;
    }
  return (i);
}

int		my_put_nbr(int nb)
{
  int		i;

  i = 0;
  if (nb <= -2147483647 || nb >= 2147483647)
    return (0);
  i += my_ifnbless(&nb);
  if (nb == 0)
    {
      my_putstr("0\b");
      i += 1;
    }
  if (nb >= 10)
    {
      i += my_put_nbr(nb / 10);
      i += my_put_nbr(nb % 10);
    }
  else if (nb <= 9)
    {
      my_putchar(nb + 48);
      i++;
    }
  return (i);
}

int		my_putnbr_unsigned(unsigned int nb)
{
  int		i;

  i = 0;
  if (nb >= 4294967295)
    return (0);
   if (nb == 0)
    {
      my_putstr("0\b");
      i += 1;
    }
  if (nb >= 10)
    {
      i += my_put_nbr(nb / 10);
      i += my_put_nbr(nb % 10);
    }
  else if (nb <= 9)
    {
      my_putchar(nb + 48);
      i++;
    }
  return (i);
}
