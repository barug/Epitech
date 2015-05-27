/*
** my_strncpy.c for my_strnspy in /home/dupard_e/rendu/Piscine_C_J06/ex_1
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 08:59:03 2014 Erwan Dupard
** Last update Fri Apr 10 13:14:09 2015 barthelemy gouby
*/

int		my_strlen(char *str);

char		*my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  while (src[i] != 0 && n != 0)
    {
      dest[i] = src[i];
      i++;
      n--;
    }
  dest[i] = '\0';
  return (dest);
}
