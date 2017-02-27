/*
** translate.c for  in /home/b00bix/raytracer1/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Sun Feb 26 15:37:47 2017 Matthieu BRAULT
** Last update Mon Feb 27 16:38:01 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>
#include "raytracer1.h"

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  sfVector3f	trans;

  trans.x = to_translate.x + translations.x;
  trans.y = to_translate.y + translations.y;
  trans.z = to_translate.z * translations.z;
  return (trans);
}
