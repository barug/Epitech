/*
** turnb.c for Allum1.c in /home/barthe_g/rendu/CPE/B2/Allum1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Feb 20 17:47:17 2015 barthelemy gouby
** Last update Fri Feb 20 17:51:34 2015 barthelemy gouby
*/

#define _BSD_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include "Allum1b.h"
#include "my.h"

int		reset_cursor(t_rowslist *rowslist, int list_size)
{
  t_rowslist	*savefirst;
  int		i;

  i = 0;
  savefirst = rowslist;
  while (i < list_size)
    {
      rowslist->cursor = 0;
      rowslist = rowslist->next;
      i++;
    }
  rowslist = savefirst;
  i = 0;
  while (i < list_size)
    {
      if (rowslist->matchs_nb > 0)
        {
          rowslist->cursor = 1;
          return (0);
        }
      rowslist = rowslist->next;
      i++;
    }
  return (0);
}

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

void		ai_turn(t_rowslist *rowslist, int list_size,
                        t_window *gamewin, t_window *displaywin)
{
  werase(displaywin->win);
  box(displaywin->win, 0, 0);
  mvwaddstr(displaywin->win, 3, 17, "bot's turn:");
  wrefresh(displaywin->win);
  usleep(1000000);
  ai_action(rowslist, list_size);
  reset_cursor(rowslist, list_size);
  display_listb(rowslist, gamewin, list_size);
}

int		do_turn(t_rowslist *rowslist, int list_size,
                        t_window *gamewin, t_window *displaywin)
{
  if (player_input(rowslist, list_size, gamewin, displaywin) != 0)
    return (1);
  display_listb(rowslist, gamewin, list_size);
  if (check_win(rowslist, list_size) == 0)
    {
      werase(displaywin->win);
      box(displaywin->win, 0, 0);
      mvwaddstr(displaywin->win, 3, 18, "you win!");
      wrefresh(displaywin->win);
      usleep(3000000);
      return (1);
    }
  ai_turn(rowslist, list_size, gamewin, displaywin);
  if (check_win(rowslist, list_size) == 0)
    {
      werase(displaywin->win);
      box(displaywin->win, 0, 0);
      mvwaddstr(displaywin->win, 3, 18, "bot win!");
      wrefresh(displaywin->win);
      usleep(3000000);
      return (1);
    }
  return (0);
}
