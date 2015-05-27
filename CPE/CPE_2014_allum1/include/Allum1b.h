/*
** Allum1b.h for Allum1b in /home/barthe_g/rendu/CPE/B2/Allum1/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Feb 19 10:22:23 2015 barthelemy gouby
** Last update Fri Feb 20 17:49:37 2015 barthelemy gouby
*/

#ifndef ALLUM1B_H_
#define ALLUM1B_H_

typedef struct          s_rowslist
{
  int                   matchs_nb;
  int			cursor;
  struct s_rowslist     *next;
  struct s_rowslist     *before;
}                       t_rowslist;

typedef struct		s_window
{
  WINDOW		*win;
  int			max_y;
  int			max_x;
}			t_window;

int                     ai_action(t_rowslist *rowslist, int list_size);
t_rowslist              *make_rowslist(int list_size);
void                    free_list(t_rowslist *rowslist, int list_size);
int			player_input(t_rowslist *rowslist, int list_size,
				     t_window *gamewin, t_window *displaywin);
void			display_listb(t_rowslist *rowslist, t_window *window,
				      int list_size);
t_window		*create_window(int lines, int cols, int y, int x);
int			do_turn(t_rowslist *rowslist, int list_size,
                        t_window *gamewin, t_window *displaywin);

#endif /* ALLUM1B_H_ */
