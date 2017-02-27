/*
** raytracer1.h for  in /home/b00bix/delivery/Semester2/Infographie/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Feb  7 13:39:46 2017 Matthieu BRAULT
** Last update Mon Feb 27 16:43:59 2017 Matthieu BRAULT
*/

#ifndef RAYTRACER1_H_
# define RAYTRACER1_H_

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

#include <SFML/Graphics.h>

typedef struct		s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}			t_my_framebuffer;

typedef struct		s_sf_function
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfEvent		event;
}			t_sf_function;

sfVector3f	calc_dir_vector(float dist_to_plane, sfVector2i screen_size, sfVector3f screen_pos);
sfVector3f	translate(sfVector3f to_translate, sfVector3f translations);
sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles);
sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles);
sfVector3f	get_normal_sphere(sfVector3f intersection_point);
sfVector3f	get_normal_plane(int upward);
sfVector3f	get_normal_cylinder(sfVector3f intersection_point);
sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle);
float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector);
float		result(sfVector3f abc, sfVector3f coord, sfVector3f dir_vector, float delta);
float		intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector, float radius);
float		intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector, float radius);
float		intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector, float semiangle);
float		get_light_coef(sfVector3f light_vector, sfVector3f normal_vector);

#endif /* !RAYTRACER1_H_ */
