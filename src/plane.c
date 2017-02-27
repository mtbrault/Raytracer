/*
** plance.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Sun Feb 26 15:41:30 2017 Matthieu BRAULT
** Last update Mon Feb 27 19:55:18 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>

float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	k;
  
  if (dir_vector.z == 0)
    return (-1.0f);
  k = (float)(-eye_pos.z / dir_vector.z);
  if (k < 0)
    return (-1.0f);
  return (k);
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	zob;
  
  zob.x = 0;
  zob.y = 0;
  zob.z = 0;
  return (zob);
}
