/*
** my_printf.h for my_printf in /home/dupard_e/rendus/PSU_2013_my_printf
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Nov  5 14:40:17 2014 Erwan Dupard
** Last update Mon Nov 10 17:35:03 2014 Erwan Dupard
*/

#ifndef _MY_PRINTF_H_
# define _MY_PRINTF_H_

#include <stdarg.h>

# define ABS(n) (n > 0 ? n : -n)

typedef struct	s_form
{
  char		c;
  int		(*f)(va_list p);
}		t_form;

int		my_printf(const char *format, ...);
int		corr(va_list p, char f);
int		get_int_len(int n);
int		check(va_list p, t_form formats[], char f);

#endif	/* !_MY_PRINTF_H_ */
