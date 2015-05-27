##
## Makefile for makefile in /home/barthe_g/rendu/MUL_2014_wolf3d
## 
## Made by barthelemy gouby
## Login   <barthe_g@epitech.net>
## 
## Started on  Mon Dec 15 19:43:27 2014 barthelemy gouby
## Last update Wed May 27 11:58:00 2015 Barthelemy Gouby
##

SRC	= shadow.c \
	  luminosity.c \
	  objects.c \
	  transform.c \
	  my_pixel_put_to_image.c \
	  raytracer.c \
	  main.c \

OBJ	= $(SRC:.c=.o)

NAME	= rtv1

CC	= gcc

RM	= rm -f

CFLAGS	+= -I./include -g3

LDFLAGS = -L/usr/lib64 -L/usr/lib64/X11 -L./minilibx -L./lib -lmlx -lXext -lX11 -lmy -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
