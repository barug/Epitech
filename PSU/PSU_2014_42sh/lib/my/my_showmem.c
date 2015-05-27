/*
** my_showmem.c for my_showmem in /home/dupard_e/rendu/Piscine_C_J06/ex_18
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 20:33:25 2014 Erwan Dupard
** Last update Sat May 23 15:03:12 2015 Erwan Dupard
*/

#include "./my.h"

int		my_count_nbr_len(int nbr)
{
  int		i;

  i = 0;
  if (nbr == 0)
    return (0);
  while (nbr != 0)
    {
      nbr = nbr / 10;
      i++;
    }
  return (i);
}

int		put_addr_eight(int nbr)
{
  int		len;
  int		i;

  i = 0;
  len = my_count_nbr_len(nbr);
  if (nbr == 0)
    {
      my_putstr("00000000:");
      return (0);
    }
  while (i != (8 - len))
    {
      my_putchar('0');
      ++i;
    }
  my_put_nbr(nbr);
  my_putchar(':');
  return (0);
}

int		put_hex_chars(char *str, int n)
{
  int		i;
  int		j;

  i = n;
  j = 0;
  while (i != n + 16)
    {
      if (j == 2)
	{
	  my_putchar(' ');
	  j = 0;
	}
      if (i >= my_strlen(str))
	  my_putstr("  ");
      else
	{
	  if (str[i] >= 0x1 && str[i] <= 0xF)
	    my_putchar('0');
	  my_putnbr_base(str[i], "0123456789ABCDEF");
	}
      j++;
      i++;
    }
  return (i);
}

int		put_ascii_chars(char *str, int c)
{
  int		i;

  i = c;
  while (i != (c + 16))
    {
      if (i >= my_strlen(str))
	return (0);
      if (is_printable_char(str[i]))
	my_putchar(str[i]);
      else
	my_putchar('.');
      i++;
    }
  return (0);
}

int		my_showmem(char *str, int size)
{
  int		i;
  int		c;
  int		line;

  i = 0;
  line = 0;
  c = 0;
  while (line != (size / 16) + 1)
    {
      put_addr_eight(line * 10);
      my_putchar(' ');
      i = put_hex_chars(str, i);
      my_putchar(' ');
      c = put_ascii_chars(str, c);
      my_putchar('\n');
      ++line;
    }
  return (0);
}
