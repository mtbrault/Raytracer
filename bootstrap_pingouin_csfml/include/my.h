/*
** my.h for Bistro in /home/remi.verny/CPool_Bistro/CPool_bistro-matic
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Wed Nov  2 09:08:56 2016 Remi Verny
** Last update Wed Dec 28 10:19:33 2016 Remi Verny
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>
# include "myarg.h"
# include "mymap.h"

int	my_printf(char *str, ...);
int     my_put_nbr(int nb);
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_putstrn(char *str, int n);
void	fillwith0(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
int	my_strlen(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *src);
char	*my_malloc(int size);
char	*my_revstr(char *str);
char	*my_strcat(char *dest, char *src);
int	my_getnbr(char *str);
char	*revert_base(unsigned long long int to_convert, char *base);
char	*my_put_big_nbr(unsigned long long int nb);
char	*my_put_big_nbrsign(long long int nb);
int	**my_int_to_nbrtab(char *str, t_map *map_struct);

#endif /* MY_H_ */
