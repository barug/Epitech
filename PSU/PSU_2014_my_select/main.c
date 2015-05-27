/*
** main.c for main in /home/barthe_g/rendu/PSU/PSU_2014_my_select
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jan  6 16:33:08 2015 barthelemy gouby
** Last update Thu Jan 29 16:02:51 2015 barthelemy gouby
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include <term.h>
#include "my.h"
#include "my_select_include.h"

void                    delete(char *input, t_listnfo *listnfo)
{
  t_list                *buff;

  if (input[0] == 127)
    {
      listnfo->list->before->next = listnfo->list->next;
      listnfo->list->next->before = listnfo->list->before;
      if (listnfo->list == listnfo->liststart)
	listnfo->liststart = listnfo->list->next;
      buff = listnfo->list->next;
      free(listnfo->list);
      listnfo->list = buff;
      listnfo->list->underligned = 1;
      listnfo->argc = listnfo->argc - 1;
    }
}

void			navigate_list(t_listnfo *listnfo, char *input)
{
  if (input[2] == 'A')
    {
      listnfo->list->underligned = 0;
      listnfo->list = listnfo->list->before;
      listnfo->list->underligned = 1;
    }
  if (input[2] == 'B')
    {
      listnfo->list->underligned = 0;
      listnfo->list = listnfo->list->next;
      listnfo->list->underligned = 1;
    }
  if (input[0] == 32)
    {
      if (listnfo->list->selected == 0)
        listnfo->list->selected = 1;
      else
        listnfo->list->selected = 0;
    }
}

int			read_input(char *input,
				   t_listnfo *listnfo, int *escp)
{
  navigate_list(listnfo, input);
  if (input[0] == '\n')
    return (1);
  if (input[0] == 4 && input[1] == '\0')
      return (2);
  if (input[0] == 27 && input[1] == '\0')
    *escp = 1;
  delete(input, listnfo);
  return (0);
}

void			select_loop(t_listnfo *listnfo, int *escp,
				    int *end, int termfd)
{
  int			i;
  char                  input[4];

  while (*end == 0)
    {
      display_list(listnfo->liststart, listnfo->argc, termfd);
      i = read(0, input, 3);
      while (i <= 4)
        input[i++] = '\0';
      *end = read_input(input, listnfo, escp);
    }
}

int			main(int argc, char **argv, char **envp)
{
  t_listnfo		*listnfo;
  int			end;
  int			termfd;
  int			escp;
  char			*termcap;

  escp = 0;
  end = 0;
  if (argc == 1)
    return (0);
  listnfo = malloc(sizeof(t_listnfo));
  if (listnfo == NULL)
    return (-1);
  if ((termfd = initialize(listnfo, argc, argv, envp)) == -1)
    return (-1);
  select_loop(listnfo, &escp, &end, termfd);
  termcap = tgetstr("cd", NULL);
  new_putstr(termcap, termfd);
  if (end != 2 && escp != 1)
    display_selected(listnfo->liststart, listnfo->argc);
  free_list(listnfo);
  restore_tattr();
  return (0);
}
