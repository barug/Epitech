/*
** my_str_isalpha.c for my_str_isalpha in /home/dupard_e/rendu/Piscine_C_J06/ex_10
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 12:02:38 2014 Erwan Dupard
** Last update Mon Oct 20 15:36:31 2014 Erwan Dupard
*/

int		is_alph_char(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

int		my_str_isalpha(char *str)
{
  if (*str == 0)
    return (1);
  while (*str != 0)
    {
      if (!is_alph_char(*str))
	return (0);
      str++;
    }
  return (1);
}
