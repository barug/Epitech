/*
** local_include.h for local_include in /home/barthe_g/rendu/igraph/include
** 
** Made by barthelemy gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Dec  1 15:06:00 2014 barthelemy gouby
** Last update Sun Dec  7 17:20:06 2014 barthelemy gouby
*/

#ifndef LOCALINCLUDE_H_
# define LOCALINCLUDE_H_

int     my_pixel_put_to_image(t_imgdata *imgdata, int x, int y, int color);
int     set_pixel(int x, int y, int color, t_pixnfo *pix );
int     my_draw_line(t_pixnfo *pix1, t_pixnfo *pix2,
		     int color, t_imgdata *imgdata);
int     convert_display_map(t_point_info **point_array, t_map_info *map_info);
t_point_info    **add_point(t_point_info **point_array, t_point_info new_point);
t_point_info    make_point_info(char *z_str, int x, int y);
t_point_info    **analyze_line(char **line_array, t_point_info **point_array,
			       int y, t_map_info *map_info);
t_point_info    **map_parser(char *map_pathname, t_map_info *map_info);
char    **add_array_entry(char **tab, char *array_entry);
char            **my_str_to_wordtab(char *str);
int     get_maximum_height(t_point_info **point_array, t_map_info *map_info);
int     get_line_size(char **line);
int     check_map(char *map_pathname);
float           my_sqrt(int nbr);
t_pixnfo        make_isopixel(t_point_info *point_info, t_map_info *map_info, int window_size);
t_pixnfo        **iso_converter(t_point_info **point_array, t_map_info *map_info, int window_size);
int     display_map(t_pixnfo **pixnfo_array, t_imgdata *imgdata, t_map_info *map_info);
int     convert_display_map(t_point_info **point_array, t_map_info *map_info);

#endif /* !LOCALINCLUDE_H_ */
