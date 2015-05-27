/*
** listb.c for Allum1b in /home/barthe_g/rendu/CPE/B2/Allum1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Feb 19 10:30:01 2015 barthelemy gouby
** Last update Fri Feb 20 17:04:17 2015 barthelemy gouby
*/

#include <ncurses/curses.h>
#include <stdlib.h>
#include "my.h"
#include "Allum1b.h"

int		make_row(t_rowslist **row, t_rowslist **buff, int m_nb)
{
  if ((*row = malloc(sizeof(t_rowslist))) == NULL)
    return (-1);
  (*row)->matchs_nb = m_nb;
  (*row)->cursor = 0;
  (*row)->before = *buff;
  (*buff)->next = *row;
  *buff = *row;
  return (0);
}

t_rowslist	*make_rowslist(int list_size)
{
  int		m_nb;
  t_rowslist	*row;
  t_rowslist	*buff;
  t_rowslist	*first;

  m_nb = 3;
  if ((buff = malloc(sizeof(t_rowslist))) == NULL)
    return (NULL);
  buff->matchs_nb = 1;
  list_size--;
  first = buff;
  while (list_size)
    {
      if (make_row(&row, &buff, m_nb) == -1)
	return (NULL);
      list_size--;
      m_nb += 2;
    }
  row->next = first;
  first->before = row;
  first->cursor = 1;
  return (first);
}

void		free_list(t_rowslist *rowslist, int list_size)
{
  int		i;
  t_rowslist	*buff;

  i = 0;
  while (i < list_size)
    {
      buff = rowslist->next;
      free(rowslist);
      rowslist = buff;
      i++;
    }
}
