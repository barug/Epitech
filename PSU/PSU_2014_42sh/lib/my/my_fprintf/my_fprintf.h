/*
** my_printf.h for my_printf in /home/dupard_e/rendus/PSU_2013_my_printf
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Nov  5 14:40:17 2014 Erwan Dupard
** Last update Tue Nov 18 16:04:07 2014 Erwan Dupard
*/

#ifndef _MY_PRINTF_H_
# define _MY_PRINTF_H_

#include <stdarg.h>

# define ABS(n) (n > 0 ? n : -n)

typedef struct	s_form
{
  char		c;
  int		(*f)(int fd, va_list p);
}		t_form;

int		my_fprintf(int fd, const char *format, ...);
int		corrf(int fd, va_list p, char f);
int		get_int_lenf(int n);
int		checkf(int fd, va_list p, t_form formats[], char f);

#endif	/* !_MY_PRINTF_H_ */
