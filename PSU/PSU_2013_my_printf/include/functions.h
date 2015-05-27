/*
** functions.h for functions in /home/barthe_g/rendu/printf
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Nov 11 15:33:48 2014 barthelemy gouby
** Last update Wed Nov 12 17:40:05 2014 barthelemy gouby
*/

#ifndef _FUNCTIONS_H_
# define _FUNCTIONS_H_

typedef struct s_functions
{
  char	c;
  int	(*f)(va_list);
}t_functions;

#endif /* _FUNCTIONS_H_ */
