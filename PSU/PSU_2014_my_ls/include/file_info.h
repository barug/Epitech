/*
** file_info.h for file_info in /home/barthe_g/rendu/PSU_2014_my_ls/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Nov 26 14:36:39 2014 barthelemy gouby
** Last update Thu Nov 27 15:07:52 2014 barthelemy gouby
*/

#ifndef FILEINFO_H_
# define FILEINFO_H_

typedef struct	s_file_info
{
  struct dirent *entry;
  struct stat	sb;
}		t_file_info;

#endif /* !FILEINFO_H_ */
