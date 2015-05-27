/*
** my_strncpy.c for d in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:45:52 2014 barthelemy gouby
** Last update Mon Oct 20 21:45:54 2014 barthelemy gouby
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i] != 0)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
}
