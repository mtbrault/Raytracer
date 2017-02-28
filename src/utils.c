/*
** utils.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Mon Feb 27 12:46:59 2017 Matthieu BRAULT
** Last update Tue Feb 28 19:00:18 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "raytracer1.h"

float	result(sfVector3f abc, sfVector3f coord, sfVector3f dir_vector, float delta)
{
  float	x1;
  float	x2;

  if (delta < 0)
    return (-1.0f);
  else if (delta == 0)
    {
      if ((x1 = coord.y + ((abc.y * -1) / (2.0 * abc.x)) * dir_vector.y) >= 0)
	return (x1);
      else
	return (-1.0f);
    }
  else
    {
      x2 = ((abc.y * -1) - sqrt(delta)) / (2.0 * abc.x);
      x1 = ((abc.y * -1) + sqrt(delta)) / (2.0 * abc.x);
      x1 = coord.y + x1 * dir_vector.y;
      x2 = coord.y + x2 * dir_vector.y;
      if (x1 <= x2 && x1 > 0)
	return (x1);
      else if (x1 >= x2 && x2 > 0)
	return (x2);
      else
	return (-1.0f);
    }
}
