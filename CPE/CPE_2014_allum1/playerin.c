/*
** playerin.c for Allum1 in /home/barthe_g
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Feb 18 11:28:59 2015 barthelemy gouby
** Last update Wed Feb 18 11:38:37 2015 barthelemy gouby
*/

#include <stdlib.h>
#include "my.h"
#include "Allum1.h"

void		remove_matchs(t_rowslist *rowslist, int row, int rm_nb)
{
  int		i;
  t_rowslist	*tmp;

  i = 0;
  tmp = rowslist;
  while (i < row - 1)
    {
      tmp = tmp->next;
      i++;
    }
  if (rm_nb > tmp->matchs_nb)
    tmp->matchs_nb = 0;
  else
    tmp->matchs_nb -= rm_nb;
}

int		check_row(t_rowslist *rowslist, int *row)
{
  int		i;

  i = 1;
  while (i < *row )
    {
      rowslist = rowslist->next;
      i++;
    }
  if (rowslist->matchs_nb == 0)
    {
      my_printf("empty row\n");
      return (1);
    }
  return (0);
}

int		get_row(t_rowslist *rowslist, int *row, int list_size)
{
  char		*input;
  int		done;

  done = 0;
  while (done == 0)
    {
      if ((input = get_next_line(0)) == NULL)
        return (-1);
      if (my_strcmp(input, "exit") == 0)
        return (1);
      *row = my_getnbr(input);
      if (*row <= 0 || *row > list_size)
        my_printf("incorrect row number\n");
      else if (check_row(rowslist, row) == 0)
	done = 1;
    }
  return (0);
}

int		get_rm_nb(int *rm_nb)
{
  char		*input;
  int		done;

  done = 0;
  while (done == 0)
    {
      if ((input = get_next_line(0)) == NULL)
        return (-1);
      if (my_strcmp(input, "exit") == 0)
        return (1);
      *rm_nb = my_getnbr(input);
      if (*rm_nb <= 0)
        my_printf("please enter positive number\n");
      else
        done = 1;
    }
  return (0);
}

int		player_input(t_rowslist *rowslist, int list_size)
{
  int		row;
  int		rm_nb;
  int		end;

  my_printf("select row:\n");
  if ((end = get_row(rowslist, &row, list_size)) == -1)
    return (-1);
  else if (end == 1)
    return (1);
  my_printf("select number of matchsticks to remove:\n");
  if ((end = get_rm_nb(&rm_nb)) == -1)
    return (-1);
  else if (end == 1)
    return (1);
  remove_matchs(rowslist, row, rm_nb);
  return (0);
}
