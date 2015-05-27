/*
** redirections.c for 42sh in /home/barthe_g/rendu/PSU/PSU_2014_42sh/barth
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu May 21 14:36:54 2015 Barthelemy Gouby
** Last update Sun May 24 17:35:27 2015 Barthelemy Gouby
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "minishell.h"
#include "my.h"

int	redirect_output(t_command *command)
{
  int	fd;

  if ((*command).output != NULL)
    {
      if ((fd = open((*command).output, O_RDWR | O_CREAT,
		     S_IRUSR | S_IWUSR | S_IRGRP)) == EXIT_FAILED)
	return (EXIT_FAILED);
      if ((*command).pipeout == 1)
	dup2(fd, 1);
    }
  if ((*command).append != NULL)
    {
      if ((fd = open((*command).append, O_RDWR | O_APPEND | O_CREAT,
		     S_IRUSR | S_IWUSR | S_IRGRP)) == EXIT_FAILED)
	return (EXIT_FAILED);
      if ((*command).pipeout == 1)
	dup2(fd, 1);
    }
  return (EXIT_SUCCESS);
}

int		endread(char *end)
{
  int		pipefd[2];
  char		*input;

  if (pipe(pipefd) == EXIT_FAILED)
    return (EXIT_FAILED);
  my_printf("> ");
  while (my_strcmp(input = get_next_line(0), end) != 0)
    {
      my_printf("> ");
      my_fprintf(pipefd[1], "%s\n", input);
    }
  close(pipefd[1]);
  if (dup2(pipefd[0], 0) == EXIT_FAILED)
    return (EXIT_FAILED);
  return (EXIT_SUCCESS);
}

int		redirect_input(t_command *command)
{
  int		fd;

  if ((*command).input != NULL)
    {
      if ((fd = open((*command).input, O_RDWR | O_CREAT,
		     S_IRUSR | S_IWUSR | S_IRGRP)) == EXIT_FAILED)
	return (EXIT_FAILED);
      if ((*command).pipein == 0)
	dup2(fd, 0);
    }
  if ((*command).endread != NULL)
    return (endread((*command).endread));
  return (EXIT_SUCCESS);
}

int		do_redirections(t_command *command)
{
  if ((*command).pipeout != 1)
    if (dup2((*command).pipeout, 1) == EXIT_FAILED)
      return (EXIT_FAILED);
  if ((*command).pipein != 0)
    if (dup2((*command).pipein, 0) == EXIT_FAILED)
      return (EXIT_FAILED);
  if (redirect_output(command) == EXIT_FAILED)
    return (EXIT_FAILED);
  if (redirect_input(command) == EXIT_FAILED)
    return (EXIT_FAILED);
  return (EXIT_SUCCESS);
}
