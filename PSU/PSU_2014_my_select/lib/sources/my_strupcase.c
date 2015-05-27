/*
** my_strupcase.c for r in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:46:25 2014 barthelemy gouby
** Last update Mon Oct 20 21:46:27 2014 barthelemy gouby
*/

char	*my_strupcase(char *str)
{
  int	i;

  while (str[i] != 0)
    {
      if (str[i] < 122 && str[i] > 97)
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
