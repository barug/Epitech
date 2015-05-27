/*
** my_select_include.h for my_select_include in /home/barthe_g/rendu/PSU/PSU_2014_my_select/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jan  6 17:03:18 2015 barthelemy gouby
** Last update Sun Jan 11 23:11:22 2015 barthelemy gouby
*/

#ifndef MYSELECT_H_
# define MYSELECT_H_

typedef struct	s_list
{
  char		*name;
  struct s_list	*next;
  struct s_list	*before;
  int		position;
  int		selected;
  int		underligned;
}		t_list;

typedef struct	s_listnfo
{
  t_list	*list;
  t_list	*liststart;
  int		argc;
}		t_listnfo;

int		set_tattr();
int		restore_tattr();
void		new_putchar(char c, int termfd);
void		new_putstr(char *str, int termfd);
int		display_list(t_list *list, int argc, int termfd);
int		display_selected(t_list *list, int argc);
int		load_termcaps(char **envp);
int		initialize(t_listnfo *listnfo, int argc, char **argv, char **envp);
t_list		*make_list(int argc, char **argv);
int		list_loop(t_list **entry, t_list **entrybefore, int argc, char **argv);
t_list		*make_list(int argc, char **argv);
void		free_list(t_listnfo *listnfo);

#endif /* !MYSELECT_H_ */
