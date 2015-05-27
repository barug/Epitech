/*
** my_putcharerr.c for libmy in /home/dupard_e/rendus/PSU_2014_my_ls/lib/my
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Nov 18 14:59:17 2014 Erwan Dupard
** Last update Sat May 23 15:02:20 2015 Erwan Dupard
*/

#include <unistd.h>

void		my_fputchar(int f, char c)
{
  (void)write(f, &c, 1);
}
