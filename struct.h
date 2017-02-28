/*
** struct.h for  in /home/b00bix/raytracer1
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue Feb 28 18:52:44 2017 Matthieu BRAULT
** Last update Tue Feb 28 18:54:13 2017 Matthieu BRAULT
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct		s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}			t_my_framebuffer;

typedef struct		s_sf_function
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfEvent		event;
}			t_sf_function;

#endif /* !STRUCT_H_ */
