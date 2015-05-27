/*
** ai.c for Allum1.c in /home/barthe_g/rendu/CPE/B2/Allum1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Feb 11 15:35:37 2015 barthelemy gouby
** Last update Tue Feb 17 15:41:03 2015 barthelemy gouby
*/

#include "my.h"
#include "Allum1.h"


int		substract_bigrow(t_rowslist *rowslist, int list_size, int small_rows)
{
  int		i;

  i = 0;
  while (i < list_size)
    {
      if (rowslist->matchs_nb > 1)
	{
	  if (small_rows % 2 == 0)
	    while (rowslist->matchs_nb != 1)
	      rowslist->matchs_nb--;
	  else
	    rowslist->matchs_nb = 0;
	  return (0);
	}
      rowslist = rowslist->next;
      i++;
    }
  return (0);
}

int		substract_smallrow(t_rowslist *rowslist, int list_size)
{
  int		i;

  i = 0;
  while (i < list_size)
    {
      if (rowslist->matchs_nb == 1)
	{
	  rowslist->matchs_nb = 0;
	  return (0);
	}
      i++;
      rowslist = rowslist->next;
    }
  return (0);
}

int		check_endgame(t_rowslist *rowslist, int list_size)
{
  int		i;
  int		big_rows;
  int		small_rows;

  i = 0;
  big_rows = 0;
  small_rows = 0;
  while (i < list_size)
    {
      if (rowslist->matchs_nb > 1)
	big_rows++;
      if (rowslist->matchs_nb == 1)
	small_rows++;
      rowslist = rowslist->next;
      i++;
    }
  if (big_rows  > 1)
    return (1);
  rowslist = rowslist->next;
  i = 0;
  if (big_rows == 1)
    substract_bigrow(rowslist, list_size,  small_rows);
  else if (big_rows == 0)
    substract_smallrow(rowslist, list_size);
  return (0);
}

int		find_row_and_rm(t_rowslist *rowslist, int list_size, int s)
{
  int		i;

  i = 0;
  while (i < list_size)
    {
      if ((rowslist->matchs_nb ^ s) < rowslist->matchs_nb)
        {
          rowslist->matchs_nb = rowslist->matchs_nb ^ s;
          return (0);
        }
      rowslist = rowslist->next;
      i++;
    }
  return (0);
}

int		random_rm(t_rowslist *rowslist, int list_size)
{
  int		i;

  i = 0;
  while (i < list_size)
    {
      if (rowslist->matchs_nb > 0)
	{
	  rowslist->matchs_nb--;
	  return (0);
	}
      rowslist = rowslist->next;
      i++;
    }
  return (0);
}

int		ai_action(t_rowslist *rowslist, int list_size)
{
  int		s;
  int		i;
  
  s = 0;
  i = 0;
  if (check_endgame(rowslist, list_size) == 0)
    return (0);
  while (i < list_size)
    {
      s ^= rowslist->matchs_nb;
      rowslist = rowslist->next;
      i++;
    }
  rowslist = rowslist->next;
  if (s != 0) 
    find_row_and_rm(rowslist, list_size, s);
  else 
    random_rm(rowslist, list_size);
  return (0);
}
