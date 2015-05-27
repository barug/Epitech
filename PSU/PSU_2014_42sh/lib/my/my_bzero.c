/*
** my_bzero.c for libmy in /home/dupard_e/rendus/PSU_2014_my_ls/lib/my
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Nov 21 14:59:57 2014 Erwan Dupard
** Last update Fri Nov 21 15:00:53 2014 Erwan Dupard
*/

#include "./my.h"

char		*my_bzero(char str[])
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      str[i] = 0;
      i++;
    }
  return (str);
}
