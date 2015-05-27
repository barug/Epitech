/*
** loadtab.c for loadtab in /home/barthe_g/rendu/CPE/CPE_2014_bsq
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Jan 16 16:13:51 2015 barthelemy gouby
** Last update Sun Jan 18 22:21:01 2015 barthelemy gouby
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include <term.h>
#include "my.h"
#include "bsq_include.h"

int		check_tab(t_tabnfo *tabnfo)
{
  int		x;
  int		y;

  y = 1;
  x = 0;
  while (tabnfo->tabl[y])
    {
      while (tabnfo->tabl[y][x])
        {
          if (tabnfo->tabl[y][x] != '.' && tabnfo->tabl[y][x] != 'o')
            return (-1);
          x++;
        }
      if (x != tabnfo->nbr_of_colns)
        return (-1);
      x = 0;
      y++;
    }
  if (y != tabnfo->nbr_of_lines)
    return (-1);
  return (0);
}

int		get_firstline(int fd, t_tabnfo *tabnfo)
{
  int		i;
  char		*line;

  i = 0;
  if ((line = get_next_line(fd)) == NULL)
    return (-1);
  while (line[i])
    {
      if (line[i] < '0' || line[i] >'9')
        return (-1);
      i++;
    }
  i = 0;
  tabnfo->nbr_of_lines = my_getnbr(line);
  if ((tabnfo->tabl = malloc((my_getnbr(line) + 1) * sizeof(char*))) == NULL)
    return (-1);
  free(line);
  return (0);
}

void		make_line(char *line, t_tabnfo *tabnfo, int *i)
{
  char		*termcap;

  termcap = tgetstr("cd", NULL);
  my_printf("%s", termcap);
  my_printf("line:%i\n", *i + 1);
  termcap = tgetstr("UP", NULL);
  termcap = tparm(termcap, 1);
  my_printf("%s", termcap);
  tabnfo->tabl[(*i)++] =  line;
}

int		make_tab(char *pathname, t_tabnfo *tabnfo)
{
  int		fd;
  char		*line;
  int		i;
  char		*termcap;

  i = 0;
  my_printf("\nLOADING TAB...\n");
  if((fd = open(pathname, O_RDONLY)) == -1)
    return (-1);
  if (get_firstline(fd, tabnfo) == -1)
    return (-1);
  while ((line = get_next_line(fd)) != NULL)
    make_line(line, tabnfo, &i);
  termcap = tgetstr("cd", NULL);
  my_printf("%s", termcap);
  my_printf("DONE");
  tabnfo->tabl[i] = NULL;
  i = 0;
  while(tabnfo->tabl[0][i])
    i++;
  tabnfo->nbr_of_colns = i;
  return (0);
}
