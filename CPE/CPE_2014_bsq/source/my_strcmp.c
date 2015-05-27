/*
** my_strcmp.c for my_strcmp in /home/barthe_g/rendu/Piscine_C_J06
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct  6 15:48:36 2014 gouby barthelemy
** Last update Mon Oct 20 21:15:40 2014 barthelemy gouby
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}
