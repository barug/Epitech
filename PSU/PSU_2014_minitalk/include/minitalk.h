/*
** minitalk.h for minitalk in /home/barthe_g/rendu/PSU/B2/PSU_2014_minitalk/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Mar 22 16:37:55 2015 barthelemy gouby
** Last update Sun Mar 22 23:08:50 2015 barthelemy gouby
*/

#ifndef MINITALK_H_
# define MINITALK_H_

typedef struct		s_client
{
  pid_t			client_pid;
  struct s_client	*next;
}			t_client;

int			push_in_list(t_client **client_list, pid_t client_pid);

#endif /* !MINITALK_H_ */
