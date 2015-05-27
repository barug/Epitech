/*
** my_getnbr_base.c for my_getnbr_base in /home/dupard_e/rendu/my_funcs/others
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Oct  8 17:28:27 2014 Erwan Dupard
** Last update Mon Oct 27 15:51:31 2014 Erwan Dupard
*/

int		my_strlen(char *str);

int		is_in_base(char c, char *base)
{
  int		j;

  j = 0;
  while (base[j] != 0)
    {
      if (c == base[j])
	return (1);
      j++;
    }
  return (0);
}

int		get_nbr_index(char *nbr, int i, char *base)
{
  int		c;

  c = 0;
  while (base[c] != 0)
    {
      if (base[c] == nbr[i])
	return (c);
      c++;
    }
  return (0);
}

int		calc_nbr(char *nbr, int i, char *base)
{
  int		c;
  int		nbr_index;
  int		base_n;

  base_n = my_strlen(base);
  c = 0;
  while (is_in_base(nbr[i], base))
    {
      nbr_index = get_nbr_index(nbr, i, base);
      c = c * base_n;
      c = c + nbr_index;
      i++;
    }
  return (c);
}

int		my_getnbr_base(char *nbr, char *base)
{
  int		less_c;
  int		i;
  int		isneg;
  int		c;

  i = 0;
  isneg = 0;
  less_c = 0;
  while ((nbr[i] == '+' || nbr[i] == '-') && nbr[i] != 0)
    {
      if (nbr[i] == '-')
	++less_c;
      ++i;
    }
  if (less_c % 2 == 1)
    isneg = 1;
  c = calc_nbr(nbr, i, base);
  if (isneg)
    c = -c;
  return (c);
}
