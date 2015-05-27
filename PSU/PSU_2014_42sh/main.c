/*
** main.c for minishell in /home/barthe_g/rendu/PSU/PSU_2014_minishell
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jan 20 17:36:12 2015 barthelemy gouby
** Last update Sun May 24 18:54:42 2015 Barthelemy Gouby
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/minishell.h"

int		g_malloc = 0;
int		g_spid = 0;

void		free_cmd_tab(t_command **cmd_tab)
{
  int		cmd_seq;
  int		cmd;

  cmd_seq = 0;
  while (cmd_tab[cmd_seq])
    {
      cmd = 0;
      while (cmd_tab[cmd_seq][cmd].args != NULL)
	{
	  free(cmd_tab[cmd_seq][cmd].args);
	  cmd++;
	}
      free(cmd_tab[cmd_seq]);
      cmd_seq++;
    }
  free(cmd_tab);
}

int		execute_input()
{
  char          *input;
  t_parser	pars;
  char          **pathtab;
  int		return_value;

  if ((input = get_next_line(0)) == NULL)
    {
      my_putchar('\n');
      if (g_malloc == 1)
	return (EXIT_FAILED);
      else
	return (EXIT_SUCCESS);
    }
  if (my_strlen(input) > 0)
    {
      if ((pathtab = get_pathtab()) == NULL)
	return (EXIT_FAILED);
      if ((command_parser(input, &pars)) == -1)
	return (EXIT_FAILED);
      return_value = execute_cmd_tab(&pars, pathtab);
      free_all(&pars, pathtab);
      return (return_value);
    }
  return (EXIT_SUCCESS);
}

int		main(int argc, char **argv, char **envp)
{
  int		return_value;
  int		end;

  end = 0;
  if ((g_env = make_env(envp)) == NULL)
    {
      my_fprintf(2, "[-] Malloc Failed To Cpy Env..\n");
      return (EXIT_FAILED);
    }
  argc = argc;
  argv = argv;
  signal(SIGINT, ctr_c);
  signal(SIGTSTP, ctr_z);
  while (end == 0)
    {
      my_printf("$>");
      if ((return_value = (execute_input())) != EXIT_SUCCESS)
	end = 1;
    }
  free_tab(g_env);
  if (return_value >= EXIT_EXIT)
    return (return_value - EXIT_EXIT);
  return (return_value);
}
