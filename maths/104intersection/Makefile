##
## Makefile for makefile in /home/barthe_g/rendu/104intersection
## 
## Made by barthelemy gouby
## Login   <barthe_g@epitech.net>
## 
## Started on  Wed Dec 17 12:51:52 2014 barthelemy gouby
## Last update Thu Dec 18 14:50:32 2014 barthelemy gouby
##

SRC	= main.c \
	equations.c \

OBJ	= $(SRC:.c=.o)

NAME	= 104intersection

CC	= gcc

RM	= rm -f

CFLAGS	+= -I./include -g3
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -Wextra -Wall -Werror

all:	$(NAME)

$(NAME):	$(OBJ) 
	$(CC) -o $(NAME) $(OBJ) -L./lib -lmy -lm

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
