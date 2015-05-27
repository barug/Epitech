/*
** my_is_prime.c for my_is_prime in /home/dupard_e/rendu/Piscine_C_J05
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Oct  3 19:38:20 2014 Erwan Dupard
** Last update Tue Oct  7 11:53:06 2014 Erwan Dupard
*/

int		my_is_prime(int nb)
{
  int		i;
  int		c;

  c = 0;
  i = 0;
  if (nb < 1)
    return (0);
  if (nb >= 2147483647)
    return (0);
  while (i != nb)
    {
      if (nb / i)
	  c++;
    }
  if (c == 2)
    return (1);
  else
    return (0);
}
