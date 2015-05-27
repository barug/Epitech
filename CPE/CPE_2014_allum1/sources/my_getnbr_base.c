/*
** my_getnbr_base.c for getnbrbase in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:36:40 2014 barthelemy gouby
** Last update Mon Oct 20 21:36:44 2014 barthelemy gouby
*/

int	my_getnbr_base(char *str, char *base)
{
  int   i;
  int   a;
  int   size;
  int   puiss;
  int	neg;
  int   res;
  int	add;

  i = 0;
  a = 0;
  size = 0;
  puiss = 1;
  neg = 1;
  res = 0;
  if ( str[0] == 0 || base[0] == 0)
    return (0);
  while (base[i] != 0)
    {
      a = i + 1;
      while (base[a] != 0)
	{
	  if (base[a] == base[i])
	    return (0);
	  a = a + 1;
	}
      i = i + 1;
    }
  i = 0;
  a = 0;
  while (base[size] != 0)
    size = size + 1;
  while (str[i] != 0)
    {
      while (base[a] != str[i] && base[a] != 0)
	a = a + 1;
      if (a == size && str[a] != '-' && str[a] != '+')
	return (0);
      a = 0;
      i = i + 1;
    }
  
  while (str[i] != 0)
    {
      if (str[i] == '-')
	neg = neg * (- 1);
      i = i + 1;
    }
  i = i - 1;
  while (i >= 0)
    {
      while (str[i] != base[a] && a < size)
	a = a + 1;
      if (str[i] == base[a])
	add = a;
      else
	add = 0;
      res = res + (add * puiss);
      a = 0;
      puiss = puiss * size;
      i = i - 1;
    }
  return (res * neg);
}
