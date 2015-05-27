##
## Makefile for makefile in /home/barthe_g/rendu/PSU/PSU_2014_minishell
## 
## Made by barthelemy gouby
## Login   <barthe_g@epitech.net>
## 
## Started on  Tue Jan 20 17:34:27 2015 barthelemy gouby
## Last update Sun May 17 21:34:59 2015 Barthelemy Gouby
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -I./include -g3 -lncurses
CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -pedantic

LDFLAGS	= -L./lib -lmy -lncurses -lm

SRCS	= main.c \

OBJS	= $(SRCS:.c=.o)

NAME	= a_star

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
