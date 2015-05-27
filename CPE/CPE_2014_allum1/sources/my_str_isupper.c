/*
** my_str_isupper.c for e in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:44:01 2014 barthelemy gouby
** Last update Mon Oct 20 21:44:02 2014 barthelemy gouby
*/

int	my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] < 'A' || str[i] > 'Z')
        return (0);
      i = i + 1;
    }
  return (1);
}
