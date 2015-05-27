/*
** my_ls.c for my_ls in /home/barthe_g/rendu/PSU_2014_my_ls
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Nov 21 12:22:18 2014 barthelemy gouby
** Last update Fri Nov 28 12:55:02 2014 barthelemy gouby
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
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

int	put_file_rights(struct stat *sb)
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

int	get_user_and_group(struct stat *sb)
{
  struct passwd *ps;
  struct group  *gp;

  ps = getpwuid(sb->st_uid);
  my_printf(" %s", ps->pw_name);
  gp = getgrgid(sb->st_gid);
  my_printf(" %s", gp->gr_name);
  return (0);
}

int	if_l_option(struct stat *sb)
{
  char		*time;

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

t_file_info	make_file_info(struct dirent *entry, char *pathname)
{
  t_file_info	file_info;
  struct stat	sb;
  char		*new_pathname;

  file_info.entry = entry;
  new_pathname = add_str_m(pathname, entry->d_name);
  stat(new_pathname, &sb);
  file_info.sb = sb;
  free(new_pathname);
  return (file_info);
}

t_file_info	**fill_info_array(t_file_info **file_info_array, char *pathname)
{
  DIR           *dirp;
  struct dirent *entry;
  int           i;
  t_file_info	file_info;

  i = 0;
  if ((dirp = opendir(pathname)) == NULL)
    return (NULL);
  while ((entry = readdir(dirp)) != NULL)
      if (entry->d_name[0] != '.')
	{
	  file_info_array[i] = malloc(sizeof(t_file_info));
	  *(file_info_array[i]) = make_file_info(entry,pathname);
	  i++;
	}
  file_info_array[i] = NULL;
  i = 0;
  return (file_info_array);
}

t_file_info	**make_info_array(char *pathname)
{
  DIR		*dirp;
  struct dirent *entry;
  t_file_info	**file_info_array;
  int		i;

  i = 0;
  if ((dirp = opendir(pathname)) == NULL)
    return (NULL);
  while ((entry = readdir(dirp)) != NULL)
    if (entry->d_name[0] != '.')
      i++;
  closedir(dirp);
  file_info_array = malloc((i + 1) * sizeof(t_file_info));
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

t_file_info **sort_name_info_array(t_file_info **file_info_array)
{
  int		i;
  int		position;
  int		indic;
  t_file_info	*buffer;

  i = 0;
  position = 0;
  indic = 1;
  while (file_info_array[position] != NULL)
    {
      indic = 0;
      i = position;
      while (file_info_array[i] != NULL && indic != 1)
	{
	  if (strcmp(file_info_array[position]->entry->d_name,file_info_array[i]->entry->d_name) > 0)
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

t_file_info	**sort_time_info_array(t_file_info **file_info_array)
{
  int           i;
  int           position;
  int           indic;
  t_file_info	*buffer;
  time_t	time_position;
  time_t	time_i;

  i = 0;
  position = 0;
  indic = 1;
  while (file_info_array[position] != NULL)
    {
      indic = 0;
      i = position;
      while (file_info_array[i] != NULL && indic != 1)
        {
          if (file_info_array[position]->sb.st_mtime < file_info_array[i]->sb.st_mtime)
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

void	read_normal(t_file_info **file_info_array, t_option_struct *option_struct)
{
  int	i;

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

void	read_reverse(t_file_info **file_info_array, t_option_struct *option_struct)
{
  int	i;

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

int	get_files_list(char *pathname, t_option_struct *option_struct)
{
  char		*new_pathname;
  t_file_info	**file_info_array;
  int		i;

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

int	recursivity(char *pathname,t_option_struct *option_struct)
{
  DIR		*dirp;
  struct dirent *entry;
  char		*new_pathname;

  if ((dirp = opendir(pathname)) == NULL)
    return (1);
  while ((entry = readdir(dirp)) != NULL)
    {
      if (entry->d_name[0] != '.' && entry->d_type == 4)
	{
	  new_pathname = add_str_m(pathname, entry->d_name);
	  my_printf("\n%s:\n", new_pathname);
	  get_files_list(new_pathname, option_struct);
	  recursivity(new_pathname, option_struct);
	  free(new_pathname);
	}
    }
  closedir(dirp);
  return(0);
}

char    **add_array_entry(char **tab, char *array_entry)
{
  int   i;
  char  **new_tab;

  i = 0;
  while (tab[i] != NULL)
    i++;
  new_tab = malloc((i + 2) * sizeof(char*));
  i = 0;
  while (tab[i] != NULL)
    new_tab[i] = tab[i++];
  new_tab[i] = array_entry;
  i++;
  new_tab[i] = NULL;
  return(new_tab);
}

int	analyze_option(t_option_struct *option_struct, char *option_str)
{
  int	i;

  i = 1;
  while (option_str[i] != '\0')
    {
      option_str[i] == 'l' ? option_struct->l = 1 : 0;
      option_str[i] == 'r' ? option_struct->r = 1 : 0;
      option_str[i] == 't' ? option_struct->t = 1 : 0;
      option_str[i] == 'R' ? option_struct->R = 1 : 0;
      option_str[i] == 'd' ? option_struct->d = 1 : 0;
      if (option_str[i] != 'l' && option_str[i] != 'r' && option_str[i] != 't' && option_str[i] != 'R' && option_str[i] != 'd')
	return (1);
      i++;
    }
  return (0);
}

int	get_option(int argc, char **argv, t_option_struct *option_struct)
{
  int			i;
  int			a;

  i = 1;
  if (argc > 1)
      while (i != argc)
	{
	  if (argv[i][0] == '-')
	    {
	      if (analyze_option(option_struct, argv[i]) == 1)
		return (1);
	    }
	  else 
	    option_struct->pathname = add_array_entry(option_struct->pathname, argv[i]);
	  i++;
	}
  return (0);
}

int	main(int argc, char **argv)
{
  int			i;
  t_option_struct	option_struct;

  i = 0;
  option_struct.pathname = malloc(sizeof(char*));
  option_struct.pathname[0] = NULL;
  if (get_option(argc, argv, &option_struct) == 1)
    {
      my_printf("\nmy_ls: invalid option\n");
      return (1);
    }
  if (option_struct.pathname[0] != NULL)
    while (option_struct.pathname[i] != NULL)
      {
	my_printf("\n%s:\n", option_struct.pathname[i]);
	get_files_list(option_struct.pathname[i], &option_struct);
	if (option_struct.R == 1)
	  recursivity(option_struct.pathname[i], &option_struct);
	i++;
      }
  else
    {
      get_files_list(".", &option_struct);
      if (option_struct.R == 1)
	recursivity(".", &option_struct);
    }
  return (0);
}
