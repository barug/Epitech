/*
** algo.c for algo in /home/barthe_g/rendu/CPE/CPE_2014_bsq
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Jan 14 14:15:29 2015 barthelemy gouby
** Last update Sun Jan 18 22:25:42 2015 barthelemy gouby
*/

#include "my.h"
#include "bsq_include.h"
#include <ncurses/curses.h>
#include <term.h>

int		search_square(t_tabnfo *tabnfo, int squaresize, int *x, int *y)
{
  int		xcase;
  int		ycase;

  xcase = 0;
  ycase = 0;
  while (squaresize - ycase > 0)
    {
      while (squaresize - xcase > 0)
	{
	  if (tabnfo->tabl[*y + ycase][*x + xcase] == 'o')
	    {
	      if (tabnfo->nbr_of_colns - (*x + xcase + 1 + squaresize) >= 0)
		*x = *x + xcase;
	      else
	      	{
	      	  *x = -1;
	      	  *y = *y + 1;
	      	}
	      return (1);
	    }
	  xcase++;
	}
      xcase = 0;
      ycase++;
    }
  return (0);
}

int		search_tab(t_tabnfo *tabnfo, t_maxsquare *maxsquare,
			   int squaresize)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (tabnfo->nbr_of_lines - (y + squaresize) >= 0)
    {
      while (tabnfo->nbr_of_colns - (x + squaresize) >= 0 &&
	     tabnfo->nbr_of_lines - (y + squaresize) >= 0)
	{
	  if (search_square(tabnfo, squaresize, &x, &y) == 0)
	    {
	      maxsquare->x = x;
	      maxsquare->y = y;
	      maxsquare->size = squaresize;
	      return (1);
	    }
	  x++;
	}
      x = 0;
      y++;
    }
  return (0);
}

int		find_maxsquaresize(t_tabnfo *tabnfo)
{
  if (tabnfo->nbr_of_lines < tabnfo->nbr_of_colns)
    return (tabnfo->nbr_of_lines);
  else
    return (tabnfo->nbr_of_colns);
}

int		find_maxsquare(t_tabnfo *tabnfo, t_maxsquare *maxsquare)
{
  int		squaresize;
  int		squarefound;
  char		*termcap;

  squarefound = 0;
  squaresize = find_maxsquaresize(tabnfo);
  my_printf("\nSEARCHING...\n");
  while (squaresize > 0 && squarefound == 0)
    {
      termcap = tgetstr("cd", NULL);
      my_printf("%s", termcap);
      my_printf("squaresize: %i\n", squaresize);
      termcap = tgetstr("UP", NULL);
      termcap = tparm(termcap, 1);
      my_printf("%s", termcap);
      squarefound = search_tab(tabnfo, maxsquare, squaresize--);
    }
  termcap = tgetstr("cd", NULL);
  my_printf("%s", termcap);
  if (squarefound == 1)
    return (0);
  else
    return (-1);
}
