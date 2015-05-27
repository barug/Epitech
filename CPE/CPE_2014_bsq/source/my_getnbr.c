/*
** my_getnbr.c for my_getnbr.c in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:35:56 2014 barthelemy gouby
** Last update Fri Nov 14 16:39:58 2014 barthelemy gouby
*/

int	my_getnbr(char *str)
{
  int	i;
  int	r;
  int	n;

  i = 0;
  r = 0;
  n = 1;
  while (str[i] != 0)
    {
      if (str[i] == '-')
	n = n * (- 1);
      if (str[i] >= '0' && str[i] <= '9')
	{
	  r = r * 10 + (str[i] -48);
	  if (r < 0)
	    return (0);
	}
      if ((str[i] != '-' && str[i] != '+' && str[i] < 48) || str[i] > 57)
	return (r * n);
      i = i + 1;
    }
  return (r * n);
}
