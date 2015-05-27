/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Dec 15 16:09:33 2014 barthelemy gouby
** Last update Mon Dec 15 16:24:38 2014 barthelemy gouby
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

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
