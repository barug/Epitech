/*
** my_str_isnum.c for my_str_isnum in /home/dupard_e/rendu/Piscine_C_J06/ex_11
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 12:21:15 2014 Erwan Dupard
** Last update Mon Oct 20 15:37:28 2014 Erwan Dupard
*/

int		is_num_char(char c)
{
  if (c >= '0' && c <='9')
    return (1);
  return (0);
}

int		my_str_isnum(char *str)
{
  if (*str == 0)
    return (1);
  while (*str != 0)
    {
      if (!is_num_char(*str))
	return (0);
      str++;
    }
  return (1);
}
