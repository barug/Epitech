/*
** mainb.c for Allum1 in /home/barthe_g/rendu/CPE/B2/Allum1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Feb 18 12:17:12 2015 barthelemy gouby
** Last update Fri Feb 20 17:51:42 2015 barthelemy gouby
*/

#define _BSD_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include "Allum1b.h"
#include "my.h"

int	choose_size(t_window *window)
{
  char	*input;
  int	end;
  int	size;

  end = 0;
  werase(window->win);
  box(window->win, 0, 0);
  mvwaddstr(window->win, 3, 6, "choose a size between 4 and 10:");
  wrefresh(window->win);
  if ((input = malloc(3 * sizeof(char))) == NULL)
    return (-1);
  while (end == 0)
    {
      wgetnstr(window->win, input, 2);
      size = my_getnbr(input);
      if (size < 4 || size > 10)
	{
	  mvwaddstr(window->win, 3, 37, "  ");
          wmove(window->win, 3, 37);
          end = 0;
	}
      else
	end = 1;
    }
  return (size);
}

int		initialize(t_window **displaywin, t_window **gamewin,
			   int *list_size, t_rowslist **rowslist)
{
  initscr();
  if ((*displaywin = create_window(6, 45, 0, 0)) == NULL)
    return (-1);
  if ((*gamewin = create_window(30, 45, 6, 0)) == NULL)
    return (-1);
  if ((*list_size = choose_size(*displaywin)) == -1)
    return (-1);
  if ((*rowslist = make_rowslist(*list_size)) == NULL)
    return (-1);
  cbreak();
  noecho();
  curs_set(0);
  keypad((*gamewin)->win, TRUE);
  return (0);
} 

int		main()
{
  t_rowslist    *rowslist;
  int           list_size;
  t_window	*displaywin;
  t_window	*gamewin;
  int		end;

  end = 0;
  if (initialize(&displaywin, &gamewin, &list_size, &rowslist) == -1)
    return (-1);
  display_listb(rowslist, gamewin, list_size);
  while (end == 0)
    end = do_turn(rowslist, list_size, gamewin, displaywin);
  delwin(displaywin->win);
  free(displaywin);
  delwin(gamewin->win);
  free(gamewin);
  free_list(rowslist, list_size);
  endwin();
  return (0);
}
