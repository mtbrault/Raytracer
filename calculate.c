/*
** calculate.c for  in /home/b00bix/delivery/Semester2/Infographie/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu Feb  9 14:51:38 2017 Matthieu BRAULT
** Last update Thu Mar 16 14:22:16 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include "struct.h"
#include "raytracer1.h"

void	my_aff(sfVector3f form, float plane, t_my_framebuffer *buffer,
	       sfVector2i pos)
{
  plane = plane;
  if (form.x > 0 && form.z > 0)
    {
      if (form.x < form.z)
	my_put_pixel(buffer, pos.y, pos.x, sfBlue);
      else
	my_put_pixel(buffer, pos.y, pos.x, sfGreen);
    }
  else if (form.x > 0)
    my_put_pixel(buffer, pos.y, pos.x, sfBlue);
  else if (form.z > 0)
    my_put_pixel(buffer, pos.y, pos.x, sfGreen);
}

void	my_calculate(t_my_framebuffer *buffer)
{
  sfVector3f	dir_vector;
  sfVector2i	coord;
  sfVector2i	screen_size;
  sfVector3f	form;
  float		plane;

  buffer->pos.x = 0;
  screen_size = ((sfVector2i) {buffer->width, buffer->height});
  while (buffer->pos.x <= screen_size.y)
    {
      buffer->pos.y = 0;
      while (buffer->pos.y <= screen_size.x)
	{
	  coord = ((sfVector2i) {buffer->pos.y, buffer->pos.x});
	  dir_vector = calc_dir_vector(500, screen_size, coord);
	  form.x = intersect_sphere(buffer->eye_pos, dir_vector, 200);
	  form.y = intersect_cylinder(buffer->eye_pos, dir_vector, 150);
	  plane = intersect_plane(buffer->eye_pos, dir_vector);
	  form.z = intersect_cone(buffer->eye_pos, dir_vector, 20);
	  my_aff(form, plane, buffer, buffer->pos);
	  buffer->pos.y = buffer->pos.y + 1;
	}
      buffer->pos.x = buffer->pos.x + 1;
    }
}
