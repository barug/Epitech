/*
** datastruct.h for datastruct in /home/barthe_g/rendu/igraph/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Nov 14 12:51:58 2014 barthelemy gouby
** Last update Mon Dec  1 14:33:07 2014 barthelemy gouby
*/

#ifndef _IMGDATA_H_
# define _IMGDATA_H_

typedef struct s_imgdata
{
  void	*mlx_ptr;
  void	*img_ptr;
  void	*win_ptr;
  char	*data;
  int	bpp;
  int	sizeline;
  int	endian;
} t_imgdata;

#endif /* _IMGDATA_H_ */
