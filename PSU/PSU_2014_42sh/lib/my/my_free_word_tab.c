/*
** my_free_word_tab.c for libmy in /home/dupard_e/rendus/PSU_2014_minishell1/lib/my
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Dec 30 19:47:22 2014 Erwan Dupard
** Last update Wed Jan 21 15:54:22 2015 Erwan Dupard
*/

#include <stdlib.h>

int		my_free_word_tab(char ***word_tab)
{
  int		i;
  char		**tab;

  tab = *word_tab;
  i = -1;
  if (!tab)
    return (1);
  while (tab && tab[++i])
    free(tab[i]);
  if (tab)
    free(tab);
  return (0);
}
