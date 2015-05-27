WINDOW *win;

void    reprint(int useless)
{
  useless = useless;
  endwin();
  refresh();
  wrefresh(win);
}

int     main()
{
  /* t_rowslist    *rowslist; */
  /* int           list_size; */
  /* int           end; */
  /* int                row; */
  /* int                col; */

  initscr();
  /* getmaxyx(stdscr, row, col); */
  /* my_printf("\n%i %i\n", row, col); */
  win = newwin(30, 60, 0, 0);
  box(win, '|', '-');
  wrefresh(win);
  while (1)
    {
      signal(SIGWINCH, reprint);
    }
  /* end = 0; */
  /* list_size = 8; */
  /* rowslist = make_rowslist(list_size); */
  while (1);
  endwin();
  return (0);
}
