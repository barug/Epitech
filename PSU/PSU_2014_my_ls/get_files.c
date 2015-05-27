/*
** get_files.c for get_files in /home/barthe_g/rendu/PSU_2014_my_ls
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Nov 30 22:32:09 2014 barthelemy gouby
** Last update Sun Nov 30 23:13:59 2014 barthelemy gouby
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

char    *add_str_m(char *str1, char *str2)
{
  int   a;
  int   b;
  int   i;
  char  *output_str;

  i = 0;
  a = my_strlen(str1);
  b = my_strlen(str2);
  output_str = malloc ((a + b + 2) * sizeof(char));
  if (output_str == NULL)
    return (NULL);
  while (i < a)
    {
      output_str[i] = str1[i];
      i++;
    }
  output_str[i++] = '/';
  a++;
  while ((i - a) < b)
    {
      output_str[i] = str2[i - a];
      i++;
    }
  output_str[i] = '\0';
  return (output_str);
}

int     put_file_rights(struct stat *sb)
{
  sb->st_mode & S_IFDIR ? my_putchar('d') : my_putchar('-');
  sb->st_mode & S_IRUSR ? my_putchar('r') : my_putchar('-');
  sb->st_mode & S_IWUSR ? my_putchar('w') : my_putchar('-');
  sb->st_mode & S_IXUSR ? my_putchar('x') : my_putchar('-');
  sb->st_mode & S_IRGRP ? my_putchar('r') : my_putchar('-');
  sb->st_mode & S_IWGRP ? my_putchar('w') : my_putchar('-');
  sb->st_mode & S_IXGRP ? my_putchar('x') : my_putchar('-');
  sb->st_mode & S_IROTH ? my_putchar('r') : my_putchar('-');
  sb->st_mode & S_IWOTH ? my_putchar('w') : my_putchar('-');
  sb->st_mode & S_IXOTH ? my_putchar('x') : my_putchar('-');
  return (0);
}

int     get_user_and_group(struct stat *sb)
{
  struct passwd *ps;
  struct group  *gp;

  ps = getpwuid(sb->st_uid);
  my_printf(" %s", ps->pw_name);
  gp = getgrgid(sb->st_gid);
  my_printf(" %s", gp->gr_name);
  return (0);
}

int     if_l_option(struct stat *sb)
{
  char          *time;

  put_file_rights(sb);
  my_printf(" %i", sb->st_nlink);
  get_user_and_group(sb);
  my_printf(" %i", sb->st_size);
  time = ctime(&(sb->st_mtime));
  time = &time[4];
  time [12] = 0;
  my_printf(" %s", time);
  my_putchar(' ');
  return (0);
}
