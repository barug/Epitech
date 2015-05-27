/*
** my_ls.c for my_ls in /home/barthe_g/rendu/PSU_2014_my_ls
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Nov 21 12:22:18 2014 barthelemy gouby
** Last update Sun Nov 30 23:14:10 2014 barthelemy gouby
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
#include "my_ls.h"

int	recursivity(char *pathname, t_option_struct *option_struct)
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
  return (0);
}

char    **add_array_entry(char **tab, char *array_entry)
{
  int   i;
  char  **new_tab;

  i = 0;
  while (tab[i] != NULL)
    i++;
  new_tab = malloc((i + 2) * sizeof(char*));
  if (new_tab == NULL)
    return (NULL);
  i = 0;
  while (tab[i] != NULL)
    {
      new_tab[i] = tab[i];
      i++;
    }
  new_tab[i] = array_entry;
  i++;
  new_tab[i] = NULL;
  return (new_tab);
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
      if (option_str[i] != 'l' && option_str[i] != 'r' &&
	  option_str[i] != 't' && option_str[i] != 'R' && option_str[i] != 'd')
	return (1);
      i++;
    }
  return (0);
}

int	get_option(int argc, char **argv, t_option_struct *option_struct)
{
  int			i;

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
