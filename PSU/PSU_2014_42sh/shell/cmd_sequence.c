/*
** cmd_sequence.c for minishell2 in /home/barthe_g/rendu/PSU/B2/PSU_2014_minishell2
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Mar 29 20:00:10 2015 barthelemy gouby
** Last update Sun May 24 16:57:04 2015 Barthelemy Gouby
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

int	parent_process_pipe(t_command *command, char **pathtab,
			    int *pipefd, int pid)
{
  int	status;

  close(pipefd[0]);
  (*command).pipeout = pipefd[1];
  if (execute_prog(command, pathtab) == EXIT_FAILED)
    return (EXIT_FAILED);
  close(pipefd[1]);
  waitpid(pid, &status, 0);
  if ((*command).pipein != 0)
    {
      if (WEXITSTATUS(status) == EXIT_FAILED)
	return (EXIT_FAILED);
      return (TERMINATE_PROCESS);
    }
  if (WEXITSTATUS(status) == EXIT_FAILED)
    return (CMD_FAILED);
  return (EXIT_SUCCESS);
}

int	fork_and_pipe(t_command *cmd_sequence, char **pathtab, int *i)
{
  int	pipefd[2];
  int	pid;

  if (pipe(pipefd) == -1)
    return (EXIT_FAILED);
  if ((pid = fork()) == -1)
    return (EXIT_FAILED);
  if (pid == 0)
    {
      (*i)++;
      cmd_sequence[*i].pipein = pipefd[0];
      close(pipefd[1]);
      return (execute_cmd_sequence(cmd_sequence, pathtab, i));
    }
  else
    return (parent_process_pipe(&cmd_sequence[*i], pathtab, pipefd, pid));
  return (EXIT_SUCCESS);
}

int	execute_cmd_sequence(t_command *cmd_sequence, char **pathtab, int *i)
{
  if (cmd_sequence[*i + 1].args != NULL)
    return (fork_and_pipe(cmd_sequence, pathtab, i));
  return (execute_prog(&cmd_sequence[*i], pathtab));
}

int		execute_cmd_tab(t_parser *pars, char **pathtab)
{
  int		cmd_seq;
  int		i;
  int		return_value;

  cmd_seq = 0;
  while (pars->cmd_tab[cmd_seq])
    {
      i = 0;
      if (pars->cmd_tab[cmd_seq][0].args == NULL)
	return (EXIT_SUCCESS);
      return_value = execute_cmd_sequence(pars->cmd_tab[cmd_seq], pathtab, &i);
      if ((return_value == CMD_FAILED && pars->sep[cmd_seq] == '&') ||
	   (return_value == EXIT_SUCCESS && pars->sep[cmd_seq] == '|'))
	{
	  if (pars->cmd_tab[cmd_seq + 2] == NULL ||
	      (pars->sep[cmd_seq + 1] != '|' && pars->sep[cmd_seq + 1] != ';'))
	    return (EXIT_SUCCESS);
	  cmd_seq++;
	}
      if (return_value == EXIT_FAILED || return_value == TERMINATE_PROCESS
	  || return_value >= EXIT_EXIT)
	return (return_value);
      cmd_seq++;
    }
  return (EXIT_SUCCESS);
}
