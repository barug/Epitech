/*
** get_next_line.c for get_next_line in /home/dupard_e/rendus/CPE_2014_getnextline
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Apr  7 19:13:53 2015 Erwan Dupard
** Last update Sat May 23 14:39:34 2015 karine aknin
*/

#include <stdlib.h>
#include <unistd.h>
#include "./get_next_line.h"
#include "../../../include/minishell.h"

int	my_cat_buf_to_line(char *line, char *buf, char *save)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(line);
  while (buf[j])
    {
      if (buf[j] == '\n' || i == BUFF_SIZE)
  	{
  	  line[i] = 0;
	  if (buf[j] == '\n')
	    j++;
  	  save = my_strcpy(save, buf + j);
  	  return (1);
  	}
      line[i++] = buf[j++];
    }
  save[0] = 0;
  line[i] = 0;
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	save[BUFF_SIZE];
  char		buf[BUFF_SIZE + 1];
  char		*line;
  int		len;

  if ((line = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
    {
      g_malloc = 1;
      return (NULL);
    }
  line[0] = 0;
  if (my_cat_buf_to_line(line, save, save) == 1)
    return (line);
  while ((len = read(fd, buf, BUFF_SIZE)) > 0 && BUFF_SIZE > 0)
    {
      buf[len] = 0;
      if (my_cat_buf_to_line(line, buf, save) == 1)
	return (line);
    }
  if (line && line[0] != 0)
    return (line);
  return (NULL);
}
