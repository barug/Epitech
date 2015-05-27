/*
** my_funcs2.c for my_printf in /home/dupard_e/rendus/PSU_2013_my_printf
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Nov  5 21:41:51 2014 Erwan Dupard
** Last update Fri Nov 14 12:55:32 2014 Erwan Dupard
*/

#include <stdarg.h>
#include "./my_funcs.h"
#include "../my.h"
#include "./my_printf.h"

int		my_unsigned(va_list p)
{
  unsigned int	n;
  int		i;

  n = va_arg(p, unsigned int);
  i = my_putnbr_unsigned(n);
  return (i);
}

int		my_spec(va_list p)
{
  char		*str;
  int		i;

  i = 0;
  str = va_arg(p, char *);
  while (*str)
    {
      if (!is_printable_char(*str))
	{
	  my_putstr("\\0");
	  i += 2;
	  i += my_putnbr_base(*str, "01234567");
	}
      else
	{
	  my_putchar(*str);
	  i++;
	}
      str++;
    }
  return (i);
}

int		my_bin(va_list p)
{
  int		c;
  int		i;

  c = va_arg(p, int);
  i = my_putnbr_base(c, "01");
  return (i);
}

int		my_char(va_list p)
{
  char		c;

  c = (char)va_arg(p , int);
  my_putchar(c);
  return (1);
}

int		my_octal(va_list p)
{
  int		c;
  int		i;

  c =  va_arg(p, unsigned int);
  i = my_putnbr_base_unsigned(c, "01234567");
  return (i);
}
