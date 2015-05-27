/*
** my_revstr.c for my_revstr in /home/dupard_e/rendu/Piscine_C_J06/ex_3
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 09:04:45 2014 Erwan Dupard
** Last update Sat May 23 15:03:58 2015 Erwan Dupard
*/

#include "./my.h"

char		*my_revstr(char *str)
{
  int		l;
  int		i;

  i = 0;
  l = my_strlen(str) - 1;
  while (i != (l / 2) + 1)
    {
      my_swap_char(&str[l-i], &str[i]);
      i++;
    }
  return (str);
}
