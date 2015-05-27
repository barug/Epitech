/*
** my_revstr.c for revstr in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:39:49 2014 barthelemy gouby
** Last update Fri Nov 14 16:39:40 2014 barthelemy gouby
*/

char	*my_revstr(char *str)
{
  char	stockstr;
  int	x;
  int	i;

  x = my_strlen(str) - 1;
  i = 0;
  while (x > i)
    {
      stockstr = str[i];
      str[i] = str[x];
      str[x] = stockstr;
      x = x - 1;
      i = i + 1;
    }
  return (str);
}
