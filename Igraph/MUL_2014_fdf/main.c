/*
** main.c for main in /home/barthe_g/rendu/MUL_2014_fdf
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Sun Dec  7 17:03:58 2014 barthelemy gouby
** Last update Wed May 27 12:05:06 2015 Barthelemy Gouby
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

int     main(int argc, char **argv)
{
  t_point_info  **point_array;
  t_map_info    map_info;

  if (argc != 2)
    {
      my_printf("usage: ./fdf [map_name]\n");
      return (0);
    }
  if (check_map(argv[1]) == 1)
    {
      my_printf("error: invalid map\n");
      return (0);
    }
  point_array = map_parser(argv[1], &map_info);
  get_maximum_height(point_array, &map_info);
  convert_display_map(point_array, &map_info);
  return (0);
}
