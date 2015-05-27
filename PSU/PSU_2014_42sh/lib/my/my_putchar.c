/*
** my_putchar.c for my_showstr in /home/dupard_e/rendu/Piscine_C_J06/ex_17
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 20:49:30 2014 Erwan Dupard
** Last update Mon Oct 20 16:07:20 2014 Erwan Dupard
*/

#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}
