/*
** raytracer1.h for  in /home/b00bix/delivery/Semester2/Infographie/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Feb  7 13:39:46 2017 Matthieu BRAULT
** Last update Fri Feb 10 15:11:44 2017 Matthieu BRAULT
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

sfVector3f	calc_dir_vector(sfVector2i screen_size, sfVector3f screen_pos);
float		result(sfVector3f abc, sfVector3f coord, sfVector3f dir_vector);
float		my_sphere(sfVector3f coord, sfVector3f dir_vector, float radius);
float		my_cylinder(sfVector3f coord, sfVector3f dir_vector, float radius);
float		my_cone(sfVector3f coord, sfVector3f dir_vector, float angl);

#endif /* !RAYTRACER1_H_ */
