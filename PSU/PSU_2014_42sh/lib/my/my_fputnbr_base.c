/*
** my_putnbr_base.c for my_putnbr_base in /home/dupard_e/rendu/Piscine_C_J06/ex_15
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 13:45:40 2014 Erwan Dupard
** Last update Tue Nov 18 15:34:24 2014 Erwan Dupard
*/

#include "./my.h"

int		my_fputnbr_base(int fd, int n, char *base)
{
  int		r;
  int		d;
  int		base_n;
  int		i;

  i = 0;
  base_n = my_strlen(base);
  if (n < 0)
    {
      my_fputchar(fd, '-');
      i++;
      n = -n;
    }
  d = 1;
  while ((n / d) >= base_n)
    d = d * base_n;
  while (d > 0)
    {
      r = (n /d) % base_n;
      my_fputchar(fd, base[r]);
      i++;
      d = d / base_n;
    }
  return (i);
}

int		my_fputnbr_base_unsigned(int fd, unsigned int n, char *base)
{
  unsigned int	r;
  unsigned int	d;
  unsigned int	base_n;
  unsigned int	i;

  i = 0;
  base_n = my_strlen(base);
  d = 1;
  while ((n / d) >= base_n)
    d = d * base_n;
  while (d > 0)
    {
      r = (n /d) % base_n;
      my_fputchar(fd, base[r]);
      i++;
      d = d / base_n;
    }
  return (i);
}

int			my_fputnbr_base_addr(int fd, unsigned long n, char *base)
{
  unsigned long		r;
  unsigned long		d;
  unsigned int		base_n;
  unsigned int		i;

  i = 0;
  base_n = my_strlen(base);
  d = 1;
  while ((n / d) >= base_n)
    d = d * base_n;
  while (d > 0)
    {
      r = (n /d) % base_n;
      my_fputchar(fd, base[r]);
      i++;
      d = d / base_n;
    }
  return (i);
}
