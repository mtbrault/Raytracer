/*
** main.c for  in /home/b00bix/delivery/Semester2/Infographie/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed Feb  8 16:43:45 2017 Matthieu BRAULT
** Last update Fri Feb 10 15:09:48 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include "raytracer1.h"

sfRenderWindow	*create_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, 0);
  if (window == NULL)
    return (NULL);
  return (window);
}

void	*buffer_create(t_my_framebuffer *buff, int width, int height)
{
  int	s;

  if ((buff->pixels = malloc(width * height * 4 * sizeof(sfUint8))) == NULL)
    return (NULL);
  if (buff->pixels == NULL)
    return (NULL);
  s = 0;
  while (s < width * height * 4)
    {
      buff->pixels[s] = 0;
      s = s + 1;
    }
}
void	window_open(t_sf_function *sf)
{
  while (sfRenderWindow_isOpen(sf->window))
    {
      while (sfRenderWindow_pollEvent(sf->window, &sf->event))
	{
	  if ((sf->event.type == sfEvtClosed))
	    sfRenderWindow_close(sf->window);
	  if (sfKeyboard_isKeyPressed(sfKeyEscape))
	    sfRenderWindow_close(sf->window);
	}
      sfRenderWindow_clear(sf->window, sfBlack);
      sfRenderWindow_drawSprite(sf->window, sf->sprite, NULL);
      sfRenderWindow_display(sf->window);
    }
  sfRenderWindow_destroy(sf->window);
}

int	read_map(char *name, t_my_framebuffer *buffer)
{
  int		fd;
  char		buff[4097];
  sfVector2i	*coord;

  if ((coord = malloc(sizeof(*coord))) == NULL)
    return (1);
  if ((fd = open(name, O_RDONLY)) == -1)
    return (1);
  if (read(fd, buff, 4096) == -1)
    return (1);
  buff[4097] = '\0';
  my_calculate(buff, buffer);
  close(fd);
}

int	main(int ac, char **av)
{
  t_my_framebuffer	*buff;
  t_sf_function		*sf;

  if (ac != 2)
    return (84);
  if ((buff = malloc(sizeof(*buff))) == NULL)
    return (84);
  if ((sf = malloc(sizeof(*sf))) == NULL)
    return (84);
  buff->width = SCREEN_WIDTH;
  buff->height = SCREEN_HEIGHT;
  sf->window = create_window("Raytracer 1", buff->width, buff->height);
  if (buffer_create(buff, buff->width, buff->height) == NULL)
    return (84);
  sf->sprite = sfSprite_create();
  sf->texture = sfTexture_create(buff->width, buff->height);
  sfSprite_setTexture(sf->sprite, sf->texture, sfTrue);
  if (read_map(av[1], buff) == 1)
    return (84);
  sfTexture_updateFromPixels(sf->texture, buff->pixels, buff->width,
			     buff->height, 0, 0);
  window_open(sf);
  return (0);
}
