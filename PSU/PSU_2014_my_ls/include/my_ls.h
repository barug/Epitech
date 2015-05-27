/*
** my_ls.h for my_ls.h in /home/barthe_g/rendu/PSU_2014_my_ls/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Nov 30 23:01:33 2014 barthelemy gouby
** Last update Sun Nov 30 23:06:38 2014 barthelemy gouby
*/

#ifndef MYLS_H_
# define MYLS_H_

char    *add_str_m(char *str1, char *str2);
int     put_file_rights(struct stat *sb);
int     get_user_and_group(struct stat *sb);
int     if_l_option(struct stat *sb);
t_file_info     make_file_info(struct dirent *entry,
			       char *pathname);
t_file_info     **fill_info_array(t_file_info **file_info_array,
                                  char *pathname);
t_file_info     **make_info_array(char *pathname);
int     my_strcmp_m(char *s1, char *s2);
void    read_normal(t_file_info **file_info_array, t_option_struct *option_struct);
void    read_reverse(t_file_info **file_info_array, t_option_struct *option_struct);
int     get_files_list(char *pathname, t_option_struct *option_struct);
t_file_info **sort_name_info_array(t_file_info **file_info_array);
t_file_info     **sort_time_info_array(t_file_info **file_info_array);

#endif /* !MYLS_H_ */
