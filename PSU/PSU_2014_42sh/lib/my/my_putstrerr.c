/*
** my_putstrerr.c for my_putstrerr in /home/dupard_e/rendus/PSU_2014_my_ls
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Nov 17 17:08:47 2014 Erwan Dupard
** Last update Fri Nov 21 16:09:34 2014 Erwan Dupard
*/

#include <unistd.h>
#include "./my.h"

void		my_putstrerr(char *str)
{
  write(2, str, my_strlen(str));
}
