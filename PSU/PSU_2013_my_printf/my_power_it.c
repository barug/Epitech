/*
** my_power_it.c for my_power_it in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:37:25 2014 barthelemy gouby
** Last update Mon Oct 20 21:37:30 2014 barthelemy gouby
*/

int	my_power_it(int nb, int power)
{
  int	a;
  int	b;

  a = 1;
  b = nb;
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  while (a < power)
    {
      b = b * nb;
      a = a + 1;
    }
  return (b);
}
