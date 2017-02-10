/*
** framebuffer_create.c for  in /home/b00bix/delivery/Semester2/Infographie/raytracer1/bootstrap_pingouin_csfml
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Feb 10 14:25:19 2017 Matthieu BRAULT
** Last update Fri Feb 10 14:40:19 2017 Matthieu BRAULT
*/

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*framebuffer;
  
  if ((framebuffer = malloc(sizeof(*framebuffer))) == NULL)
    return (NULL);
  framebuffer->width = width;
  framebuffer->height = height;
  return (framebuffer);
}
