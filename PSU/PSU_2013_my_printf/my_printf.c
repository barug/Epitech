/*
** my_printf.c for printf in /home/barthe_g/rendu/printf
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Nov 10 18:11:27 2014 barthelemy gouby
** Last update Sun Nov 16 18:38:22 2014 barthelemy gouby
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "functions.h"
#include "include.h"

int	no_function(char c)
{
  if (c != 'i' && c != 'd' && c != 's' && c != 'o' && c != 'u'
      && c != 'x' && c != 'X' && c != 'b' && c != 'c' && c != 'S' && c != 'p')
    {
      my_putchar('%');
      my_putchar(c);
    }
}

t_functions	*set_functions()
{
  static	t_functions functions[] = {{'i', &put_int},
					   {'d', &put_int},
					   {'s', &put_str},
					   {'S', &put_str_S},
					   {'o', &put_unsigned_o},
					   {'u', &put_unsigned_u},
					   {'x', &put_unsigned_x},
					   {'X', &put_unsigned_X},
					   {'b', &put_unsigned_b},
					   {'c', &put_int_c},
					   {'p', &put_void},
					   {0, 0}};
  return (functions);
}

int     printer(va_list ap, char c)
{
  int   i;
  int	lenght;
  static t_functions *functions;

  functions = set_functions();
  i = 0;
  while (functions[i].c != 0)
    {
      if (c == functions[i].c)
	{
	  lenght = functions[i].f(ap);
	  break;
	}
      i++;
    }
  return (lenght);
}

int	my_printf(const char *fmt, ...)
{
  va_list	ap;
  int		i;
  int		lenght;

  lenght = 0;
  i = 0;
  va_start(ap, fmt);

  while (fmt[i] != 0)
    {
      if (fmt[i] != '%')
	{
	  my_putchar(fmt[i]);
	  lenght++;
	}
      if (fmt[i] == '%')
  	{
  	  i++;
	  no_function(fmt[i]);
  	  lenght = lenght + printer(ap, fmt[i]);
  	}
      i++;
    }
  va_end(ap);
  return (lenght);
}
