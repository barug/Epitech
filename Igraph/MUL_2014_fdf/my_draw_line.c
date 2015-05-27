/*
** my_draw_line.c for my_draw_line in /home/barthe_g/rendu/igraph
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Nov 14 14:46:01 2014 barthelemy gouby
** Last update Sun Dec  7 17:43:03 2014 barthelemy gouby
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

int     absolut_value(int value)
{
  if (value < 0)
    return (-value);
  else
    return (value);
}

int	set_pixel(int x, int y, int color, t_pixnfo *pix )
{
  pix->x = x;
  pix->y = y;
  pix->color = color;
  return (0);
}

int	my_draw_line_low(t_pixnfo *pix1, t_pixnfo *pix2,
			 int color, t_imgdata *imgdata)
{
  int	x;

  x = pix1->x;
  while (x <= pix2->x)
    {
      my_pixel_put_to_image(imgdata, x, pix1->y + ((pix2->y - pix1->y)
						   * (x-pix1->x)) / (pix2->x - pix1->x), color);
      x++;
    }
  while (x >= pix2->x)
    {
      my_pixel_put_to_image(imgdata, x, pix1->y + ((pix2->y - pix1->y)
						   * (x-pix1->x)) / (pix2->x - pix1->x), color);
      x--;
    }
  return (0);

}

int     my_draw_line_high(t_pixnfo *pix1, t_pixnfo *pix2, 
			  int color, t_imgdata *imgdata)
{
  int   y;

  y = pix1->y;
  while (y <= pix2->y)
    {
      my_pixel_put_to_image(imgdata, pix1->x + ((pix2->x - pix1->x)
						* (y-pix1->y)) / (pix2->y - pix1->y), y, color);
      y++;
    }
  while (y >= pix2->y)
    {
      my_pixel_put_to_image(imgdata, pix1->x + ((pix2->x - pix1->x)
						* (y-pix1->y)) / (pix2->y - pix1->y), y, color);
      y--;
    }
  return (0);
}

int     my_draw_line(t_pixnfo *pix1, t_pixnfo *pix2,
		     int color, t_imgdata *imgdata)
{
  color = 0x00FFFFFF;
  if (absolut_value((pix2->x) - (pix1->x)) >= absolut_value((pix2->y) - (pix1->y)))
    my_draw_line_low(pix1, pix2, color, imgdata);
  if (absolut_value((pix2->x) - (pix1->x)) < absolut_value((pix2->y) - (pix1->y)))
    my_draw_line_high(pix1, pix2, color, imgdata);
  return (0);
}
