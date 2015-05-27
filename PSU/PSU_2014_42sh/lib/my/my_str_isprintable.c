/*
** my_str_isprintable.c for my_str_isprintable in /home/dupard_e/rendu/Piscine_C_J06/ex_14
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 12:36:42 2014 Erwan Dupard
** Last update Mon Oct 20 15:36:16 2014 Erwan Dupard
*/

int		is_printable_char(char c)
{
  if (c > 32 && c < 127)
    return (1);
  return (0);
}

int		my_str_isprintable(char *str)
{
  if (*str == 0)
    return (1);
  while (*str != 0)
    {
      if (!is_printable_char(*str))
	return (0);
      str++;
    }
  return (1);
}
