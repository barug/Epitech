/*
** my_intlen.c for libmy in /home/dupard_e/rendus/PSU_2014_my_ls/lib/my
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Nov 18 17:33:16 2014 Erwan Dupard
** Last update Tue Nov 18 17:46:25 2014 Erwan Dupard
*/

#include "./my.h"

# define ABS(c) (c >= 0 ? c : -c)

int		my_intlen(int n)
{
  int		len;

  len = 0;
  if (n == 0)
    return (1);
  while (n > 0)
    {
      n /= 10;
      len++;
    }
  return (len);
}
