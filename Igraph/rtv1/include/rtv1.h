/*
** rtv1.h for rtv1 in /home/barthe_g/rendu/igraph/B2/MUL_2014_rtv1/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Wed Mar  4 12:56:03 2015 barthelemy gouby
** Last update Sun Mar 15 23:16:42 2015 barthelemy gouby
*/

#ifndef _RTV1_H_
# define _RTV1_H_

typedef struct	s_pov
{
  double	x;
  double	y;
  double	z;
  int           anglex;
  int           angley;
  int           anglez;
}		t_pov;

typedef struct	s_object
{
  char		*type;
  double	x;
  double	y;
  double	z;
  double	anglex;
  double	angley;
  double	anglez;
  double	parameter;
  int		color;
}		t_object;

typedef struct	s_intersect
{
  double	k;
  t_object	*object;
}		t_intersect;

typedef struct	s_pixel
{
  int		x;
  int		y;
}		t_pixel;

typedef struct	s_coordinate
{
  double	x;
  double	y;
  double	z;
}		t_coordinate;

typedef struct	s_imgdata
{
  void		*mlx_ptr;
  void		*img_ptr;
  void		*win_ptr;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
}		t_imgdata;

int		raytracer(t_imgdata *imgdata, t_pov *pov,
			  t_object *objects,
			  t_coordinate *lightsource);
int		my_pixel_put_to_image(t_imgdata *imgdata,
				      int x, int y, int color);
void		rotate_x(double *y, double *z, double angle);
void		rotate_y(double *x, double *z, double angle);
void		rotate_z(double *x, double *y, double angle);
void		transform_pov(t_pov *tmp_pov,
			      t_coordinate *tmp_vect,
			      t_object *object);
t_intersect	plane(t_pov pov, t_coordinate rayvector,
		      t_object *object);
t_intersect	sphere(t_pov pov, t_coordinate rayvector,
		       t_object *object);
t_intersect	cone(t_pov pov,
		     t_coordinate rayvector,
		     t_object *object);
t_intersect	cylinder(t_pov pov,
			 t_coordinate rayvector,
			 t_object *object);
int		luminosity_sphere(t_pov *intersection_p,
				  t_coordinate *lightvector,
                                  t_object *object);
int		luminosity_plane(t_pov *intersection_p,
				 t_coordinate *lightvector,
                                 t_object *object);
int		luminosity_cone(t_pov *intersection_p,
				t_coordinate *lightvector,
				t_object *object);
int		luminosity_cylinder(t_pov *intersection_p,
				    t_coordinate *lightvector,
				    t_object *object);
int		find_if_shadow(t_pov *intersection_p,
                               t_object *objects,
			       t_coordinate *lightvector);
t_intersect	calculate_intersection(t_pov *pov,
				       t_coordinate *rayvector,
				       t_object *object);

# define	WIN_WIDTH 1024
# define	WIN_HEIGHT 768
# define	D 100
# define	SQUARE(nb) ((nb) * (nb))
# define	PI 3.14159265358
# define	OBJECTS_NB 8
# define	ZERO 0.0000000001

#endif /* _RTV1_H_ */
