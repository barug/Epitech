/*
** my_wordtab_len.c for libmy in /home/dupard_e/rendus/CPE_2014_lemin
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Apr 30 14:03:13 2015 Erwan Dupard
** Last update Fri May  1 15:51:34 2015 Erwan Dupard
*/

int		my_wordtab_len(char **c)
{
  int		i;

  i = 0;
  while (c[i])
    i++;
  return (i);
}
