/*
** my_strcapitalize.c for capitalize in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:41:25 2014 barthelemy gouby
** Last update Fri Nov 14 16:08:32 2014 barthelemy gouby
*/

char	*my_strcapitalize(char *str)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (str[i] != 0)
    {
      if (a == 1 && (str[i] > 64 && str[i] < 91))
	str[i] = str[i] + 32;
      if (str[i] > 96 && str[i] < 123 && a == 0)
	{
	  str[i] = str[i] - 32;
	  a = 1;
	}
      if ((str[i] < 58 && str[i] > 47) ||(str[i] > 64 && str[i] < 91))
	a = 1;
      if (str[i] < 48 || (str[i] > 58 &&  str[i] < 65)
	  || (str[i] > 90 && str[i] < 97) || (str[i] > 122 && str[i] < 127))
	a = 0;
      i = i + 1;
    }
  return (str);
}
