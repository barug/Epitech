/*
** cd.c for 42sh in /home/dupard_e/rendus/PSU_2014_42sh
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu May 21 16:25:10 2015 Erwan Dupard
** Last update Sun May 24 15:55:38 2015 karine aknin
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "my.h"

int		cd_home()
{
  char		*home;
  char		*pwd;

  if ((home = my_getenv(g_env, "HOME")) == NULL)
    {
      my_fprintf(2, "[-] Failed to getenv HOME\n");
      return (EXIT_SUCCESS);
    }
  if (access(home, F_OK) == EXIT_FAILED)
    return (EXIT_SUCCESS);
  if ((pwd = my_getenv(g_env, "PWD")) == NULL)
    return (EXIT_SUCCESS);
  if (my_setenv("OLDPWD", pwd) == EXIT_FAILED)
    return (EXIT_SUCCESS);
  if (my_setenv("PWD", home) == EXIT_FAILED)
    return (EXIT_SUCCESS);
  if (chdir(home) == EXIT_FAILED)
    {
      my_printf("[-] Failed to change directory to %s\n", home);
      return (EXIT_SUCCESS);
    }
  if (my_setenv("PWD", home) == EXIT_FAILED)
    return (EXIT_SUCCESS);
  my_printf("[+] Successfully changed directory to '%s'\n", home);
  return (EXIT_SUCCESS);
}

int		cd_prev()
{
  char		*oldpwd;
  char		*pwd;

  if ((oldpwd = my_getenv(g_env, "OLDPWD")) == NULL)
    {
      my_fprintf(2, "[-] Failed to getenv OLDPWD\n");
      return (EXIT_SUCCESS);
    }
  if ((pwd = my_getenv(g_env, "PWD")) == NULL)
    return (EXIT_SUCCESS);
  if (chdir(oldpwd) == EXIT_FAILED)
    {
      my_fprintf(2, "[-] Failed to chdir(%s)..\n", oldpwd);
      return (EXIT_SUCCESS);
    }
  if (my_setenv("PWD", oldpwd) == EXIT_FAILED)
    return (EXIT_SUCCESS);
  if (my_setenv("OLDPWD", pwd) == EXIT_FAILED)
    return (EXIT_SUCCESS);
  my_printf("[+] Successfully changed directory to '%s'\n", oldpwd);
  return (EXIT_SUCCESS);
}

int		cd_classic(char *arg)
{
  char		*pwd;

  if ((pwd = my_getenv(g_env, "PWD")) == NULL)
    {
      my_printf("[-] Failed to get PWD..\n");
      return (EXIT_SUCCESS);
    }
  if (chdir(arg) == EXIT_FAILED)
    {
      my_printf("[-] Failed to chdir(%s)..\n", arg);
      return (EXIT_SUCCESS);
    }
  if (my_setenv("OLDPWD", pwd) == EXIT_FAILED)
    return (EXIT_SUCCESS);
  if (my_setenv("PWD", arg) == EXIT_FAILED)
    return (EXIT_SUCCESS);
  my_printf("[+] Successfully changed directory to '%s'\n", arg);
  return (EXIT_SUCCESS);
}

int		cmd_cd(char **inptab, char **pathtab)
{
  (void)pathtab;
  if (inptab[1] != NULL)
    {
      if (inptab[1][0] == '-')
	cd_prev();
      else
	cd_classic(inptab[1]);
    }
  else
    cd_home();
  return (EXIT_SUCCESS);
}
