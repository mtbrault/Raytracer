/*
** utils.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Mon Feb 27 12:46:59 2017 Matthieu BRAULT
** Last update Sat Mar  4 18:40:14 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "raytracer1.h"

float	result(sfVector3f abc, sfVector3f coord, sfVector3f vec_dir, float delta)
{
  float	x1;
  float	x2;

  if (delta < 0)
    return (-1.0f);
  else if (delta == 0)
    {
      if ((x1 = coord.x + ((abc.y * -1) / (2.0 * abc.x)) * vec_dir.x) >= 0)
	return (x1);
      else
	return (-1.0f);
    }
  else
    {
      x2 = ((abc.y * -1) - sqrt(delta)) / (2.0 * abc.x);
      x1 = ((abc.y * -1) + sqrt(delta)) / (2.0 * abc.x);
      x1 = coord.x + x1 * vec_dir.x;
      x2 = coord.x + x2 * vec_dir.x;
      if (x1 <= x2 && x1 > 0)
	return (x1);
      else if (x2 > 0)
	return (x2);
      else
	return (-1.0f);
    }
}
