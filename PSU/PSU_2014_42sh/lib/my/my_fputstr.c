/*
** my_fputstr.c for libmy in /home/dupard_e/rendus/PSU_2014_my_ls/lib/my
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Nov 18 15:02:02 2014 Erwan Dupard
** Last update Tue Nov 18 16:19:33 2014 Erwan Dupard
*/

#include <unistd.h>
#include "./my.h"

void		my_fputstr(int fd, char *str)
{
  while (*str)
    {
      my_fputchar(fd, *(str));
      str++;
    }
}
