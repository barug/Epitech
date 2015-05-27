/*
** main.c for main in /home/barthe_g/rendu/CPE/CPE_2014_bsq
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jan 13 17:10:38 2015 barthelemy gouby
** Last update Sun Jan 18 21:47:44 2015 barthelemy gouby
*/

#include <ncurses/curses.h>
#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "bsq_include.h"

int			load_termcaps(char **envp)
{
  int			i;
  char			*termid;

  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp(envp[i], "TERM=", 5) == 0)
        termid = &(envp[i][5]);
      i++;
    }
  if (tgetent(NULL, termid) != 1)
    {
      my_printf("failure while loading termcaps\n");
      return (-1);
    }
  return (0);
}

void		make_maxsquare(t_tabnfo *tabnfo, t_maxsquare *maxsquare)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y < maxsquare->size)
    {
      while (x < maxsquare->size)
	tabnfo->tabl[maxsquare->y + y][maxsquare->x + x++] = 'X';
      x = 0;
      y++;
    }
}

void		if_X(t_tabnfo *tabnfo, int *x, int y)
{
  if (tabnfo->tabl[y][*x] == 'X')
    {
      my_printf("\033[32m");
      while (tabnfo->tabl[y][*x] == 'X')
	{
	  my_putchar('X');
	  (*x)++;
	}
      my_printf("\033[0m");
    }
}

void		if_o(t_tabnfo *tabnfo, int *x, int y)
{
  if (tabnfo->tabl[y][*x] == 'o')
    {
      my_printf("\033[31m");
      while (tabnfo->tabl[y][*x] == 'o')
        {
          my_putchar('o');
          (*x)++;
        }
      my_printf("\033[0m");
    }
}

void		display_tab(t_tabnfo *tabnfo)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (tabnfo->tabl[y] != NULL)
    {
      while (tabnfo->tabl[y][x] != '\0')
	{
	  if_X(tabnfo, &x, y);
	  if_o(tabnfo, &x, y);
	  if (tabnfo->tabl[y][x] == '.')
	    {
	      my_putchar('.');
	      x++;
	    }
	}
      my_putchar('\n');
      x = 0;
      y++;
    }
}

void		free_tabnfo(t_tabnfo *tabnfo)
{
  int		y;

  y = 0;
  while(tabnfo->tabl[y] != NULL)
    free(tabnfo->tabl[y++]);
  free(tabnfo->tabl[y]);
  free(tabnfo->tabl);
  free(tabnfo);
}

int		main(int argc, char **argv, char **envp)
{
  t_tabnfo	*tabnfo;
  t_maxsquare	*maxsquare;

  argc = argc;
  if (load_termcaps(envp) == -1)
    return (-1);
  if ((tabnfo = malloc(sizeof(t_tabnfo))) == NULL)
    return (-1);
  if ((maxsquare = malloc(sizeof(t_maxsquare))) == NULL)
    return (-1);
  if (make_tab(argv[1], tabnfo) == -1)
    return (-1);
  if (check_tab(tabnfo) == -1)
    return (-1);
  if (find_maxsquare(tabnfo, maxsquare) == -1)
    {
      my_printf("no possible square");
      return (-1);
    }
  my_printf("FOUND:\n");
  make_maxsquare(tabnfo, maxsquare);
  display_tab(tabnfo);
  free_tabnfo(tabnfo);
  return (0);
}
