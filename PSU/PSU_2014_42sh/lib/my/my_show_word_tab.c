/*
** my_show_word_tab.c for libmy in /home/dupard_e/rendus/PSU_2014_minishell1/lib/my
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Dec 30 19:54:13 2014 Erwan Dupard
** Last update Fri Apr  3 16:49:58 2015 Erwan Dupard
*/

#include "./my.h"

void		my_show_word_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      my_printf("%s ", tab[i]);
      i++;
    }
  my_printf("\n");
}
