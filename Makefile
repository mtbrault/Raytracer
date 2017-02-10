##
## Makefile for  in /home/b00bix/delivery/CPool_rush3
## 
## Made by Matthieu BRAULT
## Login   <b00bix@epitech.net>
## 
## Started on  Sun Oct 30 04:31:30 2016 Matthieu BRAULT
## Last update Fri Feb 10 15:10:37 2017 Matthieu BRAULT
##

CC	= gcc

RM	= rm -f

SRC	= calculate.c \
	  form.c \
	  main.c \
	  autograder/my_put_pixel.c

NAME	= raytracer1

CFLAGS	+= -I./
CFLAGS	+= -Wall -Wextra

OBJS	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) -lc_graph_prog -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
