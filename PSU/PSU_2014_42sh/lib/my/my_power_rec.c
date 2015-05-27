/*
** my_power_rec.c for my_power_rec in /home/dupard_e/rendu/Piscine_C_J05
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Oct  3 15:23:41 2014 Erwan Dupard
** Last update Tue Oct  7 11:20:16 2014 Erwan Dupard
*/

int		my_power_rec(int nb, int power)
{
  int		m;

  if (power == 0)
    return (1);
  if (power % 2 == 0)
    {
      m = my_power_rec(nb, power / 2);
      return (m * m);
    }
  else
    {
      if ((nb * my_power_rec(nb, power - 1)) >= 2147483647 ||
	  (nb * my_power_rec(nb, power - 1)) <= -2147483647)
	return (0);
      return (nb * my_power_rec(nb, power - 1));
    }
}
