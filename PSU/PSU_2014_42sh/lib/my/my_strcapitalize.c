/*
** my_strcapitalize.c for my_strcapitalize in /home/dupard_e/rendu/Piscine_C_J06/ex_9
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 10:19:01 2014 Erwan Dupard
** Last update Tue Oct  7 19:09:07 2014 Erwan Dupard
*/

char		*my_strlowcase(char *str);

char		*my_strcapitalize(char *str)
{
  int		i;

  i = 0;
  str = my_strlowcase(str);
  while (str[i] != 0)
    {
      if (i == 0)
	  if (str[i] >= 'a' && str[i] <= 'z')
	    str[i] = str[i] - 32;
      if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
	{
	  if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
	    str[i + 1] = str[i + 1] - 32;
	}
      i++;
    }
  return (str);
}
