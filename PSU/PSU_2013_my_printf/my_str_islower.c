/*
** my_str_islower.c for trisi in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:42:53 2014 barthelemy gouby
** Last update Mon Oct 20 21:42:56 2014 barthelemy gouby
*/

int	my_str_islower(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] < 'a' || str[i] > 'z')
        return (0);
      i = i + 1;
    }
  return (1);
}
