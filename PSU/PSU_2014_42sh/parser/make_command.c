/*
** make_command.c for make_command in /home/aknin_k/rendu/tek1/syst_unix/42sh/PSU_2014_42sh/karine/shell
** 
** Made by karine aknin
** Login   <aknin_k@epitech.net>
** 
** Started on  Mon May 18 16:50:19 2015 karine aknin
** Last update Sun May 24 15:59:29 2015 karine aknin
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "minishell.h"

t_command	*change_globale()
{
  printf("ERROR = Malloc failed\n");
  g_malloc = 1;
  return (NULL);
}

int	check_sep(char **input_tab, int *n)
{
  if (input_tab[*n][0] == ';')
    return (1);
  else if (input_tab[*n][0] == '|' && input_tab[*n][1] == '|')
    return (1);
  else if (input_tab[*n][0] == '&' && input_tab[*n][1] == '&')
    return (1);
  return (0);
}

int	find_my_first_exec(char **input_tab, int i)
{
  while (input_tab[i])
    {
      if (input_tab[i][0] == ';')
	return (i);
      else if (input_tab[i][0] == '|' && input_tab[i][1] == '|')
	return (i);
      else if (input_tab[i][0] == '&' && input_tab[i][1] == '&')
	return (i);
      i++;
    }
  return (i);
}

t_command	*make_command_sequence(char **input_tab, int *n, int i)
{
  t_command	*command_sequence;

  if (input_tab[*n] == NULL)
    return (NULL);
  i = find_my_first_exec(input_tab, i);
  if ((command_sequence = malloc(sizeof(*command_sequence) * ((i - *n + 1))))
      == NULL)
    return (change_globale());
  i = 0;
  while (input_tab[*n] && (check_sep(input_tab, n) == 0))
    {
      if (make_args(input_tab, n, &command_sequence[i]) == -1)
	return (NULL);
      find_redirections(input_tab, &command_sequence, n, i);
      command_sequence[i].pipein = 0;
      command_sequence[i].pipeout = 1;
      if (input_tab[*n] && input_tab[*n][0] == '|' && input_tab[*n][1] != '|')
	(*n)++;
      i++;
    }
  if (input_tab[*n] != NULL && (check_sep(input_tab, n) == 1))
    (*n)++;
  command_sequence[i].args = NULL;
  return (command_sequence);
}
