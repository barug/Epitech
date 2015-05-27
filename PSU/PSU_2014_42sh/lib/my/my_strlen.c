/*
** my_strlen.c for my_strncpy in /home/dupard_e/rendu/Piscine_C_J06/ex_02
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 16:27:02 2014 Erwan Dupard
** Last update Tue Nov 18 16:11:16 2014 Erwan Dupard
*/

#include <stdio.h>
#include "./my.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
      i++;
  return (i);
}
