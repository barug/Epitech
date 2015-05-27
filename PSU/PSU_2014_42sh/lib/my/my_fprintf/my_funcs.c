/*
** my_funcs.c for my_printf in /home/dupard_e/rendus/PSU_2013_my_printf
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Nov  5 21:35:14 2014 Erwan Dupard
** Last update Tue Nov 18 16:35:31 2014 Erwan Dupard
*/

#include <stdlib.h>
#include <stdarg.h>
#include "./my_funcs.h"
#include "../my.h"

int		my_fdeci(int fd, va_list p)
{
  int		n;
  int		i;

  i = 0;
  n = va_arg(p, int);
  i = my_fputnbr(fd, n);
  return (i);
}

int		my_flhex(int fd, va_list p)
{
  unsigned int	n;
  int		i;

  n = va_arg(p, unsigned int);
  i = my_fputnbr_base_unsigned(fd, n, "0123456789abcdef");
  return (i);
}

int		my_fLhex(int fd, va_list p)
{
  unsigned int	n;
  int		i;

  n = va_arg(p, unsigned int);
  i = my_fputnbr_base_unsigned(fd, n, "0123456789ABCDEF");
  return (i);
}

int		my_fhexp(int fd, va_list p)
{
  void		*point;
  int		i;

  i = 0;
  point = va_arg(p, void *);
  my_fputstr(fd, "0x");
  i += 2;
  i += my_fputnbr_base_addr(fd, (unsigned long)point, "0123456789abcdef");
  return (i);
}

int		my_fstrp(int fd, va_list p)
{
  char		*str;

  str = va_arg(p, char *);
  if (str == NULL)
    {
      my_fputstr(fd, "(null)");
      return (6);
    }
  else
    my_fputstr(fd, str);
  return (my_strlen(str));
}
