/*
** my_put_nbr.c for my_put_nbr in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:38:26 2014 barthelemy gouby
** Last update Fri Nov 14 16:42:13 2014 barthelemy gouby
*/

int	my_put_nbr(int nb)
{
  int	div;
  int	lenght;

  lenght = 0;
  div = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  while (nb / div > 9)
    {
      div = div * 10;
    }
  while (div > 0)
    {
      my_putchar((((nb - (nb % div)) / div)) + 48);
      nb = nb % div;
      div = div / 10;
      lenght++;
    }
  return (lenght);
}
