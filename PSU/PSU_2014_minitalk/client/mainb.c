/*
** mainb.c for clientbonus in /home/barthe_g/rendu/PSU/B2/PSU_2014_minitalk
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Mar 19 17:57:43 2015 barthelemy gouby
** Last update Wed Mar 25 14:24:37 2015 barthelemy gouby
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"

int	g_permission = -1;

void	sig_hand(int sig)
{
  sig = sig;
  g_permission = 1;
}

void	send_char(pid_t pid, char c)
{
  int	bit_count;

  bit_count = 0;
  while (bit_count < 8)
    {
      usleep(1000);
      if ((c & 1) == 1)
        kill(pid, SIGUSR1);
      else
        kill(pid, SIGUSR2);
      c = c >> 1;
      bit_count++;
    }
}

int	main(int argc, char **argv)
{
  pid_t	pid;
  int	i;

  i = 0;
  if (argc != 3)
    return (0);
  pid = my_getnbr(argv[1]);
  if (signal(SIGUSR1, sig_hand) == SIG_ERR)
    return (-1);
  kill(pid, SIGUSR1);
  while (g_permission == -1)
    pause();
  while (argv[2][i])
    {
      send_char(pid, argv[2][i]);
      i++;
    }
  send_char(pid, 4);
  return (0);
}
