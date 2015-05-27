/*
** my_str_to_word_tab.c<2> for my_str_to_word_tab in /home/dupard_e/rendus/rush/marvin
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Sat Jan  3 11:50:35 2015 Erwan Dupard
** Last update Thu May 21 18:50:36 2015 Erwan Dupard
*/

#include <stdlib.h>
#include "./my.h"

int		is_sep(char c)
{
  return (c == ' ' || c == ':' || c == '\t');
}

int		get_word_count(char *str)
{
  int		len;

  len = 0;
  while (*str)
    {
      while (*str && is_sep(*str))
	str++;
      if (!is_sep(*str))
	{
	  len++;
	  while (*str && !is_sep(*str))
	    str++;
	}
      if (*str)
	str++;
    }
  return (len);
}

char		*get_some_str(char *str)
{
  char		*ret;
  int		i;

  i = 0;
  while (str[i] && !is_sep(str[i]))
    i++;
  if ((ret = malloc(sizeof(*str) * i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] && !is_sep(str[i]))
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}

char		**my_str_to_word_tab(char *str)
{
  int		len;
  char		**tab;
  int		j;

  j = 0;
  len = get_word_count(str);
  if ((tab = malloc(sizeof(*tab) * (len + 2))) == NULL)
    return (NULL);
  while (*str)
    {
      if (!is_sep(*str))
	{
	  if ((tab[j] = get_some_str(str)) == NULL)
	    return (NULL);
	  j++;
	  while (*str && !is_sep(*str))
	    str++;
	}
      if (*str)
	str++;
    }
  tab[j] = NULL;
  return (tab);
}
