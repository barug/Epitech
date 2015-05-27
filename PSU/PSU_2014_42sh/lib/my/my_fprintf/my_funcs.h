/*
** my_funcs.h for my_printf in /home/dupard_e/rendus/PSU_2013_my_printf
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Nov  5 21:32:38 2014 Erwan Dupard
** Last update Tue Nov 18 16:29:11 2014 Erwan Dupard
*/

#ifndef _MY_FUNCS_H_
# define _MY_FUNCS_H_

#include <stdarg.h>

int		my_fdeci(int fd, va_list p);
int		my_flhex(int fd, va_list p);
int		my_fLhex(int fd, va_list p);
int		my_fhexp(int fd, va_list p);
int		my_fstrp(int fd, va_list p);
int		my_fspec(int fd, va_list p);
int		my_fbin(int fd, va_list p);
int		my_fchar(int fd, va_list p);
int		my_foctal(int fd, va_list p);
int		my_funsigned(int fd, va_list p);
int		my_feenn(va_list p, int j, int *ok);

#endif	/* !_MY_FFUNCS_H_ */
