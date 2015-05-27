/*
** bsq_include.h for bsq_include in /home/barthe_g/rendu/CPE/CPE_2014_bsq/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jan 13 17:37:02 2015 barthelemy gouby
** Last update Fri Jan 16 17:34:52 2015 barthelemy gouby
*/

#ifndef BSQ_H_
# define BSQ_H_

typedef struct	s_tabnfo
{
  char		**tabl;
  int		nbr_of_lines;
  int		nbr_of_colns;
}		t_tabnfo;

typedef struct	s_maxsquare
{
  int		x;
  int		y;
  int		size;
}		t_maxsquare;

int             find_maxsquare(t_tabnfo *tabnfo, t_maxsquare *maxsquare);
int             check_tab(t_tabnfo *tabnfo);
int             get_firstline(int fd, t_tabnfo *tabnfo);
int             make_tab(char *pathname, t_tabnfo *tabnfo);

#endif /* !BSQ_H_ */
