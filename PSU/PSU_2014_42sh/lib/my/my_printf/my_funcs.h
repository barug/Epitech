/*
** my_funcs.h for my_printf in /home/dupard_e/rendus/PSU_2013_my_printf
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Nov  5 21:32:38 2014 Erwan Dupard
** Last update Sun Nov 16 13:06:55 2014 Erwan Dupard
*/

#ifndef _MY_FUNCS_H_
# define _MY_FUNCS_H_

#include <stdarg.h>

int		my_deci(va_list p);
int		my_lhex(va_list p);
int		my_Lhex(va_list p);
int		my_hexp(va_list p);
int		my_strp(va_list p);
int		my_spec(va_list p);
int		my_bin(va_list p);
int		my_char(va_list p);
int		my_octal(va_list p);
int		my_unsigned(va_list p);
int		my_eenn(va_list p, int j, int *ok);

#endif	/* !_MY_FUNCS_H_ */
