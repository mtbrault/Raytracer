/*
** my.h for BootstrapGraph1 in /home/remi.verny/CSFML
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Tue Nov  8 10:31:17 2016 Remi Verny
** Last update Sun Jan 15 13:06:01 2017 Remi Verny
*/

#ifndef MY_STRUCT_H_
# define MY_STRUCT_H_

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/System/Export.h>
# include <SFML/Graphics.h>

typedef struct	        s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_csfml_disp
{
  sfSprite		*sprite;
  sfRenderWindow	*window;
  sfTexture		*texture;
  t_my_framebuffer	*framebuffer;
}			t_csfml;

typedef struct	 	s_ray
{
  double		pos_x;
  double	       	pos_y;
  double	       	dir_x;
  double	       	dir_y;
}			t_ray;

typedef struct		s_fov
{
  double		dir_x;
  double	       	dir_y;
  double	       	cam_plane_x;
  double	       	cam_plane_y;
  double	       	copy;
}			t_fov;

typedef struct		s_ray_values
{
  int			step_x;
  int			step_y;
  int			coord_encount;
  int			map_x;
  int			map_y;
  double		until_first_x;
  double		until_first_y;
  double		diff_x;
  double		diff_y;
  double		real_dist;
}			t_ray_val;

typedef struct		s_disp_val
{
  int	  		draw_start;
  int			draw_end;
  int	  		diff;
  int			x_color;
  sfVector2i		from;
  sfVector2i		to;
  sfColor		color;
}			t_disp_val;

typedef struct		s_distances
{
  float			dist_x;
  float			dist_y;
  float			delta_x;
  float			delta_y;
  int			step_x;
  int			step_y;
  sfVector2i		map_pos;
}			t_dist;

t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			set_mode(sfVideoMode *mode);
void			my_put_pixel(t_my_framebuffer *framebuffer,
				     int x, int y, sfColor color);
void			my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from, sfVector2i to,
				     sfColor color);

#endif /* MY_STRUCT_H_ */
