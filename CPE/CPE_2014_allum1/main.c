/*
** main.c for Allum1 in /home/barthe_g/rendu/CPE/B2/Allum1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Feb  3 12:02:48 2015 barthelemy gouby
** Last update Fri Feb 20 16:53:02 2015 barthelemy gouby
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "Allum1.h"

int		check_win(t_rowslist *rowslist, int list_size)
{
  int		i;
  int		big_row;
  int		small_row;

  big_row = 0;
  small_row = 0;
  i = 0;
  while (i < list_size)
    {
      if (rowslist->matchs_nb > 1)
	big_row++;
      if (rowslist->matchs_nb == 1)
	small_row++;
      rowslist = rowslist->next;
      i++;
    }
  if (big_row == 0 && small_row == 1)
    return (0);
  return (1);
}

int		do_turn(t_rowslist *rowslist, int list_size)
{
  if (player_input(rowslist, list_size) != 0)
    return (1);
  display_list(rowslist, list_size);
  if (check_win(rowslist, list_size) == 0)
    {
      my_printf("you win!\n");
      free_list(rowslist, list_size);
      return (1);
    }
  ai_action(rowslist, list_size);
  my_printf("bot's turn:\n");
  display_list(rowslist, list_size);
  if (check_win(rowslist, list_size) == 0)
    {
      my_printf("bot win!\n");
      free_list(rowslist, list_size);
      return (1);
    }
  return (0);
}

int		main()
{
  t_rowslist	*rowslist;
  int		list_size;
  int		end;

  end = 0;
  list_size = 4;
  if ((rowslist = make_rowslist(list_size)) == NULL)
    return (-1);
  display_list(rowslist, list_size);
  while (end == 0)
    end = do_turn(rowslist, list_size);
  free_list(rowslist, list_size);
  return (0);
}
