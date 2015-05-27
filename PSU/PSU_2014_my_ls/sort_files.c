/*
** sort_files.c for sort_files in /home/barthe_g/rendu/PSU_2014_my_ls
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Nov 30 22:35:56 2014 barthelemy gouby
** Last update Sun Nov 30 23:15:00 2014 barthelemy gouby
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

t_file_info **sort_name_info_array(t_file_info **file_info_array)
{
  int           i;
  int           position;
  int           indic;
  t_file_info   *buffer;

  i = 0;
  position = 0;
  indic = 1;
  while (file_info_array[position] != NULL)
    {
      indic = 0;
      i = position;
      while (file_info_array[i] != NULL && indic != 1)
        {
          if (strcmp(file_info_array[position]->entry->d_name,
		     file_info_array[i]->entry->d_name) > 0)
            {
              buffer = file_info_array[position];
              file_info_array[position] = file_info_array[i];
              file_info_array[i] = buffer;
              indic = 1;
            }
          i++;
        }
      file_info_array[i] == NULL ? position++ : 0;
    }
  return (file_info_array);
}

t_file_info     **sort_time_info_array(t_file_info **file_info_array)
{
  int           i;
  int           position;
  int           indic;
  t_file_info   *buffer;
  time_t        time_position;
  time_t        time_i;

  i = 0;
  position = 0;
  indic = 1;
  while (file_info_array[position] != NULL)
    {
      indic = 0;
      i = position;
      while (file_info_array[i] != NULL && indic != 1)
        {
          if (file_info_array[position]->sb.st_mtime
	      < file_info_array[i]->sb.st_mtime)
            {
              buffer = file_info_array[position];
              file_info_array[position] = file_info_array[i];
              file_info_array[i] = buffer;
              indic = 1;
            }
          i++;
        }
      file_info_array[i] == NULL ? position++ : 0;
    }
  return (file_info_array);
}
