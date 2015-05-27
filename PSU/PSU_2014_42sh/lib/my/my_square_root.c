/*
** my_square_root.c for my_square_root in /home/dupard_e/rendu/Piscine_C_J05
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Oct  3 18:17:06 2014 Erwan Dupard
** Last update Mon Oct 20 15:52:38 2014 Erwan Dupard
*/

int		my_square_root(int nb)
{
  int		i;

  i = 0;
  while (i != nb)
    {
      if (nb >= 2147483647 || nb <= -2147483647)
	return (0);
      if (i*i == nb)
	return (i);
      i++;
    }
  return (0);
}
