##
## Makefile for makefile in /home/barthe_g/rendu/PSU/PSU_2014_minishell
## 
## Made by barthelemy gouby
## Login   <barthe_g@epitech.net>
## 
## Started on  Tue Jan 20 17:34:27 2015 barthelemy gouby
## Last update Tue Apr 21 13:40:00 2015 Barthelemy Gouby
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -I./include -g3 -lncurses
CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -pedantic

LDFLAGS	= -L./lib -lmy -lncurses

SRCS	= generator.c \
	  main.c \

OBJS	= $(SRCS:.c=.o)

NAME	= maze_gen

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
