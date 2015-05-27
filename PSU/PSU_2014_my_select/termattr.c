/*
** termattr.c for termattr in /home/barthe_g/rendu/PSU/PSU_2014_my_select
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Jan  7 18:59:32 2015 barthelemy gouby
** Last update Sun Jan 11 22:15:06 2015 barthelemy gouby
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include <term.h>
#include "my.h"
#include "my_select_include.h"

int			initialize(t_listnfo *listnfo, int argc, char **argv, char **envp)
{
  int			termfd;

  if (set_tattr() == -1)
    return (-1);
  if (load_termcaps(envp) == -1)
    return (-1);
  listnfo->list = make_list(argc, argv);
  if (listnfo->list == NULL)
    {
      my_printf("failure to make list");
      return (-1);
    }
  if ((termfd = open("/dev/tty", O_WRONLY)) == -1)
    {
      my_printf("failure to open terminal");
      return (-1);
    }
  listnfo->liststart = listnfo->list;
  listnfo->argc = argc;
  return (termfd);
}

int                     set_tattr()
{
  struct termios        termios;

  if (tcgetattr(0, &termios) == -1)
    {
      my_printf("failure to get tattr\n");
      return(-1);
    }
  termios.c_lflag &= ~ECHO;
  termios.c_lflag &= ~ICANON;
  termios.c_cc[VMIN] = 1;
  signal(SIGINT, SIG_IGN);
  if (tcsetattr(0, TCSANOW, &termios) == -1)
    {
      my_printf("failure to set tattr\n");
      return (-1);
    }
  return (0);
}

int                     restore_tattr()
{
  struct termios        termios;

  if (tcgetattr(0, &termios) == -1)
    {
      my_printf("failure to get tattr\n");
      return(-1);
    }
  termios.c_lflag |= ECHO;
  termios.c_lflag |= ICANON;
  termios.c_cc[VMIN] = 0;
  if (tcsetattr(0, TCSANOW, &termios) == -1)
    {
      my_printf("failure to set tattr\n");
      return (-1);
    }
  return (0);
}

int                     load_termcaps(char **envp)
{
  int                   i;
  char                  *termid;

  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp(envp[i], "TERM=", 5) == 0)
        termid = &(envp[i][5]);
      i++;
    }
  if (tgetent(NULL, termid) != 1)
    {
      my_printf("failure while loading termcaps\n");
      return (-1);
    }
  return (0);
}
