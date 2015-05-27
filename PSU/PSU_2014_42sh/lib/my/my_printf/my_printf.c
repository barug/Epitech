/*
** my_printf.c for my_printf in /home/dupard_e/rendus/PSU_2013_my_printf
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Nov  5 14:43:20 2014 Erwan Dupard
** Last update Tue Nov 18 16:30:03 2014 Erwan Dupard
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../my.h"
#include "./my_printf.h"
#include "./my_funcs.h"

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, format);
  while (*format)
    {
      if (*format == '%')
	{
	  i += corr(ap, *(format + 1));
	  format++;
	}
      else
	{
	  my_putchar(*format);
	  i++;
	}
      format++;
    }
  return (i);
}

int		corr(va_list p, char f)
{
  int		i;
  static t_form	formats[] = {{'d', &my_deci},
			     {'x', &my_lhex},
			     {'i', &my_deci},
			     {'X', &my_Lhex},
			     {'p', &my_hexp},
			     {'s', &my_strp},
			     {'u', &my_unsigned},
			     {'o', &my_octal},
			     {'S', &my_spec},
			     {'c', &my_char},
			     {'b', &my_bin},
			     {0, NULL}};

  i = check(p, formats, f);
  return (i);
}

int		check(va_list p, t_form formats[], char f)
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
	  j += formats[i].f(p);
	  ok = 1;
	}
      i++;
    }
  if (ok == 0)
    {
      my_putchar('%');
      my_putchar(f);
      j += 2;
    }
  return (j);
}

int		get_int_len(int n)
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
