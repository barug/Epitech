/*
** get_files2.c for get_files2 in /home/barthe_g/rendu/PSU_2014_my_ls
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Nov 30 22:34:33 2014 barthelemy gouby
** Last update Sun Nov 30 23:14:23 2014 barthelemy gouby
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

t_file_info     make_file_info(struct dirent *entry, char *pathname)
{
  t_file_info   file_info;
  struct stat   sb;
  char          *new_pathname;

  file_info.entry = entry;
  new_pathname = add_str_m(pathname, entry->d_name);
  stat(new_pathname, &sb);
  file_info.sb = sb;
  free(new_pathname);
  return (file_info);
}

t_file_info     **fill_info_array(t_file_info **file_info_array,
				  char *pathname)
{
  DIR           *dirp;
  struct dirent *entry;
  int           i;
  t_file_info   file_info;

  i = 0;
  if ((dirp = opendir(pathname)) == NULL)
    return (NULL);
  while ((entry = readdir(dirp)) != NULL)
    if (entry->d_name[0] != '.')
      {
	file_info_array[i] = malloc(sizeof(t_file_info));
	if (file_info_array[i] == NULL)
	  return (NULL);
	*(file_info_array[i]) = make_file_info(entry, pathname);
	i++;
      }
  file_info_array[i] = NULL;
  i = 0;
  return (file_info_array);
}

t_file_info     **make_info_array(char *pathname)
{
  DIR           *dirp;
  struct dirent *entry;
  t_file_info   **file_info_array;
  int           i;

  i = 0;
  if ((dirp = opendir(pathname)) == NULL)
    return (NULL);
  while ((entry = readdir(dirp)) != NULL)
    if (entry->d_name[0] != '.')
      i++;
  closedir(dirp);
  file_info_array = malloc((i + 1) * sizeof(t_file_info));
  if (file_info_array == NULL)
    return (NULL);
  file_info_array = fill_info_array(file_info_array, pathname);
  return (file_info_array);
}

int     my_strcmp_m(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}
