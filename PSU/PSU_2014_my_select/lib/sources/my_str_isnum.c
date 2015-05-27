/*
** my_str_isnum.c for isnum in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:43:20 2014 barthelemy gouby
** Last update Mon Oct 20 21:43:21 2014 barthelemy gouby
*/

int	my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] < 48 || str[i] > 57)
        return (0);
      i = i + 1;
    }
  return (1);
}
