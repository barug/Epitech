/*
** parser1.c for parser in /home/aknin_k/rendu/tek1/syst_unix/42sh/PSU_2014_42sh/karine/shell
** 
** Made by karine aknin
** Login   <aknin_k@epitech.net>
** 
** Started on  Mon May 18 15:58:59 2015 karine aknin
** Last update Sun May 24 17:11:40 2015 karine aknin
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "minishell.h"

int	my_putstror(char *str)
{
  printf("%s\n", str);
  return (-1);
}

void	fill_in_str(char **input_tab, t_parser *pars)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (input_tab[i])
    {
      if (input_tab[i][0] == ';')
	{
	  pars->sep[n] = ';';
	  n++;
	}
      if (input_tab[i][0] == '|' && input_tab[i][1] == '|')
	{
	  pars->sep[n] = '|';
	  n++;
	}
      if (input_tab[i][0] == '&' && input_tab[i][1] == '&')
	{
	  pars->sep[n] = '&';
	  n++;
	}
      i++;
    }
  pars->sep[n] = '\0';
}

int	create_my_tab_and_char(char **input_tab, t_parser *pars)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (input_tab[i])
    {
      if (input_tab[i][0] == ';' || (input_tab[i][0] == '|' &&
				     input_tab[i][1] == '|') ||
	  (input_tab[i][0] == '&' && input_tab[i][1] == '&'))
	n++;
      i++;
    }
  if ((pars->cmd_tab = malloc(sizeof(*pars->cmd_tab) * (n + 2))) == NULL)
    return (my_putstror("ERROR = Malloc failed"));
  pars->cmd_tab[n + 1] = NULL;
  if ((pars->sep = malloc(sizeof(*pars->sep) * (n + 2))) == NULL)
    return (my_putstror("ERROR = Malloc failed"));
  pars->sep[n + 1] = '\0';
  fill_in_str(input_tab, pars);
  return (0);
}

int	command_parser(char *input, t_parser *pars)
{
  char	**input_tab;
  int	i;
  int	n;

  n = 0;
  input_tab = NULL;
  pars->cmd_tab = NULL;
  pars->sep = NULL;
  i = 0;
  if ((input_tab = my_str_to_word_tab(input)) == NULL)
    return (-1);
  if ((create_my_tab_and_char(input_tab, pars)) == -1)
    return (-1);
  while ((pars->cmd_tab[i] = make_command_sequence(input_tab, &n, n)))
    i++;
  if (pars->cmd_tab[i] == NULL && g_malloc == 1)
    return (-1);
  if (input_tab)
    free(input_tab);
  return (0);
}
