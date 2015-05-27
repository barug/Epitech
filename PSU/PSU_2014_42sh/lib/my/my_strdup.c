/*
** my_strdup.c for libmy in /home/dupard_e/rendus/PSU_2014_my_ls/lib/my
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Nov 18 14:45:21 2014 Erwan Dupard
** Last update Thu Jan 22 16:10:00 2015 Erwan Dupard
*/

#include <stdlib.h>
#include "./my.h"

char		*my_strdup(char *str)
{
  char		*ret;

  if ((ret = malloc(my_strlen(str) * sizeof (*str) + 1)) == NULL)
    return (NULL);
  ret = my_strcpy(ret, str);
  return (ret);
}
