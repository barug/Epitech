/*
** my_str_isprintable.c for isp in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:43:37 2014 barthelemy gouby
** Last update Mon Oct 20 21:43:38 2014 barthelemy gouby
*/

int	my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] < 32 || str[i] > 176)
        return (0);
      i = i + 1;
    }
  return (1);
}
