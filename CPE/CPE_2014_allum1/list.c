/*
** list.c for Allum1 in /home/barthe_g/rendu/CPE/B2/Allum1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Feb 18 11:44:08 2015 barthelemy gouby
** Last update Fri Feb 20 16:52:28 2015 barthelemy gouby
*/

#include <stdlib.h>
#include "my.h"
#include "Allum1.h"

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
      if ((row = malloc(sizeof(t_rowslist))) == NULL)
	return (NULL);
      row->matchs_nb = m_nb;
      row->before = buff;
      buff->next = row;
      buff = row;
      list_size--;
      m_nb += 2;
    }
  row->next = first;
  first->before = row;
  return (first);
}

void		display_row(t_rowslist *row, int list_size)
{
  int		i;

  i = 0;
  while (i <= list_size - 1)
    {
      my_putchar(' ');
      i++;
    }
  i = 0;
  while (i < row->matchs_nb)
    {
      my_putchar('|');
      i++;
    }
}

void		display_list(t_rowslist *rowslist, int list_size)
{
  int		i;
  t_rowslist	*tmp;
  int		shift;

  i = 0;
  tmp = rowslist;
  shift = list_size;
  while (i < list_size)
    {
      my_putchar(i + 1 + '0');
      display_row(tmp, shift);
      my_putchar('\n');
      tmp = tmp->next;
      shift--;
      i++;
    }
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
