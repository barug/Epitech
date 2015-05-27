/*
** my_str_islower.c for my_str_islower in /home/dupard_e/rendu/Piscine_C_J06/ex_12
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 12:32:03 2014 Erwan Dupard
** Last update Mon Oct 20 15:37:06 2014 Erwan Dupard
*/

int		is_lower_char(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

int		my_str_islower(char *str)
{
  if (*str == 0)
    return (1);
  while (*str != 0)
    {
      if (!is_lower_char(*str))
	return (0);
      str++;
    }
  return (1);
}
