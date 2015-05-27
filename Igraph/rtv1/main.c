/*
** main.c for rtv1 in /home/barthe_g/rendu/igraph/B2/MUL_2014_rtv1
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Mar  4 12:59:07 2015 barthelemy gouby
** Last update Sun Mar 15 23:24:25 2015 barthelemy gouby
*/

#include <mlx.h>
#include "my.h"
#include "rtv1.h"

static	t_object objects[] = {{"sphere", 0, 0, 0, 0, 90, 0, 100, 0x00FF0000},
			      {"sphere", 0, 200, 100, 90, 0, 0, 100, 0x00FF0000},
			      {"sphere", 0, -200, 100, 0, 90, 0, 100, 0x00FF0000},
			      {"sphere", 200, 0, 100, 0, 0, 90, 100, 0x00FF0000 },
			      {"cone", 0, 0, 0, 0, 0, 0, 100, 0x00FF0000},
			      {"cylinder", 0, 500, 0, 0, 0, 0, 100, 0x00FF0000},
			      {"cylinder", 0, -500, 0, 0, 0, 0, 100, 0x00FF0000},
			      {"plane", 0, 0, 0, 0, 0, 0, 0, 0x000000FF}};

int		expose(t_imgdata *imgdata)
{
  mlx_put_image_to_window(imgdata->mlx_ptr, imgdata->win_ptr,
                          imgdata->img_ptr, 0, 0);
  return (0);
}

int		start_minilibx(t_imgdata *imgdata)
{
  imgdata->mlx_ptr = mlx_init();
  imgdata->img_ptr = mlx_new_image(imgdata->mlx_ptr,
				   WIN_WIDTH, WIN_HEIGHT);
  imgdata->win_ptr = mlx_new_window(imgdata->mlx_ptr,
				    WIN_WIDTH, WIN_HEIGHT, "display");
  imgdata->data = mlx_get_data_addr(imgdata->img_ptr,
				    &imgdata->bpp, &imgdata->sizeline, &imgdata->endian);
  return (0);
}

int		main()
{
  t_imgdata	imgdata;
  t_pov		pov;
  t_coordinate	lightsource;

  start_minilibx(&imgdata);
  pov.x = -700;
  pov.y = 0;
  pov.z = 200;
  pov.anglex = 0;
  pov.angley = 0;
  pov.anglez = 0;
  lightsource.x = -500;
  lightsource.y = 400;
  lightsource.z = 600;
  raytracer(&imgdata, &pov, objects, &lightsource);
  mlx_expose_hook(imgdata.win_ptr, expose, &imgdata);
  mlx_loop(imgdata.mlx_ptr);
  return (0);
}
