##
## Makefile for MyLS in /home/remi.verny/UnixSystem/myLS
## 
## Made by Remi Verny
## Login   <remi.verny@epitech.net>
## 
## Started on  Mon Nov 28 15:49:54 2016 Remi Verny
## Last update Tue Feb  7 14:41:15 2017 Remi Verny
##

CC	=	gcc

RM	=	rm -f

NAME	=	my_put_pixel

CFLAGS	+=	-W -Werror -Wextra -Wall -I./include/ -lc_graph_prog -lm

SRCS	=	my_put_pixel.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) main.o options_for_lines.o $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
