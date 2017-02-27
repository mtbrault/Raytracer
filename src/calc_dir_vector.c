/*
** calc_dir_vector.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Sun Feb 26 15:34:55 2017 Matthieu BRAULT
** Last update Mon Feb 27 16:43:40 2017 Matthieu BRAULT
*/

#include "raytracer1.h"

sfVector3f	calc_dir_vector(float dist_to_plane, sfVector2i screen_size, sfVector3f screen_pos)
{
  sfVector3f	dir_vector;

  dir_vector.x = dist_to_plane;
  dir_vector.y = (screen_size.x / 2.0) - screen_pos.y;
  dir_vector.z = (screen_size.y / 2.0) - screen_pos.z;
  return (dir_vector);
}