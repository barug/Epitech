/*
** get_next_line2.c for get_next_line2 in /home/barthe_g/rendu/CPE_2014_get_next_line
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Nov 19 19:00:45 2014 barthelemy gouby
** Last update Thu Jan 15 18:42:48 2015 barthelemy gouby
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
  output_str = malloc ((a + b + 1) * sizeof(char));
  if (output_str == NULL)
    return (NULL);
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
      my_bzero(*buffer, READSIZE);
      if ((size_red = read(fd, *buffer, READSIZE)) < 0)
	return (2);
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

int	leftover_str_check(char **buffer, char **buffstart, char **output_str)
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
      *buffer = *buffstart; 
    }
  if (i == 0)
    *buffer = *buffstart;
  return (0);
}

char	*get_next_line(const int fd)
{
  static char   *buffer;
  static char	*buffstart;
  char          *output_str;
  int		i;
  static int	indicateur = 0;
  int		return_indic;

  i = 0;
  output_str = malloc ((READSIZE + 1) * sizeof(char));
  if (output_str == NULL)
    return (NULL);
  if (indicateur == 0)
    {
      buffstart = malloc ((READSIZE + 1) * sizeof(char));
      buffer = buffstart;
      if (buffer == NULL)
	return (NULL);
      my_bzero(buffer, READSIZE);
    }
  indicateur = 1;
  my_bzero(output_str, READSIZE);
  if (leftover_str_check(&buffer, &buffstart, &output_str) == 1)
    return (output_str);
  if (input_reader(&buffer, &output_str, fd) == 1)
    return (output_str);
  if (my_strlen(output_str) > 0)
    return (output_str);
  return (NULL);
}
