/*
** parser.c for parser in /home/barthe_g/rendu/MUL_2014_fdf
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Dec  1 17:55:33 2014 barthelemy gouby
** Last update Sun Dec  7 17:56:39 2014 barthelemy gouby
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

t_point_info	**add_point(t_point_info **point_array, t_point_info new_point)
{
  t_point_info	**new_point_array;
  int		i;

  i = 0;
  while (point_array[i] != NULL)
    i++;
  new_point_array = malloc((i + 2) * sizeof(t_point_info*));
  if (new_point_array == NULL)
    return (NULL);
  i = 0;
  while (point_array[i] != NULL)
    {
      new_point_array[i] = point_array[i];
      i++;
    }
  new_point_array[i] = malloc(sizeof(t_point_info));
  if (new_point_array[i] == NULL)
    return (NULL);
  (*new_point_array[i++]) = new_point;
  new_point_array[i] = NULL;
  free(point_array);
  return (new_point_array);
}

t_point_info	make_point_info(char *z_str, int x, int y)
{
  t_point_info	new_point;
  int		z;

  z = my_getnbr(z_str);
  new_point.x = x;
  new_point.y = y;
  new_point.z = z;
  return (new_point);
}

t_point_info	**analyze_line(char **line_array, t_point_info **point_array,
			       int y, t_map_info *map_info)
{
  int		x;
  t_point_info	new_point;

  x = 0;
  while (line_array[x] != NULL)
    {
      new_point = make_point_info(line_array[x], x, y);
      point_array = add_point(point_array, new_point);
      x++;
    }
  map_info->size_of_lines = x;
  return (point_array);
}

t_point_info	**map_parser(char *map_pathname, t_map_info *map_info)
{
  t_point_info	**point_array;
  int		y;
  char		*buffer;
  char		**line_array;
  int		fd;

  y = 0;
  point_array = malloc(sizeof(t_point_info*));
  if (point_array == NULL)
    return (NULL);
  point_array[0] = NULL;
  fd = open(map_pathname, O_RDONLY);
  while ((buffer = get_next_line(fd)) != NULL)
    {
      line_array = my_str_to_wordtab(buffer);
      point_array = analyze_line(line_array, point_array, y, map_info);
      y++;

    }
  map_info->nbr_of_lines = y;
  close(fd);
  return (point_array);
}
