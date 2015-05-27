/*
** build_my_args.c for build_my_args in /home/aknin_k/rendu/tek1/syst_unix/42sh/PSU_2014_42sh/karine/sources/parser
** 
** Made by karine aknin
** Login   <aknin_k@epitech.net>
** 
** Started on  Wed May 20 00:41:21 2015 karine aknin
** Last update Sun May 24 17:10:20 2015 karine aknin
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

int	change_global_bis()
{
  my_fprintf(2, "[-] Failled to malloc()..\n");
  g_malloc = 1;
  return (EXIT_FAILED);
}

int	find_first_sequence(char **input_tab, int *n)
{
  if (input_tab[*n][0] == ';')
    return (1);
  else if (input_tab[*n][0] == '|')
    return (1);
  else if (input_tab[*n][0] == '&' && input_tab[*n][1] == '&')
    return (1);
  return (0);
}

void	find_redirections(char **input_tab, t_command **command_sequence,
			  int *n, int i)
{
  (*command_sequence)[i].output = NULL;
  (*command_sequence)[i].input = NULL;
  (*command_sequence)[i].append = NULL;
  (*command_sequence)[i].endread = NULL;
  while (input_tab[*n] != NULL && (find_first_sequence(input_tab, n) == 0))
    {
      if (my_strcmp(input_tab[*n], "<") == 0)
	(*command_sequence)[i].input = input_tab[*n + 1];
      if (my_strcmp(input_tab[*n], ">") == 0)
	(*command_sequence)[i].output = input_tab[*n + 1];
      if (my_strcmp(input_tab[*n], ">>") == 0)
	(*command_sequence)[i].append = input_tab[*n + 1];
      if (my_strcmp(input_tab[*n], "<<") == 0)
	(*command_sequence)[i].endread = input_tab[*n + 1];
      (*n)++;
    }
}

int	check_sep_bis(char **input_tab, int i)
{
  if (input_tab[i][0] == ';')
    return (1);
  else if (input_tab[i][0] == '|')
    return (1);
  else if (input_tab[i][0] == '&' && input_tab[i][1] == '&')
    return (1);
  else if (input_tab[i][0] == '<')
    return (1);
  else if (input_tab[i][0] == '>')
    return (1);
  return (0);
}

int	make_args(char **input_tab, int *n, t_command *command_node)
{
  int	i;

  i = *n;
  if (input_tab[i] != NULL && (check_sep_bis(input_tab, i) == 1))
    return (-1);
  while (input_tab[i] != NULL && (check_sep_bis(input_tab, i) == 0))
    i++;
  if (((*command_node).args = malloc(((i - *n) + 1) * sizeof(char*))) == NULL)
    return (change_global_bis());
  i = 0;
  while (input_tab[*n] != NULL && (check_sep_bis(input_tab, *n) == 0))
    {
      (*command_node).args[i] = input_tab[*n];
      i++;
      (*n)++;
    }
  (*command_node).args[i] = NULL;
  return (0);
}
