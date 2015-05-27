/*
** my_strcat.c for my_strcat in /home/dupard_e/rendu/Piscine_C_J07
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Oct  7 12:02:11 2014 Erwan Dupard
** Last update Wed Dec 31 12:43:59 2014 Erwan Dupard
*/

#include <stdlib.h>
#include "./my.h"

char		*my_strcat(char *dest, char *src)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (dest[i])
    i++;
  while (src[j])
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  dest[i] = 0;
  return (dest);
}
