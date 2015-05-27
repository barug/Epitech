/*
** my_strcat.c for d in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:41:45 2014 barthelemy gouby
** Last update Mon Oct 20 21:41:46 2014 barthelemy gouby
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int   a;

  i = 0;
  a = 0;
  while (dest[i] != 0)
    i = i + 1;
  while (src[a] != 0)
    {
      dest[i] = src[a];
      i = i + 1;
      a = a + 1;
    }
  dest[i] = 0;
}

