/*
** form.c for  in /home/b00bix/delivery/Mathematique/104intersection
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Mon Dec 19 11:01:47 2016 Matthieu BRAULT
** Last update Fri Feb 10 15:12:00 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "raytracer1.h"

sfVector3f	calc_dir_vector(sfVector2i screen_size, sfVector3f screen_pos)
{
  sfVector3f	dir_vector;

  dir_vector.x = 500;
  dir_vector.y = (screen_size.x / 2) - screen_pos.x;
  dir_vector.z = (screen_size.y / 2) - screen_pos.y;
  return (dir_vector);
}

float	result(sfVector3f abc, sfVector3f coord, sfVector3f dir_vector)
{
  float	delta;
  float	x0;
  float	x1;
  float	x2;

  if (abc.x == 0 && abc.y == 0 && abc.z == 0)
    return (-1);
  if (abc.x == 0)
    return (-1);
  delta = pow(abc.y, 2) - 4 * abc.x * abc.z;
  if (delta < 0)
    return (-1);
  if (delta == 0)
    {
      x0 = (abc.y * -1) / (2 * abc.x);
      return (coord.y + x0 * dir_vector.y);
    }
  if (delta > 0)
    {
      x2 = ((abc.y * -1) - sqrt(delta)) / (2 * abc.x);
      x1 = ((abc.y * -1) + sqrt(delta)) / (2 * abc.x);
      x1 = coord.y + x1 * dir_vector.y;
      x2 = coord.y + x2 * dir_vector.y;
      if (x1 <= x2)
	return (x1);
      else
	return (x2);
    }
}

float	my_sphere(sfVector3f coord, sfVector3f dir_vector, float radius)
{
  sfVector3f	abc;
  
  if (radius <= 0)
    return (-1);
  abc.x = pow(dir_vector.x, 2) + pow(dir_vector.y, 2) + pow(dir_vector.z, 2);
  abc.y = 2 * coord.x * dir_vector.x + 2 * coord.y * dir_vector.y + 2 * coord.z * dir_vector.z;
  abc.z = (pow(coord.x, 2) + pow(coord.y, 2) + pow(coord.z, 2)) - pow(radius, 2);
  return (result(abc, coord, dir_vector));
}

float	my_cylinder(sfVector3f coord, sfVector3f dir_vector, float radius)
{
  sfVector3f	abc;
  
  if (radius <= 0)
    return (-1);
  abc.x = pow(dir_vector.x, 2) + pow(dir_vector.y, 2);
  abc.y = 2 * coord.x * dir_vector.x + 2 * coord.y * dir_vector.y;
  abc.z = pow(coord.x, 2) + pow(coord.y, 2) - pow(radius, 2);
  return (result(abc, coord, dir_vector));
}

float	my_cone(sfVector3f coord, sfVector3f dir_vector, float angl)
{
  sfVector3f	abc;
  float		angle;
  float		powtan;

  if (angl <= 0 || angl >= 90)
    return (-1);
  angle = (M_PI / 2) - (angl * M_PI / 180);
  powtan = pow(tan(angle), 2);
  abc.x = pow(dir_vector.x, 2) + pow(dir_vector.y, 2) - (pow(dir_vector.z, 2) / powtan);
  abc.y = 2 * coord.x * dir_vector.x + 2 * coord.y * dir_vector.y - (2 * coord.z * dir_vector.z / powtan);
  abc.z = pow(coord.x, 2) + pow(coord.y, 2) - pow(coord.z, 2) / powtan;
  return (result(abc, coord, dir_vector));
}
