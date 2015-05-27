/*
** main.c for client in /home/barthe_g/rendu/PSU/B2/PSU_2014_minitalk/client
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Mar 18 16:16:22 2015 barthelemy gouby
** Last update Wed Mar 25 23:12:59 2015 barthelemy gouby
*/

#define _POSIX_SOURCE
#define _BSD_SOURCE
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include <sys/wait.h>

void	permission(int sig)
{
  sig = sig;
  signal(SIGUSR1, permission);
}

int	send_char(pid_t pid, char c)
{
  int	bit_count;

  bit_count = 0;
  while (bit_count < 8)
    {
      sleep(1);
      if ((c & 1) == 1)
	{
	  if (kill(pid, SIGUSR1) == -1)
	    return (-1);
	  /* pause(); */
	}
      else
	{
	  if (kill(pid, SIGUSR2) == -1)
	    return (-1);
	  /* pause(); */
	}
      c = c >> 1;
      bit_count++;
    }
  return (0);
}

int	send_pid(pid_t clt_pid, pid_t serv_pid)
{
  char	*cast;
  int	bit_count;
  int	byte_count;

  bit_count = 0;
  byte_count = 0;
  cast = (char*)(&clt_pid);
  while (byte_count < 4)
    {
      while (bit_count < 8)
	{
	  if (usleep(1000) == -1)
	    return (-1);
	  if ((cast[byte_count] & 1) == 1)
	    {
	      if (kill(serv_pid, SIGUSR1) == -1)
		return (-1);
	    }
	  else
	    if (kill(serv_pid, SIGUSR2) == -1)
	      return (-1);
	  cast[byte_count] = cast[byte_count] >> 1;
	  bit_count++;
	}
      bit_count = 0;
      byte_count++;
    }
  return (0);
}

int     main(int argc, char **argv)
{
  pid_t	serv_pid;
  int	i;

  i = 0;
  argc = argc;
  if (argc != 3)
    return (0);
  signal(SIGUSR1, permission);
  serv_pid = my_getnbr(argv[1]);
  my_printf(" serv_pid: %i ", serv_pid);
  my_printf(" client pid %i ", getpid());
  usleep(300);
  send_pid(getpid(), serv_pid);
  while (argv[2][i])
    {
      if (send_char(serv_pid, argv[2][i]) == -1)
	return (-1);
      i++;
    }
  send_char(serv_pid, 4);
  return (0);
}
