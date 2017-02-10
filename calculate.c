/*
** calculate.c for  in /home/b00bix/delivery/Semester2/Infographie/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Feb  9 14:51:38 2017 Matthieu BRAULT
** Last update Fri Feb 10 16:41:00 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
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

void	my_calculate(char *str, t_my_framebuffer *buffer)
{
  sfVector3f	dir_vector;
  sfVector3f	coord;
  sfVector2i	screen_size;
  sfVector3f	eye_pos;
  float		cone;
  float		cylinder;
  float		sphere;
  int		width;
  int		height;

  height = 0;
  screen_size.x = buffer->width;
  screen_size.y = buffer->height;
  while (height <= screen_size.y)
    {
      width = 0;
      while (width <= screen_size.x)
	{
	  eye_pos.x = width;
	  eye_pos.y = height;
	  eye_pos.z = 0;
	  dir_vector = calc_dir_vector(screen_size, eye_pos);
	  sphere = my_sphere(eye_pos, dir_vector, 67);
	  cone = my_cone(eye_pos, dir_vector, 44);
	  cylinder = my_cylinder(eye_pos, dir_vector, 32);
	  if (my_aff(cylinder, sphere, cone) == 1)
	    my_put_pixel(buffer, width, height, sfRed);	  
	  else if (my_aff(cylinder, sphere, cone) == 2)
	    my_put_pixel(buffer, width, height, sfGreen);
	  else if (my_aff(cylinder, sphere, cone) == 3)
	    my_put_pixel(buffer, width, height, sfYellow);
	  width = width + 1;
	}
      height = height + 1;
    }
}
