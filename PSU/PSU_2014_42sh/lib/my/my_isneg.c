/*
** my_isneg.c for libmy in /home/dupard_e/rendu/Piscine_C_J07
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Oct  7 09:52:21 2014 Erwan Dupard
** Last update Mon Oct 20 16:06:03 2014 Erwan Dupard
*/

void		my_putchar(char c);

int		my_isneg(int n)
{
  if (n < 0)
      my_putchar('N');
  if (n >= 0)
      my_putchar('P');
  return (0);
}
