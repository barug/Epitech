/*
** my_strdup.c for my_strdup in /home/barthe_g/rendu/Piscine_C_J08/ex_01
** 
** Made by gouby barthelemy
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Oct  8 18:25:06 2014 gouby barthelemy
** Last update Fri Nov 14 16:40:43 2014 barthelemy gouby
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	i;
  char	*dup;

  i = 0;
  while (src[i] != 0)
    {
      i = i + 1;
    }
  dup = malloc(i * sizeof(char));
  if (dup == NULL)
    return (NULL);
  if (dup == 0)
    return (0);
  i = 0;
  while (src[i] != 0)
    {
      dup[i] = src[i];
      i++;
    }
  dup[i] = 0;
  return (dup);
}
