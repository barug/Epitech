/*
** my_strstr.c for my_strstr in /home/dupard_e/rendu/Piscine_C_J06/ex_4
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 09:13:49 2014 Erwan Dupard
** Last update Mon Oct 20 15:35:54 2014 Erwan Dupard
*/

int		my_strlen(char *str);

char		*my_strstr(char *str, char *to_find)
{
  int		c;
  int		len;
  int		i;
  int		j;

  j = 0;
  i = 0;
  len = my_strlen(to_find);
  c = 0;
  while (str[i] != '\0')
    {
      while (str[i] == to_find[j] && to_find[j] != '\0')
	{
	  c++;
	  i++;
	  j++;
	}
      if (c == len)
	return (&str[i - len]);
      c = 0;
      i++;
      j = 0;
    }
  return (0);
}
