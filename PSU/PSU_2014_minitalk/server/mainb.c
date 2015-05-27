/*
** mainb.c for serverbonus in /home/barthe_g/rendu/PSU/B2/PSU_2014_minitalk
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Mar 19 17:59:05 2015 barthelemy gouby
** Last update Sun Mar 22 23:09:56 2015 barthelemy gouby
*/

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "minitalk.h"

int			get_bit(int sig)
{
  static char		c = 0;
  static int		bit_count = 0;

  if (sig == SIGUSR1)
    {
      c = c | 1 << bit_count;
      bit_count++;
    }
  else if (sig == SIGUSR2)
    bit_count++;
  if (bit_count == 8)
    {
      bit_count = 0;
      if (c == 4)
	{
	  c = 0;
	  return (1);
	}
      my_putchar(c);
      c = 0;
    }
  return (0);
}

void			free_node(t_client **client_list)
{
  t_client		*tmp;

  tmp = (*client_list)->next;
  free(*client_list);
  *client_list = tmp;
}

void			if_not_current(pid_t *current_client,
				       t_client **client_list,
				       siginfo_t *siginfo)
{
  if (*current_client == -1)
    {
      *current_client = siginfo->si_pid;
      kill(siginfo->si_pid, SIGUSR1);
    }
  else
    {
      usleep(100);
      if (push_in_list(client_list, siginfo->si_pid) == -1)
	exit (-1);
    }
}

void			sig_action(int sig, siginfo_t *siginfo,
				   void *context)
{
  static pid_t		current_client = -1;
  static t_client	*client_list = NULL;

  context = context;
  if (siginfo->si_pid == current_client)
    {
      if (get_bit(sig) == 1)
	{
	  if (client_list != NULL)
	    {
	      current_client = client_list->client_pid;
	      free_node(&client_list);
	      kill(current_client, SIGUSR1);
	    }
	  else
	    current_client = -1;
	}
      else
	kill(current_client, SIGUSR1);
    }
  else
    {
      usleep(200);
      if_not_current(&current_client, &client_list, siginfo);
    }
}

int			main()
{
  pid_t			serv_pid;
  int			end;
  struct sigaction	sigact;

  end = 1;
  serv_pid = getpid();
  my_printf("pid: %i\n", serv_pid);
  sigact.sa_flags = SA_SIGINFO;
  sigact.sa_sigaction = sig_action;
  if (sigaction(SIGUSR1, &sigact, NULL) == -1)
    return (-1);
  if (sigaction(SIGUSR2, &sigact, NULL) == -1)
    return (-1);
  while (end)
    pause();
  return (0);
}
