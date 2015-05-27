/*
** include.h for include in /home/barthe_g/rendu/printf
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Nov 12 13:05:21 2014 barthelemy gouby
** Last update Sun Nov 16 18:27:47 2014 barthelemy gouby
*/

#ifndef _INCLUDE_H_
#define _INCLUDE_H_

int     put_int(va_list ap);
int     put_str(va_list ap);
int     put_str_S(va_list ap);
int     put_unsigned_o(va_list ap);
int     put_unsigned_u(va_list ap);
int     put_unsigned_x(va_list ap);
int     put_unsigned_X(va_list ap);
int     put_unsigned_b(va_list ap);
int     put_int_c(va_list ap);
int     put_void(va_list ap);

#endif /* _INCLUDE_H_ */

