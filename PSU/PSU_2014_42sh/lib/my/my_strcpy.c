/*
** my_strcpy.c for my_strcpy in /home/dupard_e/rendu/Piscine_C_J06/ex_1
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Oct  6 08:54:07 2014 Erwan Dupard
** Last update Tue Nov 18 14:54:30 2014 Erwan Dupard
*/

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}
