/*
** mywolf.h for Wolf3D in /home/remi.verny/CSFML/wireframe
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Dec 21 13:40:15 2016 Remi Verny
** Last update Sun Jan 15 11:19:16 2017 Remi Verny
*/

#ifndef WOLF_H_
# define WOLF_H_

# include "mystruct.h"
# include "myplayer.h"
# include "mymap.h"
# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics.h>

void		moving_pixels(t_my_framebuffer *framebuffer, sfColor color);
int		**get_map(const char *str, t_map *map_struct);
void		pixelize_map(t_my_framebuffer *framebuffer, int **map,
			     sfColor color, t_map map_struct);
void		raycast_vec(t_my_framebuffer *framebuffer, t_fov *fov,
			    int **map, t_player *player);
void		color_floor_sky(t_my_framebuffer *framebuffer);
sfVector2f	move_forward(sfVector2f pos, float direction, float distance);
int	        compare_pixels(t_my_framebuffer *framebuffer, int x, int y);
int		is_integer(float num);
void		straight_forward(t_csfml *display, int **map, t_fov *fov,
				 t_player *player);
void		straight_backwards(t_csfml *display, int **map, t_fov *fov,
				   t_player *player);
void		rotate_right(t_csfml *display, int **map, t_fov *fov,
			     t_player *player);
void		rotate_left(t_csfml *display, int **map, t_fov *fov,
			    t_player *player);
void		minimap(int **map, t_csfml *display, t_player *player);
void		move_forw_cond(int **map, t_fov *fov, t_player *player);
void		move_backw_cond(int **map, t_fov *fov, t_player *player);
void		color_floor_sky(t_my_framebuffer *framebuffer);

#endif /* WOLF_H_ */
