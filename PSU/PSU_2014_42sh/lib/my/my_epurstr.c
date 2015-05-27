/*
** my_epurstr.c for my_epurstr in /home/dupard_e/rendus/Bistromathique/lib/my
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Oct 31 12:55:35 2014 Erwan Dupard
** Last update Sat May 23 15:02:08 2015 Erwan Dupard
*/

#include <stdlib.h>
#include "./my.h"

char		*my_epurstr(char *str)
{
  char		*ret;
  char		*save;

  if ((save = ret = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (*str)
    {
      *ret = *str;
      str++;
      ret++;
      while (*str == ' ' || *str == '\t')
	  str++;
    }
  *ret = 0;
  return (save);
}
