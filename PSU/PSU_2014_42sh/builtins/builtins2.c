/*
** builtins2.c for 42sh in /home/dupard_e/rendus/PSU_2014_42sh
** 
** Made by Erwan Dupard
** Login  <dupard_e@epitech.net>
** 
** Started on  Tue May 12 15:39:59 2015 Erwan Dupard
** Last update Sun May 24 16:33:31 2015 Barthelemy Gouby
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"

int	overwrite_value(char *name, char *value)
{
  int	i;
  char	*new;

  i = 0;
  while (g_env[i] && my_strncmp(g_env[i], name, my_strlen(name)) != 0)
    i++;
  if (!g_env[i])
    return (EXIT_FAILED);
  if ((new = malloc(sizeof(*new) *
		    (my_strlen(name) + my_strlen(value) + 2))) == NULL)
    return (EXIT_FAILED);
  new = my_strcpy(new, name);
  new = my_strcat(new, "=");
  new = ((!value || !*value) ? new : my_strcat(new, value));
  free(g_env[i]);
  g_env[i] = new;
  return (TERMINATE_PROCESS);
}

int		my_realloc_env()
{
  int		i;
  char		**new;

  i = 0;
  while (g_env[i])
    ++i;
  if ((new = malloc(sizeof(*new) * (i + 2))) == NULL)
    return (EXIT_FAILED);
  i = 0;
  while (g_env[i])
    {
      new[i] = my_strdup(g_env[i]);
      free(g_env[i]);
      i++;
    }
  new[i] = NULL;
  free(g_env);
  g_env = new;
  return (EXIT_SUCCESS);
}

int	cmd_exit(char **inptab, char **pathtab)
{
  int	sig;

  (void)pathtab;
  if (!inptab[1])
    return (EXIT_EXIT);
  sig = my_atoi(inptab[1]);
  if (sig > EXIT_EXIT)
    return (sig + EXIT_EXIT);
  return (EXIT_EXIT);
}

int	cmd_env(char **inptab, char **pathtab)
{
  int	i;

  i = 0;
  (void)inptab;
  (void)pathtab;
  while (g_env[i])
    {
      my_printf("\033[32m\033[1m%d| \033[0m%s\n", i, g_env[i]);
      i++;
    }
  return (TERMINATE_PROCESS);
}
