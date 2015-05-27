/*
** map_info.c for map_info in /home/barthe_g/rendu/MUL_2014_fdf
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Dec  7 17:02:08 2014 barthelemy gouby
** Last update Sun Dec  7 17:03:00 2014 barthelemy gouby
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "datastruct.h"
#include "pixelinfo.h"
#include "point_info.h"
#include "my.h"
#include "local_include.h"

int     get_maximum_height(t_point_info **point_array, t_map_info *map_info)
{
  int   max_height;
  int   z;
  int   i;

  i = 0;
  max_height = 0;
  while (point_array[i] != NULL)
    {
      z = point_array[i]->z;
      if (z < 0)
        z = - z;
      if (z > max_height)
        max_height = z;
      i++;
    }
  map_info->max_height = max_height;
  return (0);
}

int     get_line_size(char **line)
{
  int   i;

  i = 0;
  while (line[i] != NULL)
    i++;
  return (i);
}

int     check_map(char *map_pathname)
{
  int   fd;
  char  *buffer;
  char  **line;
  int   line_size;

  fd = open(map_pathname, O_RDONLY);
  if ((buffer = get_next_line(fd)) != NULL)
    {
      line = my_str_to_wordtab(buffer);
      line_size = get_line_size(line);
      free(line);
    }
  else
    return (1);
  while ((buffer = get_next_line(fd)) != NULL)
    {
      line = my_str_to_wordtab(buffer);
      if (get_line_size(line) != line_size)
        return (1);
      free(line);
    }
  close(fd);
  return (0);
}
