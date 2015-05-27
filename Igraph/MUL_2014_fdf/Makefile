##
## Makefile for makefile in /home/barthe_g/rendu/MUL_2014_fdf
## 
## Made by barthelemy gouby
## Login   <barthe_g@epitech.net>
## 
## Started on  Tue Dec  2 17:05:19 2014 barthelemy gouby
## Last update Wed May 27 12:00:12 2015 Barthelemy Gouby
##

SRC	= parser.c \
	map_info.c \
	parser_functions.c \
	projection.c \
	my_pixel_put_to_image.c \
	my_draw_line.c \
	main.c \

OBJ	= $(SRC:.c=.o)

NAME	= fdf

CC	= gcc

RM	= rm -f

CFLAGS	+= -I./include -g3
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -Wextra -Wall -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L/usr/lib64 -L/usr/lib64/X11 -L./minilibx -L./lib -lmlx -lXext -lX11 -lmy

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
