/*
** my_putstr.c for putstr in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:39:03 2014 barthelemy gouby
** Last update Fri Nov 14 16:42:27 2014 barthelemy gouby
*/

int	my_putstr(char *str)
{
  int	a;
  int	length;

  a = 0;
  length = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      length++;
      a  = a + 1;
    }
  return (length);
}
