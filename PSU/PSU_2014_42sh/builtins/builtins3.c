/*
** builtins3.c for 42sh in /home/dupard_e/rendus/PSU_2014_42sh
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue May 12 15:40:13 2015 Erwan Dupard
** Last update Sun May 24 17:09:09 2015 karine aknin
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"

int	my_setenv(char *name, char *value)
{
  int	i;
  int	nlength;

  i = 0;
  nlength = my_strlen(name);
  while (g_env[i])
    {
      if (my_strncmp(g_env[i], name, nlength) == 0)
        {
          if (overwrite_value(name, value) == EXIT_FAILED)
            return (EXIT_FAILED);
          return (EXIT_SUCCESS);
	}
      i++;
    }
  if (make_newvariable(name, value) == EXIT_FAILED)
    return (EXIT_FAILED);
  return (EXIT_SUCCESS);
}

int	cmd_setenv(char **inptab, char **pathtab)
{
  pathtab = pathtab;
  if (inptab[1] == NULL || inptab[2] == NULL)
    {
      my_printf("[^] Usage : setenv <var> <value>\n");
      return (EXIT_SUCCESS);
    }
  if (my_setenv(inptab[1], inptab[2]) == EXIT_FAILED)
    return (EXIT_FAILED);
  my_printf("[+] Successfully setenv  %s=%s\n", inptab[1], inptab[2]);
  return (EXIT_SUCCESS);
}

int	cmd_echo(char **inptab, char **pathtab)
{
  int	i;

  (void)pathtab;
  i = 1;
  if (!inptab[i])
    return (TERMINATE_PROCESS);
  while (inptab[i])
    {
      my_printf("%s", inptab[i]);
      ++i;
      if (inptab[i] != NULL)
	my_printf(" ");
    }
  my_putchar('\n');
  return (TERMINATE_PROCESS);
}
