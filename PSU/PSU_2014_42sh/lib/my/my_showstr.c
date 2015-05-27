/*
** my_showstr.c for my_showstr in /home/dupard_e/rendu/Piscine_C_J06/ex_17
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 20:44:08 2014 Erwan Dupard
** Last update Mon Oct 20 15:55:36 2014 Erwan Dupard
*/

int		my_putnbr_base(int nb, char *base);
void		my_putchar(char c);
int		my_is_printable_char(char c);

int		my_showstr(char *str)
{
  while (*str != 0)
    {
      if (!my_is_printable_char(*str))
	{
	  my_putchar('\\');
	  my_putnbr_base(*str, "0123456789abcdef");
	}
      else
	my_putchar(*str);
      str++;
    }
  return (0);
}
