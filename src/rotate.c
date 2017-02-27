/*
** rotate.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Sun Feb 26 15:39:23 2017 Matthieu BRAULT
** Last update Mon Feb 27 16:57:53 2017 Matthieu BRAULT
*/

#include <math.h>
#include <SFML/Graphics.h>

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	axe1;
  sfVector3f	axe2;
  sfVector3f	axe3;

  axe1.x = to_rotate.x;
  axe1.y = (to_rotate.y * cos(angles.x)) + (to_rotate.z * -sin(angles.x));
  axe1.z = (to_rotate.y * sin(angles.x)) + (to_rotate.z * cos(angles.x));
  axe2.x = (axe1.x * cos(angles.y)) + (axe1.z * sin(angles.y));
  axe2.y = axe1.y;
  axe2.z = (axe1.x * -sin(angles.y)) + (axe1.z * cos(angles.y));
  axe3.x = (axe2.x * cos(angles.z)) + (axe2.y * -sin(angles.z));
  axe3.y = (axe2.x * sin(angles.z)) + (axe2.y * cos(angles.z));
  axe3.z = axe2.z;
  return (axe3);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	axe1;
  sfVector3f	axe2;
  sfVector3f	axe3;

  axe1.x = (to_rotate.x * cos(angles.z)) + (to_rotate.y * -sin(angles.z));
  axe1.y = (to_rotate.x * sin(angles.z)) + (to_rotate.y * cos(angles.z));
  axe1.z = to_rotate.z;
  axe2.x = (axe1.x * cos(angles.y)) + (axe1.z * sin(angles.y));
  axe2.y = axe1.y;
  axe2.z = (axe1.x * -sin(angles.y)) + (axe1.z * cos(angles.y));
  axe3.x = axe2.x;
  axe3.y = (axe2.y * cos(angles.x)) + (axe2.z * -sin(angles.x));
  axe3.z = (axe2.y * sin(angles.x)) + (axe2.z * cos(angles.x));
  return (axe3);
}
