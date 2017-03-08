/*
** calculate.c for  in /home/b00bix/delivery/Semester2/Infographie/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Feb  9 14:51:38 2017 Matthieu BRAULT
** Last update Wed Mar  8 16:09:52 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include "struct.h"
#include "raytracer1.h"

void	my_calculate(t_my_framebuffer *buffer)
{
  sfVector3f	dir_vector;
  sfVector2i	coord;
  sfVector2i	screen_size;
  sfVector3f	eye_pos;
  float		cone;
  float		cylinder;
  float		sphere;
  float		plane;
  int		width;
  int		height;

  height = 0;
  eye_pos = eye_pos;
  screen_size.x = buffer->width;
  screen_size.y = buffer->height;
  eye_pos.x = -500;
  eye_pos.y = 100;
  eye_pos.z = 0;
  while (height <= screen_size.y)
    {
      width = 0;
      while (width <= screen_size.x)
	{
	  coord.x = width;
	  coord.y = height;
	  dir_vector = calc_dir_vector(500, screen_size, coord);
	  sphere = intersect_sphere(eye_pos, dir_vector, 180);
	  cylinder = intersect_cylinder(eye_pos, dir_vector, 150);
	  plane = intersect_plane(eye_pos, dir_vector);
	  if (sphere > 0)
	    my_put_pixel(buffer, width, height, sfRed);
	  cone = intersect_cone(eye_pos, dir_vector, 20);
	  width = width + 1;
	}
      height = height + 1;
    }
}
