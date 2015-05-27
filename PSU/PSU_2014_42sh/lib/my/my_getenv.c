/*
** my_getenv.c for libmy in /home/dupard_e/rendus/PSU_2014_42sh/lib/my
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed May 13 14:52:49 2015 Erwan Dupard
** Last update Thu May 21 18:52:38 2015 Erwan Dupard
*/

#include <stdlib.h>
#include "./my.h"

char		*my_getenv(char **env, char *s)
{
  int		i;

  i = 0;
  if (!env)
    return (NULL);
  while (env[i])
    {
      if (my_strncmp(env[i], s, my_strlen(s)) == 0)
	return (my_strdup(env[i] + my_strlen(s) + 1));
      i++;
    }
  return (NULL);
}
