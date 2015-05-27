/*
** my_isneg.c for isneg in /home/barthe_g/rendu/functions
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Oct 20 21:36:14 2014 barthelemy gouby
** Last update Mon Oct 20 21:36:16 2014 barthelemy gouby
*/

int my_isneg(int a)
{
  if (a <= 0)
    {
      my_putchar('N');
    }
  else
    {
      my_putchar('P');
    }
}
