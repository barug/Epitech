/*
** my_strupcase.c for my_strupcase in /home/dupard_e/rendu/Piscine_C_J06/ex_7
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 09:30:32 2014 Erwan Dupard
** Last update Mon Oct  6 18:53:03 2014 Erwan Dupard
*/

char		*my_strupcase(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      i++;
    }
  return (str);
}
