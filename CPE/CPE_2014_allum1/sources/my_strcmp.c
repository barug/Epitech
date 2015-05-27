/*
** my_strcmp.c for my_strcmp in /home/barthe_g/rendu/Piscine_C_J06
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct  6 15:48:36 2014 gouby barthelemy
** Last update Fri Feb 13 17:23:22 2015 barthelemy gouby
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1[0] == '\0' || s2[0] =='\0')
    return (-1);
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}
