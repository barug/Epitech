/*
** my_funcs2.c for my_printf in /home/dupard_e/rendus/PSU_2013_my_printf
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Nov  5 21:41:51 2014 Erwan Dupard
** Last update Tue Nov 18 16:28:44 2014 Erwan Dupard
*/

#include <stdarg.h>
#include "./my_funcs.h"
#include "../my.h"
#include "./my_fprintf.h"

int		my_funsigned(int fd, va_list p)
{
  unsigned int	n;
  int		i;

  n = va_arg(p, unsigned int);
  i = my_fputnbr_unsigned(fd, n);
  return (i);
}

int		my_fspec(int fd, va_list p)
{
  char		*str;
  int		i;

  i = 0;
  str = va_arg(p, char *);
  while (*str)
    {
      if (!is_printable_char(*str))
	{
	  my_fputstr(fd, "\\0");
	  i += 2;
	  i += my_fputnbr_base(fd, *str, "01234567");
	}
      else
	{
	  my_fputchar(fd, *str);
	  i++;
	}
      str++;
    }
  return (i);
}

int		my_fbin(int fd, va_list p)
{
  int		c;
  int		i;

  c = va_arg(p, int);
  i = my_fputnbr_base(fd, c, "01");
  return (i);
}

int		my_fchar(int fd, va_list p)
{
  char		c;

  c = (char)va_arg(p , int);
  my_fputchar(fd, c);
  return (1);
}

int		my_foctal(int fd, va_list p)
{
  int		c;
  int		i;

  c =  va_arg(p, unsigned int);
  i = my_fputnbr_base_unsigned(fd, c, "01234567");
  return (i);
}
