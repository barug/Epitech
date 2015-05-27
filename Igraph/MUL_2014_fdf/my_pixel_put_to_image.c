/*
** my_pixel_put_to_image.c for my_puxel_to_image in /home/barthe_g/rendu/igraph
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Nov 13 15:12:57 2014 barthelemy gouby
** Last update Sun Dec  7 17:20:59 2014 barthelemy gouby
*/

#include <mlx.h>
#include "datastruct.h"

int	my_pixel_put_to_image(t_imgdata *imgdata, int x, int y, int color)
{
  int	pixel;
  int	i;
  int	nb;

  pixel = imgdata->bpp/8;
  nb = (y * imgdata->sizeline) + (x * pixel);
  i = (y * imgdata->sizeline) + (x * pixel);
  while (i < (nb + pixel))
    {
      imgdata->data[i] = mlx_get_color_value(imgdata->mlx_ptr, color);
      i++;
    }
  return (0);
}
