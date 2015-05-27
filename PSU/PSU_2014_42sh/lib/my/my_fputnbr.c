/*
** my_put_nbr.c for my_put_nbr in /home/dupard_e/oklm
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Oct  2 19:35:35 2014 Erwan Dupard
** Last update Sun Nov 23 13:40:04 2014 Erwan Dupard
*/

#include "./my.h"

int		my_fifnbless(int *nb)
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

int		my_fputnbr(int fd, int nb)
{
  int		i;

  i = 0;
  if (nb <= -2147483647 || nb >= 2147483647)
    return (0);
  i += my_fifnbless(&nb);
  if (nb == 0)
    {
      my_fputstr(fd, "0\b");
      i += 1;
    }
  if (nb >= 10)
    {
      i += my_fputnbr(fd, nb / 10);
      i += my_fputnbr(fd, nb % 10);
    }
  else if (nb <= 9)
    {
      my_fputchar(fd, nb + 48);
      i++;
    }
  return (i);
}

int		my_fputnbr_unsigned(int fd, unsigned int nb)
{
  int		i;

  i = 0;
  if (nb >= 4294967295)
    return (0);
   if (nb == 0)
    {
      my_fputstr(fd, "0\b");
      i += 1;
    }
  if (nb >= 10)
    {
      i += my_fputnbr(fd, nb / 10);
      i += my_fputnbr(fd, nb % 10);
    }
  else if (nb <= 9)
    {
      my_fputchar(fd, nb + 48);
      i++;
    }
  return (i);
}
