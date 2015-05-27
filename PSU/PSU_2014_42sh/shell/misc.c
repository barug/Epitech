/*
** misc.c for minishell2 in /home/barthe_g/rendu/PSU/B2/PSU_2014_minishell2
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Mar 29 20:06:04 2015 barthelemy gouby
** Last update Sun May 24 18:48:37 2015 Barthelemy Gouby
*/

#define _POSIX_SOURCE
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

char	**make_env(char **envp)
{
  int	i;
  char	**env;

  i = 0;
  while (envp[i])
    i++;
  if ((env = malloc((i + 1)* sizeof(char*))) == NULL)
    return (NULL);
  i = 0;
  while (envp[i])
    {
      env[i] = my_strdup(envp[i]);
      i++;
    }
  env[i] = NULL;
  return (env);
}

void	free_all(t_parser *pars, char **pathtab)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  free_tab(pathtab);
  while (pars->cmd_tab[i])
    {
      while (pars->cmd_tab[i][j].args)
	free_tab(pars->cmd_tab[i][j++].args);
      j = 0;
      free(pars->cmd_tab[i]);
      ++i;
    }
  free(pars->cmd_tab);
  free(pars->sep);
}

void	ctr_c(int sig)
{
  (void)sig;
  if (g_spid != 0)
    {
      kill(g_spid, SIGINT);
      g_spid = 0;
    }
  signal(SIGINT, ctr_c);
}

void		ctr_z(int sig)
{
  (void)sig;
  signal(SIGTSTP, ctr_z);
}
