/*
** Allum1.h for Allum1 in /home/barthe_g/rendu/CPE/B2/Allum1/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Feb  3 15:24:49 2015 barthelemy gouby
** Last update Wed Feb 18 11:49:43 2015 barthelemy gouby
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_

typedef struct		s_rowslist
{
  int			matchs_nb;
  struct s_rowslist	*next;
  struct s_rowslist	*before;
}			t_rowslist;

int			ai_action(t_rowslist *rowslist, int list_size);
int			player_input(t_rowslist *rowslist, int list_size);
t_rowslist		*make_rowslist(int list_size);
void			display_list(t_rowslist *rowslist, int list_size);
void			free_list(t_rowslist *rowslist, int list_size);

#endif /* !ALLUM1_H_ */
