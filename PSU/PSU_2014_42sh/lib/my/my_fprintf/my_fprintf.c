/*
** my_printf.c for my_printf in /home/dupard_e/rendus/PSU_2013_my_printf
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Nov  5 14:43:20 2014 Erwan Dupard
** Last update Tue Nov 18 16:41:39 2014 Erwan Dupard
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../my.h"
#include "./my_fprintf.h"
#include "./my_funcs.h"

int		my_fprintf(int fd, const char *format, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, format);
  while (*format)
    {
      if (*format == '%')
	{
	  i += corrf(fd, ap, *(format + 1));
	  format++;
	}
      else
	{
	  my_fputchar(fd, *format);
	  i++;
	}
      format++;
    }
  return (i);
}

int		corrf(int fd, va_list p, char f)
{
  int		i;
  static t_form	formats[] = {{'d', &my_fdeci},
			     {'x', &my_flhex},
			     {'i', &my_fdeci},
			     {'X', &my_fLhex},
			     {'p', &my_fhexp},
			     {'s', &my_fstrp},
			     {'u', &my_funsigned},
			     {'o', &my_foctal},
			     {'S', &my_fspec},
			     {'c', &my_fchar},
			     {'b', &my_fbin},
			     {0, NULL}};

  i = checkf(fd, p, formats, f);
  return (i);
}

int		checkf(int fd, va_list p, t_form formats[], char f)
{
  int		j;
  int		i;
  int		ok;

  ok = 0;
  i = 0;
  j = 0;
  while (formats[i].c != 0)
    {
      if (formats[i].c == f)
	{
	  j += formats[i].f(fd, p);
	  ok = 1;
	}
      if (formats[i].c == 'n')
	  my_feenn(p, j, &ok);
      i++;
    }
  if (ok == 0)
    {
      my_fputchar(fd, '%');
      my_fputchar(fd, f);
      j += 2;
    }
  return (j);
}

int		get_int_lenf(int n)
{
  unsigned int	len;
  unsigned char	c;

  c = 1;
  len = 0;
  if (n < 0)
    len++;
  n = ABS(n);
  while (c < 10)
    {
      if (n < my_power_rec(10, c))
	len += c;
      c++;
    }
  return (len);
}
