/*
** add_array_entry.c for add_array_entry in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Dec 15 16:15:36 2014 barthelemy gouby
** Last update Mon Dec 15 16:16:05 2014 barthelemy gouby
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
