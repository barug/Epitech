/*
** exec.c for minishell in /home/barthe_g/rendu/PSU/PSU_2014_minishell
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jan 29 13:01:59 2015 barthelemy gouby
** Last update Sun May 24 18:51:15 2015 Barthelemy Gouby
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

int		execute_prog(t_command *command, char **pathtab)
{
  int		blt_res;

  if ((blt_res = search_builtins(*command, pathtab)) != 2)
    return (blt_res);
  else if (blt_res == 2)
    return (search_exec(command, pathtab));
  return (EXIT_SUCCESS);
}

char		*make_path(char *directory, char *filename)
{
  int		dirnsize;
  int		fnsize;
  char		*path;
  int		i;
  int		n;

  i = 0;
  n = 0;
  dirnsize = my_strlen(directory);
  fnsize = my_strlen(filename);
  if ((path = malloc ((dirnsize + fnsize + 2) * sizeof(char))) == NULL)
    return (NULL);
  while (directory[i])
    path[n++] = directory[i++];
  i = 0;
  path[n++] = '/';
  while (filename[i])
    path[n++] = filename[i++];
  path[n] = '\0';
  return (path);
}

int		parent_process_action(t_command *command, int pid)
{
  int		sig;
  int		status;

  waitpid(pid, &status, 0);
  if (WIFEXITED(status) == 1 && WEXITSTATUS(status) == EXIT_SUCCESS)
    {
      if ((*command).pipein != 0 && (*command).pipeout == 1)
	return (TERMINATE_PROCESS);
      return (EXIT_SUCCESS);
    }
  if (WIFSIGNALED(status) == 1)
    {
      sig = WTERMSIG(status);
      if (sig == SIGFPE)
	my_fprintf(2, "[-] Floating point exception\n");
      if (sig == SIGSEGV)
	my_fprintf(2, "[-] Segmentation fault\n");
      if (sig == SIGPIPE)
	my_fprintf(2, "[-] Broken pipe\n");
      if (sig == SIGILL)
	my_fprintf(2, "[-] Illegal Instruction\n");
    }
  if ((*command).pipein == 0)
    return (CMD_FAILED);
  return (EXIT_FAILED);
}

int		fork_and_wait(t_command *command, char *path)
{
  pid_t		pid;

  if ((pid = fork()) == EXIT_FAILED)
    return (EXIT_FAILED);
  if (pid == 0)
    {
      if (do_redirections(command) == EXIT_FAILED)
	return (EXIT_FAILED);
      signal(SIGINT, SIG_DFL);
      signal(SIGTSTP, SIG_DFL);
      setpgid(0,0);
      execve(path, (*command).args, g_env);
      return (EXIT_FAILED);
    }
  else
    {
      g_spid = pid;
      free(path);
      return (parent_process_action(command, pid));
    }
}

int		verify_exec(char *path)
{
  struct stat	s;

  if (stat(path, &s) == EXIT_FAILED)
    return (EXIT_FAILED);
  if (S_ISDIR(s.st_mode) == 1)
    return (EXIT_FAILED);
  if (access(path, X_OK) != EXIT_FAILED)
    return (EXIT_SUCCESS);
  return (EXIT_FAILED);
}
