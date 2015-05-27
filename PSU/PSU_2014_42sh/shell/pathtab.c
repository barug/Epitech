/*
** pathtab.c for minishell in /home/barthe_g/rendu/PSU/PSU_2014_minishell
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jan 29 12:42:45 2015 barthelemy gouby
** Last update Sun May 24 17:22:36 2015 karine aknin
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

char	**get_pathtab()
{
  char	**pathtab;
  char	*pathstr;
  char	**path;

  if ((pathstr = my_getenv(g_env, "PATH")) == NULL)
    {
      if ((path = malloc(sizeof(*path) * (1))) == NULL)
	return (NULL);
      path[0] = NULL;
      return (path);
    }
  if ((pathtab = my_str_to_word_tab(pathstr)) == NULL)
    return (NULL);
  return (pathtab);
}
