/*
** parser_functions.c for parser_functions in /home/barthe_g/rendu/MUL_2014_fdf
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Dec  7 17:07:58 2014 barthelemy gouby
** Last update Sun Dec  7 17:08:40 2014 barthelemy gouby
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "datastruct.h"
#include "pixelinfo.h"
#include "point_info.h"
#include "my.h"
#include "local_include.h"

char    **add_array_entry(char **tab, char *array_entry)
{
  int   i;
  char  **new_tab;

  i = 0;
  while (tab[i] != NULL)
    i++;
  new_tab = malloc((i + 2) * sizeof(char*));
  if (new_tab == NULL)
    return (NULL);
  i = 0;
  while (tab[i] != NULL)
    {
      new_tab[i] = tab[i];
      i++;
    }
  new_tab[i++] = array_entry;
  new_tab[i] = NULL;
  free(tab);
  return (new_tab);
}

char            **my_str_to_wordtab(char *str)
{
  char          **str_array;
  char          *word;
  int           i;
  int           a;

  i = 0;
  a = 0;
  str_array = malloc(sizeof(char*));
  str_array[0] = NULL;
  while (str[i] != '\0')
    {
      if (str[i] != ' ')
        {
          while (str[a] != ' ' && str[a] != '\0')
            a++;
          word = malloc((a + 1) * sizeof(char));
          a = 0;
          while (str[i] != ' ' && str[i] != '\0')
            word[a++] = str[i++];
          word[a] = '\0';
          str_array = add_array_entry(str_array, word);
          a = 0;
        }
      else
        i++;
    }
  return (str_array);
}
