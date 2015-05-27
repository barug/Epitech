/*
** my_funcs.c for my_printf in /home/dupard_e/rendus/PSU_2013_my_printf
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Nov  5 21:35:14 2014 Erwan Dupard
** Last update Tue Nov 18 16:28:00 2014 Erwan Dupard
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "./my_funcs.h"
#include "../my.h"

int		my_deci(va_list p)
{
  int		n;
  int		i;

  i = 0;
  n = va_arg(p, int);
  i = my_put_nbr(n);
  return (i);
}

int		my_lhex(va_list p)
{
  unsigned int	n;
  int		i;

  n = va_arg(p, unsigned int);
  i = my_putnbr_base_unsigned(n, "0123456789abcdef");
  return (i);
}

int		my_Lhex(va_list p)
{
  unsigned int	n;
  int		i;

  n = va_arg(p, unsigned int);
  i = my_putnbr_base_unsigned(n, "0123456789ABCDEF");
  return (i);
}

int		my_hexp(va_list p)
{
  void		*point;
  int		i;

  i = 0;
  point = va_arg(p, void *);
  my_putstr("0x");
  i += 2;
  i += my_putnbr_base_addr((unsigned long)point, "0123456789abcdef");
  return (i);
}

int		my_strp(va_list p)
{
  char		*str;

  str = va_arg(p, char *);
  if (str == NULL)
    {
      my_putstr("(null)");
      return (6);
    }
  else
    my_putstr(str);
  return (my_strlen(str));
}
