/*
** get_files3.c for get_files3 in /home/barthe_g/rendu/PSU_2014_my_ls
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Nov 30 22:36:48 2014 barthelemy gouby
** Last update Sun Nov 30 23:14:32 2014 barthelemy gouby
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include "my.h"
#include "file_info.h"
#include "option_struct.h"

void    read_normal(t_file_info **file_info_array, t_option_struct *option_struct)
{
  int   i;

  i = 0;
  while (file_info_array[i] != NULL)
    {
      if (option_struct->l == 1)
        if_l_option(&(file_info_array[i]->sb));
      my_printf("%s", file_info_array[i]->entry->d_name);
      my_putchar('\n');
      i++;
    }
}

void    read_reverse(t_file_info **file_info_array, t_option_struct *option_struct)
{
  int   i;

  i = 0;
  while (file_info_array[i] != NULL)
    i++;
  i--;
  while (i >= 0)
    {
      if (option_struct->l == 1)
        if_l_option(&(file_info_array[i]->sb));
      my_printf("%s", file_info_array[i]->entry->d_name);
      my_putchar('\n');
      i--;
    }
}

int     get_files_list(char *pathname, t_option_struct *option_struct)
{
  char          *new_pathname;
  t_file_info   **file_info_array;
  int           i;

  file_info_array = make_info_array(pathname);
  if (file_info_array == NULL)
    return (0);
  if (option_struct->t == 1)
    file_info_array = sort_time_info_array(file_info_array);
  else
    file_info_array = sort_name_info_array(file_info_array);
  if (option_struct->r == 1)
    read_reverse(file_info_array, option_struct);
  else
    read_normal(file_info_array, option_struct);
  i = 0;
  while (file_info_array[i] != NULL)
    free(file_info_array[i++]);
  free(file_info_array);
  return (0);
}
