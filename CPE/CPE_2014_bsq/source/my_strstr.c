/*
** my_strstr.c for d in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:46:10 2014 barthelemy gouby
** Last update Mon Nov 17 14:58:04 2014 barthelemy gouby
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	n;
  int	a;
  char	*out;

  i = 0;
  n = 0;
  a = 0;
  while (to_find[n] != 0)
    n = n + 1;
  while (str[i] != 0)
    {
      while (str[i] == to_find[a] && a < n)
	{
	  a = a + 1;
	  i = i + 1;
	}
      if (a == n)
	{
	  out = &str[i - n];
	  return (out);
	}
      else
	a = 0;
      i = i + 1;
    }
  return (0);
}
