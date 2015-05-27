/*
** my_type.c for my_tipe in /home/barthe_g/rendu/PSU_2014_my_ls
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Nov 21 12:49:47 2014 barthelemy gouby
** Last update Mon Nov 24 17:26:26 2014 barthelemy gouby
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include <pwd.h>
#include <grp.h>

int	main(int argc, char **argv)
{
  struct stat	sb;
  int		type;
  struct passwd	*ps;
  struct group	*gp;
  char		*time;
  
  if ((stat(argv[1], &sb)) == 1)
    return (0);
  /*type = sb.st_mode & S_IFMT;
  type == S_IFBLK ? my_printf("block device\n") : 0;
  type == S_IFCHR ? my_printf("character device\n") : 0;
  type == S_IFDIR ? my_printf("directory\n") : 0;
  type == S_IFIFO ? my_printf("FIFO/pipe\n") : 0;
  type == S_IFLNK ? my_printf("symlink\n") : 0;
  type == S_IFREG ? my_printf("regular file\n") : 0;
  type == S_IFSOCK ? my_printf("socket\n") : 0;*/
  sb.st_mode & S_IFDIR ? my_putchar('d') : my_putchar('-');
  sb.st_mode & S_IRUSR ? my_putchar('r') : my_putchar('-');
  sb.st_mode & S_IWUSR ? my_putchar('w') : my_putchar('-');
  sb.st_mode & S_IXUSR ? my_putchar('x') : my_putchar('-');
  sb.st_mode & S_IRGRP ? my_putchar('r') : my_putchar('-');
  sb.st_mode & S_IWGRP ? my_putchar('w') : my_putchar('-');
  sb.st_mode & S_IXGRP ? my_putchar('x') : my_putchar('-');
  sb.st_mode & S_IROTH ? my_putchar('r') : my_putchar('-');
  sb.st_mode & S_IWOTH ? my_putchar('w') : my_putchar('-');
  sb.st_mode & S_IXOTH ? my_putchar('x') : my_putchar('-');
  my_printf(" %i", sb.st_nlink);
  ps = getpwuid(sb.st_uid);
  my_printf(" %s", ps->pw_name);
  gp = getgrgid(sb.st_gid);
  my_printf(" %s", gp->gr_name);
  my_printf(" %i", sb.st_size);
  time = ctime(&sb.st_mtime);
  time = &time[4];
  time [12] = 0;
  my_printf(" %s", time);
  return (0);
}
