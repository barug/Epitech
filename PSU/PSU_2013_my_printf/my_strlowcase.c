/*
** my_strlowcase.c for d in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:44:31 2014 barthelemy gouby
** Last update Mon Oct 20 21:44:32 2014 barthelemy gouby
*/

char	*my_strlowcase(char *str)
{
  int   i;

  while (str[i] != 0)
    {
      if (str[i] < 90 && str[i] > 65)
        str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
