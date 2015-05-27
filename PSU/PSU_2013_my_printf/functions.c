/*
** functions.c for functions in /home/barthe_g/rendu/printf
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Nov 11 16:47:33 2014 barthelemy gouby
** Last update Sun Nov 16 18:17:33 2014 barthelemy gouby
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "functions.h"

int	put_int(va_list ap)
{
  int	nb;
  int	lenght;

  nb = va_arg(ap, int);
 lenght =  my_put_nbr(nb);
 return (lenght);
}

int	put_str(va_list ap)
{
  char	*str;
  int	lenght;

  str = va_arg(ap, char*);
  if (str == NULL)
    lenght = my_putstr("(null)");
  else
    lenght = my_putstr(str);
  return (lenght);
}

int     put_str_S(va_list ap)
{
  char  *str;
  int	i;

  i = 0;
  str = va_arg(ap, char*);
  if (str == NULL)
    i = my_putstr("(null)");
  else
    {
      while (str[i] != 0)
	{
	  if (str[i] > 32 && str[i] < 127)
	    my_putchar(str[i]);
	  else
	    {
	      my_putchar('\\');
	      my_putnbr_base((int) str[i], "01234567");
	    }
	  i++;
	}
    }
  return (i);
}

int	put_unsigned_o(va_list ap)
{
  unsigned int	nb;
  int	lenght;

  nb = va_arg(ap, unsigned int);
  lenght = my_putnbr_base_uns(nb, "01234567");
  return (lenght);
}

int	put_unsigned_u(va_list ap)
{
  unsigned int  nb;
  int	lenght;

  nb = va_arg(ap, unsigned int);
  lenght = my_putnbr_base_uns(nb, "0123456789");
  return (lenght);
}
