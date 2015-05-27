/*
** multiclient.c for minitalk in /home/barthe_g/rendu/PSU/B2/PSU_2014_minitalk
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Mar 22 23:05:26 2015 barthelemy gouby
** Last update Sun Mar 22 23:11:46 2015 barthelemy gouby
*/

#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"

int		push_in_list(t_client **client_list, pid_t client_pid)
{
  t_client	*tmp;

  tmp = *client_list;
  if (*client_list == NULL)
    {
      usleep(100);
      if ((*client_list = malloc(sizeof(t_client))) == NULL)
        return (-1);
      (*client_list)->client_pid = client_pid;
      (*client_list)->next = NULL;
    }
  else
    {
      while (tmp->next != NULL)
        tmp = tmp->next;
      if ((tmp->next = malloc(sizeof(t_client))) == NULL)
        return (-1);
      tmp->next->client_pid = client_pid;
      tmp->next->next = NULL;
    }
  return (0);
}
