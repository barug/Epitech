/*
** my_strlen.c for d in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:44:16 2014 barthelemy gouby
** Last update Tue Mar  3 11:12:48 2015 barthelemy gouby
*/

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    a = a + 1;
  return (a);
}
