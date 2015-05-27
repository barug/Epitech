/*
** displayb.c for Allum1b in /home/barthe_g/rendu/CPE/B2/Allum1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Feb 20 17:28:06 2015 barthelemy gouby
** Last update Fri Feb 20 17:34:10 2015 barthelemy gouby
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "Allum1b.h"
#include "my.h"

t_window	*create_window(int lines, int cols, int y, int x)
{
  t_window	*window;

  if ((window = malloc(sizeof(t_window))) == NULL)
    return (NULL);
  window->win = newwin(lines, cols, y, x);
  getmaxyx(window->win, window->max_y, window->max_x);
  box(window->win, 0, 0);
  wrefresh(window->win);
  return (window);
}

void		if_cursor_display(t_rowslist *rowslist, t_window *window,
                                  int list_size, int line)
{
  if (rowslist->cursor == 1)
    {
      mvwaddch(window->win, window->max_y / 2 - list_size / 2 + line,
               window->max_x / 2 - 10, '>');
      mvwaddch(window->win, window->max_y / 2 - list_size / 2 + line,
               window->max_x / 2 + 10, '<');
    }
}

void		display_listb(t_rowslist *rowslist, t_window *window, int list_size)
{
  int		offset;
  int		mstcks;
  int		line;

  offset = 0;
  mstcks = 0;
  line = 0;
  werase(window->win);
  box(window->win, 0, 0);
  while (line < list_size)
    {
      if_cursor_display(rowslist, window, list_size, line);
      while (mstcks < rowslist->matchs_nb)
        {
          mvwaddch(window->win, window->max_y / 2 - list_size / 2 + line,
                   window->max_x / 2 - offset + mstcks, '|');
          mstcks++;
        }
      mstcks = 0;
      line++;
      offset++;
      rowslist = rowslist->next;
    }
  wrefresh(window->win);
}
