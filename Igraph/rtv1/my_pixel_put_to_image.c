/*
** my_pixel_put_to_image.c for my_puxel_to_image in /home/barthe_g/rendu/igraph
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Nov 13 15:12:57 2014 barthelemy gouby
** Last update Wed Mar  4 14:45:15 2015 barthelemy gouby
*/

#include <mlx.h>
#include "rtv1.h"

int		my_pixel_put_to_image(t_imgdata *imgdata, int x, int y, int color)
{
  int		pixel;
  int		i;
  unsigned long	rgb_color;

  pixel = imgdata->bpp/8;
  i = (y * imgdata->sizeline) + (x * pixel);
  rgb_color = mlx_get_color_value(imgdata->mlx_ptr, color);
  imgdata->data[i++] = rgb_color & 0x000000FF;
  imgdata->data[i++] = (rgb_color & 0x0000FF00) >> 8;
  imgdata->data[i++] = (rgb_color & 0x00FF0000) >> 16;
  imgdata->data[i++] = (rgb_color & 0xFF000000) >> 24;
  return (0);
}
