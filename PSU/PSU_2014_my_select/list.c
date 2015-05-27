/*
** list.c for list in /home/barthe_g/rendu/PSU/PSU_2014_my_select
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Jan 11 22:45:28 2015 barthelemy gouby
** Last update Sun Jan 11 23:00:46 2015 barthelemy gouby
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

int			list_loop(t_list **entry, t_list **entrybefore,
				  int argc, char **argv)
{
  int			i;

  i = 2;
  while (i < argc)
    {
      *entry = malloc(sizeof(t_list));
      if (entry == NULL)
        return (-1);
      (*entry)->name = argv[i];
      (*entry)->position = i++;
      (*entry)->selected = 0;
      (*entry)->underligned = 0;
      (*entry)->before = *entrybefore;
      (*entrybefore)->next = *entry;
      *entrybefore = *entry;
    }
  return (0);
}

t_list			*make_list(int argc, char **argv)
{
  t_list		*entry;
  t_list		*entrybefore;
  t_list		*firstentry;

  entry = malloc(sizeof(t_list));
  if (entry == NULL)
    return (NULL);
  entry->name = argv[1];
  entry->position = 1;
  entry->selected = 0;
  entry->underligned = 1;
  entrybefore = entry;
  firstentry = entry;
  if (list_loop(&entry, &entrybefore, argc, argv) == -1)
    return (NULL);
  entry->next = firstentry;
  firstentry->before = entry;
  return(firstentry);
}

void			free_list(t_listnfo *listnfo)
{
  int			i;
  t_list		*buff;

  i = 1;
  while (i < listnfo->argc)
    {
      buff = listnfo->list->next;
      free(listnfo->list);
      listnfo->list = buff;
      i++;
    }
  free(listnfo);
}
