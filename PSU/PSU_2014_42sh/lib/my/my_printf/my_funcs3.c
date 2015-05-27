/*
** my_funcs3.c for my_printf in /home/dupard_e/rendus/PSU_2014_my_printf/lib/my/my_printf
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Sun Nov 16 12:54:03 2014 Erwan Dupard
** Last update Sun Nov 16 13:07:21 2014 Erwan Dupard
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../my.h"

int             my_eenn(va_list p, int j, int *ok)
{
  int		*lol;

  *ok = 1;
  lol = NULL;
  lol = lol;
  lol = va_arg(p, int *);
  lol = &j;
  return (0);
}
