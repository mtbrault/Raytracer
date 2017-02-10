/*
** myplayer.h for Wolf3D in /home/remi.verny/CSFML/wireframe
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Mon Dec 26 11:36:41 2016 Remi Verny
** Last update Sun Jan 15 13:15:50 2017 Remi Verny
*/

#ifndef MY_PLAYER_H_
# define MY_PLAYER_H_

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics.h>
# include "mystruct.h"

typedef struct	s_player
{
  sfVector2f	p_pos;
  int		x_mov;
  int		y_mov;
  t_fov		fov;
}		t_player;

#endif /* MY_PLAYER_H_ */
