/*
** my_str_isalpha.c for fe in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:42:35 2014 barthelemy gouby
** Last update Mon Oct 20 21:42:36 2014 barthelemy gouby
*/

int	my_str_isalpha(char *str)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (str[i] != 0)
    {
      if (str[i] < 64 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
	return (0);
      i = i + 1;
    }
  return (1);
}
