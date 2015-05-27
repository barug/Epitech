/*
** env.c for minishell2 in /home/barthe_g/rendu/PSU/B2/PSU_2014_minishell2
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Mar 15 23:37:49 2015 barthelemy gouby
** Last update Sun May 24 17:16:48 2015 karine aknin
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

int		make_newvariable(char *name, char *value)
{
  int		i;
  char		*new;

  i = 0;
  if ((new = malloc(sizeof(*new) * (my_strlen(name)
				    + my_strlen(value) + 2))) == NULL)
    return (EXIT_FAILED);
  new = my_strcpy(new, name);
  new = my_strcat(new, "=");
  new = my_strcat(new, value);
  if (my_realloc_env() == EXIT_FAILED)
    return (EXIT_FAILED);
  while (g_env[i])
    i++;
  g_env[i] = new;
  g_env[i + 1] = NULL;
  return (EXIT_SUCCESS);
}

void	copy_variable(char *name, char *value, int i)
{
  int	c;
  int	n;

  c = 0;
  n = 0;
  while (name[c])
    {
      g_env[i][c] = name[c];
      c++;
    }
  g_env[i][c++] = '=';
  while (value[n])
    {
      g_env[i][c + n] = value[n];
      n++;
    }
  g_env[i][c + n] = '\0';
}
