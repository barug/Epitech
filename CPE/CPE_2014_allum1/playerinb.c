/*
** playerinb.c for Allum1b in /home/barthe_g/rendu/CPE/B2/Allum1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Feb 19 12:04:19 2015 barthelemy gouby
** Last update Fri Feb 20 16:46:06 2015 barthelemy gouby
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "Allum1b.h"
#include "my.h"

void		execute_keys(t_rowslist **rowslist, int *end, int ch)
{
  if (ch == KEY_UP)
    {
      (*rowslist)->cursor = 0;
      *rowslist = (*rowslist)->before;
      while ((*rowslist)->matchs_nb == 0)
	*rowslist = (*rowslist)->before;
      (*rowslist)->cursor = 1;
    }
  if (ch == KEY_DOWN)
    {
      (*rowslist)->cursor = 0;
      (*rowslist) = (*rowslist)->next;
      while ((*rowslist)->matchs_nb == 0)
	*rowslist = (*rowslist)->next;
      (*rowslist)->cursor = 1;
    }
  if (ch == '\n')
    *end = 1;
}

int		get_row(t_rowslist *rowslist, t_window *window, int list_size)
{
  int		end;
  int		ch;
  t_rowslist	*savefirst;

  end = 0;
  savefirst = rowslist;
  while (end == 0)
    {
      ch = wgetch(window->win);
      execute_keys(&rowslist, &end, ch);
      display_listb(savefirst, window, list_size);
    }
  return (0);
}

void		change_displaywin(t_window *window)
{
  werase(window->win);
  box(window->win, 0, 0);
  mvwaddstr(window->win, 3, 2, "select number of matchsticks to remove:");
  wrefresh(window->win);
  echo();
  nocbreak();
  curs_set(1);
}

int		get_rm_nb(t_window *window)
{
  char		*input;
  int		end;
  int		rm_nb;

  end = 0;
  change_displaywin(window);
  if ((input = malloc(3 * sizeof(char))) == NULL)
      return (-1);
  while (end == 0)
    {
      wgetnstr(window->win, input, 2);
      rm_nb = my_getnbr(input);
      if (rm_nb <= 0)
	{
	  mvwaddstr(window->win, 3, 41, "  ");
	  wmove(window->win, 3, 41);
	  end = 0;
	}
      else 
	end = 1;
    }
  noecho();
  cbreak();
  curs_set(0);
  return (rm_nb);
}

int	remove_matchs(t_rowslist *rowslist, int list_size, int rm_nb)
{
  while (list_size > 0)
    {
      if (rowslist->cursor == 1)
	{
	  rowslist->matchs_nb -= rm_nb;
	  if (rowslist->matchs_nb < 0)
	    rowslist->matchs_nb = 0;
	  return (0);
	}
      rowslist = rowslist->next;
      list_size--;
    }
  return (0);
}

int	player_input(t_rowslist *rowslist, int list_size,
		     t_window *gamewin, t_window *displaywin)
{
  int	rm_nb;

  werase(displaywin->win);
  box(displaywin->win, 0, 0);
  mvwaddstr(displaywin->win, 3, 17, "select row");
  wrefresh(displaywin->win);
  get_row(rowslist, gamewin, list_size);
  if ((rm_nb = get_rm_nb(displaywin)) == -1)
    return (-1);
  remove_matchs(rowslist, list_size, rm_nb);
  return (0);
}
