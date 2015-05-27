/*
** my_strcpy.c for d in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:42:15 2014 barthelemy gouby
** Last update Mon Oct 20 21:42:16 2014 barthelemy gouby
*/

char	*my_strcpy(char *dest, char *src)
{
  int	size;

  size = 0;
  while (src[size] != 0)
    {
      dest[size] = src[size];
      size = size + 1;
    }
  return (dest);
}
