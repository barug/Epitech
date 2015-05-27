/*
** projection.c for projection in /home/barthe_g/rendu/MUL_2014_fdf
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Dec  3 13:13:46 2014 barthelemy gouby
** Last update Sun Dec  7 20:40:16 2014 barthelemy gouby
*/

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

float		my_sqrt(int nbr)
{
  float		i;

  i = 0;
  while ((i * i) <= nbr)
    i = i + 0.01;
  return (i);
}

t_pixnfo	make_isopixel(t_point_info *point_info,
			      t_map_info *map_info, int window_size)
{
  t_pixnfo	new_pix;
  int		X;
  int		Y;
  int		size_ratio;
  float		height_ratio;

  if (map_info->max_height != 0)
    height_ratio = 1 / my_sqrt(map_info->max_height);
  size_ratio = window_size /(((map_info->nbr_of_lines + map_info->size_of_lines)) * 10 * 0.8806);
  X = ((10 * point_info->x) - (10 * point_info->y)) * 0.86602;
  Y = (10 * point_info->z) * height_ratio + ((10 * point_info->x) + (10 * point_info->y)) * 0.5;
  new_pix.x = (X * size_ratio) + (window_size / 2);
  new_pix.y = 3 * (window_size / 4) - (10 *size_ratio) - (Y * size_ratio);
  return (new_pix);
}

t_pixnfo	**iso_converter(t_point_info **point_array, t_map_info *map_info, int window_size)
{
  int		i;
  t_pixnfo	**pixnfo_array;

  i = 0;
  while (point_array[i] != NULL)
    i++;
  pixnfo_array = malloc(i * sizeof(t_pixnfo*));
  if (pixnfo_array == NULL)
    return (NULL);
  i = 0;
  while (point_array[i] != NULL)
    {
      pixnfo_array[i] = malloc(sizeof(t_pixnfo));
      if (pixnfo_array[i] == NULL)
	return (NULL);
      *pixnfo_array[i] = make_isopixel(point_array[i], map_info, window_size);
      i++;
    }
  pixnfo_array[i] = NULL;
  i = 0;
  while (point_array[i] !=NULL)
    free(point_array[i++]);
  free(point_array[i]);
  free(point_array);
  return (pixnfo_array);
}

int	display_map(t_pixnfo **pixnfo_array,
		    t_imgdata *imgdata, t_map_info *map_info)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (y < map_info->nbr_of_lines)
    {
      while (x < (map_info->size_of_lines - 1))
	{
	  my_draw_line(pixnfo_array[y * (map_info->size_of_lines) + x],
		       pixnfo_array[y * (map_info->size_of_lines) + x + 1], 0x00FFFFFF, imgdata);
	  x++;
	}
      x = 0;
      y++;
    }
  y = 0;
  x = 0;
  while (x < map_info->size_of_lines)
    {
      while (y < (map_info->nbr_of_lines - 1))
	{
	  my_draw_line(pixnfo_array[x + y * (map_info->size_of_lines)],
		       pixnfo_array[x + (y + 1) * map_info->size_of_lines], 0x00FFFFFF, imgdata);
	  y++;
	}
      y = 0;
      x++;
    }
  return (0);
}

int	convert_display_map(t_point_info **point_array, t_map_info *map_info)
{
  t_imgdata	t;
  t_pixnfo	**pixnfo_array;
  int		window_size;

  window_size = 1000;
  pixnfo_array = iso_converter(point_array, map_info, window_size);
  t.mlx_ptr = mlx_init();
  t.img_ptr = mlx_new_image(t.mlx_ptr, window_size, window_size);
  t.win_ptr = mlx_new_window(t.mlx_ptr, window_size, window_size, "map");
  t.data = mlx_get_data_addr(t.img_ptr, &t.bpp, &t.sizeline, &t.endian);
  display_map(pixnfo_array, &t, map_info);
  mlx_put_image_to_window(t.mlx_ptr, t.win_ptr, t.img_ptr, 20, 20);
  mlx_loop(t.mlx_ptr);
  return (0);
}
