/*
** get_next_line2.c for get_next_line2 in /home/barthe_g/rendu/CPE_2014_get_next_line
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Nov 19 19:00:45 2014 barthelemy gouby
** Last update Tue Dec  2 18:03:08 2014 barthelemy gouby
*/

#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

char    *add_str(char *str1, char *str2, int n)
{
  int   a;
  int   b;
  int   i;
  char  *output_str;

  i = 0;
  a = my_strlen(str1);
  b = my_strlen(str2);
  output_str = malloc ((a + b) * sizeof(char));
  while (i < a)
    {
      output_str[i] = str1[i];
      i++;
    }
  while ((i - a) < b && (i - a) < n)
    {
      output_str[i] = str2[i - a];
      i++;
    }
  output_str[i] = '\0';
  return (output_str);
}

void    my_bzero(char *str, int size)
{
  int   i;
  
  i = 0;
  while (i <= size)
    {
      str[i] = '\0';
      i++;
    }
}

int	input_reader(char **buffer, char **output_str, const int fd)
{
  int	i;
  int	size_red;

  size_red = 1;
  while (size_red != 0)
    {
      i = 0;
      my_bzero(*buffer, READSIZE + 1);
      size_red = read(fd, *buffer, READSIZE);
      while ((*buffer)[i] != '\0' && (*buffer)[i] != '\n')
        i++;
      if ((*buffer)[i] == '\n')
        {
          *output_str = add_str(*output_str, *buffer, i);
          *buffer = &((*buffer)[i + 1]);
          return (1);
        }
      *output_str = add_str(*output_str, *buffer, i);
    }
  return (0);
}

int	leftover_str_check(char **buffer, char **output_str)
{
  int	i;

  i = 0;
  while ((*buffer)[i] != '\0' && (*buffer)[i] != '\n')
    i++;
  if ((*buffer)[i] == '\n')
    {
      (*buffer)[i] = '\0';
      *output_str = add_str(*output_str, *buffer, i);
      *buffer = &((*buffer)[i + 1]);
      return (1);
    }
  if (i > 0)
    {
      *output_str = add_str(*output_str, *buffer, i);
    }
  return (0);
}

char	*get_next_line(const int fd)
{
  static char   *buffer;
  char          *output_str;
  int		i;
  static int	indicateur = 0;
  int		return_indic;

  i = 0;
  output_str = malloc ((READSIZE + 1) * sizeof(char));
  if (indicateur == 0)
    {
      buffer = malloc ((READSIZE + 1) * sizeof(char));
      my_bzero(buffer, READSIZE + 1);
    }
  indicateur = 1;
  my_bzero(output_str, READSIZE + 1);
  return_indic = leftover_str_check(&buffer, &output_str);
  if (return_indic == 1)
    return (output_str);
  return_indic = input_reader(&buffer, &output_str, fd);
  if (return_indic == 1)
    return (output_str);
  if (my_strlen(output_str) > 0)
    return (output_str);
  return (NULL);
}
