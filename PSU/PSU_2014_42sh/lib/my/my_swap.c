/*
** my_swap.c for my_swap in /home/dupard_e/rendu/Piscine_C_J04
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Oct  2 17:20:48 2014 Erwan Dupard
** Last update Thu Oct  2 23:23:59 2014 Erwan Dupard
*/

int		my_swap(int *a, int *b)
{
  int		c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}

int		my_swap_char(char *a, char *b)
{
  char		c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
