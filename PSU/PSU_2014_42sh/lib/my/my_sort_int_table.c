/*
** my_sort_int_table.c for my_sort_params in /home/dupard_e/rendu/Piscine_C_J07
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Oct  7 14:08:24 2014 Erwan Dupard
** Last update Mon Oct 20 15:54:25 2014 Erwan Dupard
*/

int		my_swap(int *a, int *b);

int		my_sort_int_table(int *tab, int size)
{
  int		i;
  int		j;
  int		save;

  i = 0;
  j = 0;
  while (i != size)
    {
      save = tab[i];
      while (j != size)
	{
	  if (tab[j] < save)
	    my_swap(&tab[j], &save);
	}
    }
  return (0);
}
