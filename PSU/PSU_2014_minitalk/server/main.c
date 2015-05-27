/*
** main.c for server in /home/barthe_g/rendu/PSU/B2/PSU_2014_minitalk/server
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Mar 18 16:14:52 2015 barthelemy gouby
** Last update Wed Mar 25 22:53:36 2015 barthelemy gouby
*/

#define _POSIX_SOURCE
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include <sys/wait.h>

int	g_sig_nmb = -1;

void	zero(int sig)
{
  sig = sig;
  g_sig_nmb = 0;
  signal(SIGUSR2, &zero);
}

void	one(int sig)
{
  sig = sig;
  g_sig_nmb = 1;
  signal(SIGUSR1, &one);
}

int	get_char(pid_t clt_pid)
{
  int	bit_count;
  char	c;

  bit_count = 0;
  c = 0;
  while (bit_count < 8)
    {
      kill(clt_pid, SIGUSR1);
      pause();
      if (g_sig_nmb == 1)
	{
	  c = c | 1 << bit_count;
	  g_sig_nmb = -1;
	  bit_count++;
	}
      else if (g_sig_nmb == 0)
	{
	    g_sig_nmb = -1;
	    bit_count++;
	}
    }
  if (c == 4)
    return (1);
  my_putchar(c);
  return (0);
}

pid_t	get_client_pid()
{
  pid_t	clt_pid;
  char	*cast;
  int	bit_count;
  int	byte_count;

  bit_count = 0;
  byte_count = 0;
  clt_pid = 0;
  cast = (char*)(&clt_pid);
  while (byte_count < 4)
    {
      while (bit_count < 8)
	{
	  pause();
	  if (g_sig_nmb == 1)
	    {
	      cast[byte_count] = cast[byte_count] | 1 << bit_count;
	      g_sig_nmb = -1;
	    }
	  else if (g_sig_nmb == 0)
	      {
		g_sig_nmb = -1;
	      }
	  bit_count++;
	}
      bit_count = 0;
      byte_count++;
    }
  return (clt_pid);
}

int	main()
{
  pid_t	serv_pid;
  pid_t	clt_pid;

  serv_pid = getpid();
  my_printf("pid: %i\n", serv_pid);
  if (signal(SIGUSR1, &one) == SIG_ERR)
    return (-1);
  if (signal(SIGUSR2, &zero) == SIG_ERR)
    return (-1);
  while (1)
    {
      clt_pid = get_client_pid();
      while (get_char(clt_pid) == 0);
    }
  return (0);
}
