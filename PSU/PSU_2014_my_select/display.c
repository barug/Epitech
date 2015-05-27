/*
** display.c for display in /home/barthe_g
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Jan 11 20:26:16 2015 barthelemy gouby
** Last update Fri Jan 16 16:43:21 2015 barthelemy gouby
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include <term.h>
#include "my.h"
#include "my_select_include.h"

void                    new_putchar(char c, int termfd)
{
  write(termfd, &c, 1);
}

void                    new_putstr(char *str, int termfd)
{
  int                   i;

  i = 0;
  while (str[i])
    new_putchar(str[i++], termfd);
}

int                     display_list(t_list *list, int argc, int termfd)
{
  int                   i;
  char                  *termcap;

  i = 1;
  termcap = tgetstr("cd", NULL);
  new_putstr(termcap, termfd);
  while (i < argc)
    {
      if (list->underligned == 1)
        {
          termcap = tgetstr("us", NULL);
          new_putstr(termcap, termfd);
        }
      if (list->selected == 1)
        {
          termcap = tgetstr("mr", NULL);
          new_putstr(termcap, termfd);
        }
      new_putstr(list->name, termfd);
      new_putchar('\n', termfd);
      termcap = tgetstr("me", NULL);
      new_putstr(termcap, termfd);
      list = list->next;
      i++;
    }
  termcap = tgetstr("UP", NULL);
  termcap = tparm(termcap, argc - 1);
  new_putstr(termcap, termfd);
  return (0);
}

int                     display_selected(t_list *list, int argc)
{
  int                   i;

  i = 1;
  while (i < argc)
    {
      if (list->selected == 1)
        my_printf("%s ", list->name);
      list = list->next;
      i++;
    }
  my_putchar('\n');
  return (0);
}
