/*
** create_window.c for  in /home/b00bix/delivery/Semester2/Infographie/raytracer1/bootstrap_pingouin_csfml
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Feb 10 14:40:33 2017 Matthieu BRAULT
** Last update Fri Feb 10 14:47:51 2017 Matthieu BRAULT
*/

#include <SFML/Graphics.h>

int	main(int ac, char **av)
{
  sfVideoMode		mode;
  sfRenderWindow	*window;

  mode.width = 1920;
  mode.height = 1080;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
  /* if (window == NULL) */
  /*   return (1); */
  sfRenderWindow_destroy(window);
  return (0);
}
