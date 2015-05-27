/*
** my_strncmp.c for my_strncmp in /home/dupard_e/rendu/Piscine_C_J06
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 09:26:33 2014 Erwan Dupard
** Last update Tue Oct  7 19:16:12 2014 Erwan Dupard
*/

int		my_strncmp(char *s1, char *s2, int n)
{
  while (*s1 != 0 && *s2 != 0 && n != 0)
    {
      if (*s1 != *s2)
	return (*s1 - *s2);
      s1++;
      s2++;
      n--;
    }
  return (0);
}
