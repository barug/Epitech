/*
** functions2.c for functions2 in /home/barthe_g/rendu/PSU_2013_my_printf
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Nov 14 17:06:58 2014 barthelemy gouby
** Last update Sun Nov 16 18:27:05 2014 barthelemy gouby
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "functions.h"

int     put_unsigned_x(va_list ap)
{
  unsigned int  nb;
  int   lenght;

  nb = va_arg(ap, unsigned int);
  lenght = my_putnbr_base_uns(nb, "0123456789abcdef");
  return (lenght);
}

int     put_unsigned_X(va_list ap)
{
  unsigned int  nb;
  int   lenght;

  nb = va_arg(ap, unsigned int);
  lenght = my_putnbr_base_uns(nb, "0123456789ABCDEF");
  return (lenght);
}

int     put_unsigned_b(va_list ap)
{
  unsigned int  nb;
  int           lenght;
  nb = va_arg(ap, unsigned int);
  lenght = my_putnbr_base_uns(nb, "01");
  return (lenght);
}

int     put_int_c(va_list ap)
{
  unsigned char nb;

  nb = va_arg(ap, int);
  my_putchar(nb);
  return (1);
}

int	put_void(va_list ap)
{
  void	*pointer;
  int	length;

  pointer = va_arg(ap, void*);
  length= my_putnbr_base_uns((unsigned int) pointer, "0123456789ABCDEF");
  return (length);
}
