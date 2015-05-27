/*
** builtins.c for 42sh in /home/dupard_e/rendus/PSU_2014_42sh
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue May 12 15:40:30 2015 Erwan Dupard
** Last update Sun May 24 17:28:06 2015 Barthelemy Gouby
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"

void	copy_env_and_delete(char **inptab, char **buff, int nlength, int n)
{
  int	i;

  i = 0;
  while (buff[i])
    {
      if (my_strncmp(buff[i], inptab[1], nlength) == 0)
        {
          free(buff[i]);
          i++;
        }
      g_env[n] = buff[i];
      i++;
      n++;
    }
}

int	cmd_unsetenv(char **inptab, char **pathtab)
{
  int	i;

  (void)pathtab;
  i = 0;
  if (!inptab[1])
    {
      my_fprintf(2, "[^] Usage : unsetenv <envar>\n");
      return (EXIT_SUCCESS);
    }
  while (g_env[i] && my_strncmp(g_env[i], inptab[1],
				my_strlen(inptab[1])) != 0)
    i++;
  if (g_env[i] == NULL)
    {
      my_fprintf(2, "[-] Unknow environement variable '%s'\n", inptab[1]);
      return (EXIT_SUCCESS);
    }
  while (g_env[i])
    {
      g_env[i] = g_env[i + 1];
      i++;
    }
  my_printf("[+] Successfully deleted env '%s'\n", inptab[1]);
  return (EXIT_SUCCESS);
}

int	execute_builtin(builtin f, t_command command, char **pathtab)
{
  int	pid;
  int	status;

  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      signal(SIGINT, SIG_DFL);
      signal(SIGTSTP, SIG_DFL);
      do_redirections(&command);
      return (f(command.args, pathtab));
    }
  else
    {
      waitpid(pid, &status, 0);
      if (WEXITSTATUS(status) != EXIT_FAILED)
	{
	  if (WEXITSTATUS(status) >= EXIT_EXIT)
	    return (WEXITSTATUS(status));
	  if (command.pipein != 0 && command.pipeout == 1)
	    return (TERMINATE_PROCESS);
	  return (EXIT_SUCCESS);
	}
    }
  return (EXIT_FAILED);
}

int			search_builtins2(t_command command, char **pathtab)
{
  int			i;
  static t_builtin	builtins[] = {{"setenv", &cmd_setenv},
				      {"unsetenv", &cmd_unsetenv},
				      {"cd", &cmd_cd},
				      {"exit", &cmd_exit},
				      {NULL, NULL}
  };

  i = 0;
  while (builtins[i].name)
    {
      if (my_strcmp(command.args[0], builtins[i].name) == 0)
	return (builtins[i].f(command.args, pathtab));
      i++;
    }
  return (BUILTIN_FAILED);
}

int			search_builtins(t_command command, char **pathtab)
{
  int			i;
  static t_builtin	builtins[] = {{"env", &cmd_env},
				      {"echo", &cmd_echo},
				      {NULL, NULL}
  };

  i = 0;
  while (builtins[i].name)
    {
      if (my_strcmp(command.args[0], builtins[i].name) == 0)
	return (execute_builtin(builtins[i].f, command, pathtab));
      i++;
    }
  return (search_builtins2(command, pathtab));
}
