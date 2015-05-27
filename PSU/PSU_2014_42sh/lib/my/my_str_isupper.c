/*
** my_str_isupper.c for my_str_isupper in /home/dupard_e/rendu/Piscine_C_J06/ex_13
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 12:34:38 2014 Erwan Dupard
** Last update Mon Oct 20 15:54:08 2014 Erwan Dupard
*/

int		is_upper_char(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

int		my_str_islower(char *str)
{
  if (*str == 0)
    return (1);
  while (*str != 0)
    {
      if (!is_upper_char(*str))
	return (0);
      str++;
    }
  return (1);
}
