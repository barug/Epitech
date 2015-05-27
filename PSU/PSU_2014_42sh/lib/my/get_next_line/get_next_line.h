/*
** get_next_line.h for get_next_line in /home/dupard_e/rendus/GetNexLine
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Nov 19 15:22:24 2014 Erwan Dupard
** Last update Tue Apr  7 19:17:51 2015 Erwan Dupard
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define BUFF_SIZE (4096)

#include "../my.h"

void            my_is_not_backn(char save[], char **tmp, char buffer[]);
int             init_gnl(int *i, char **tmp, char save[]);
char		*get_next_line(const int fd);
char		*my_realloc(char *buf, int size);
int		isbackn(char *str);
char		*my_strncat(char *dest, char *src, int n);

#endif	/* !GET_NEXT_LINE_H_ */
