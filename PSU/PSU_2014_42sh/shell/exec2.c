/*
** exec2.c for 42sh in /home/dupard_e/rendus/PSU_2014_42sh
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Sun May 24 11:19:39 2015 Erwan Dupard
** Last update Tue May 26 20:02:16 2015 Barthelemy Gouby
*/

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

int		search_exec(t_command *command,  char **pathtab)
{
  int		i;
  char		*path;
  char		*tmp;

  i = 0;
  if ((my_strncmp("./", (*command).args[0], 2) == 0 ||
       my_strncmp("/", (*command).args[0], 1) == 0))
    if (verify_exec((*command).args[0]) == EXIT_SUCCESS)
      {
	tmp = my_strdup((*command).args[0]);
	return (fork_and_wait(command, tmp));
      }
  while (pathtab[i])
    {
      if ((path = make_path(pathtab[i], (*command).args[0])) == NULL)
        return (EXIT_FAILED);
      if (verify_exec(path) == EXIT_SUCCESS)
	return (fork_and_wait(command, path));
      i++;
    }
  my_printf("[^] Error: unknown command: '%s'\n", (*command).args[0]);
  if ((*command).pipein != 0)
    return (TERMINATE_PROCESS);
  return (CMD_FAILED);
}
