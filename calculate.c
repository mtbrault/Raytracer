/*
** calculate.c for  in /home/b00bix/delivery/Semester2/Infographie/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Feb  9 14:51:38 2017 Matthieu BRAULT
** Last update Mon Mar  6 09:14:18 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include "struct.h"
#include "raytracer1.h"

int	my_aff(float cylinder, float sphere, float cone)
{
  if (cone < 0 && cylinder < 0 && sphere > 0)
    return (1);
  if (cone > 0 && cylinder < 0 && sphere < 0)
    return (2);
  if (cone < 0 && cylinder > 0 && sphere < 0)
    return (3);
  if (cone < 0 && cylinder > 0 && sphere > 0)
    {
      if (cylinder <= sphere)
	return (3);
      if (sphere <= cylinder)
	return (1);
    }
  if (cone > 0 && cylinder < 0 && sphere > 0)
    {
      if (cone <= sphere)
	return (2);
      if (sphere <= cone)
	return (1);
    }
  if (cone > 0 && cylinder > 0 && sphere < 0)
    {
      if (cone <= cylinder)
	return (2);
      else
	return (3);
    }
  return (0);
}

void	my_calculate(t_my_framebuffer *buffer)
{
  sfVector3f	dir_vector;
  sfVector2i	coord;
  sfVector2i	screen_size;
  sfVector3f	eye_pos;
  sfVector3f	spheree;
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
  eye_pos.x = -200;
  eye_pos.y = 0;
  eye_pos.z = 0;
  while (height <= screen_size.y)
    {
      width = 0;
      while (width <= screen_size.x)
	{
	  coord.x = width;
	  coord.y = height;
	  spheree.x = 500;
	  spheree.y = 500;
	  spheree.z = 500;
	  dir_vector = calc_dir_vector(500, screen_size, coord);
	  sphere = intersect_sphere(eye_pos, dir_vector, 42);
	  cylinder = intersect_cylinder(eye_pos, dir_vector, 150);
	  plane = intersect_plane(eye_pos, dir_vector);
	  cone = intersect_cone(eye_pos, dir_vector, 20);
	  if (cone > 0)
	    my_put_pixel(buffer, width, height, sfGreen);
	  if (plane > 0)
	    my_put_pixel(buffer, width, height, sfBlue);
	  /* if (cylinder > 0) */
	  /*   my_put_pixel(buffer, width, height, sfRed); */
	  /* if (sphere > 0) */
	  /*   my_put_pixel(buffer, width, height, sfYellow); */
	  /* if (my_aff(cylinder, sphere, cone) == 1) */
	  /*   my_put_pixel(buffer, width, height, sfRed);	   */
	  /* else if (my_aff(cylinder, sphere, cone) == 2) */
	  /*   my_put_pixel(buffer, width, height, sfGreen); */
	  /* else if (my_aff(cylinder, sphere, cone) == 3) */
	  /*   my_put_pixel(buffer, width, height, sfYellow); */
	  width = width + 1;
	}
      height = height + 1;
    }
}
