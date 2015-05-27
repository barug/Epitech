##
## Makefile for makefile in /home/barthe_g/rendu/PSU/PSU_2014_my_select
## 
## Made by barthelemy gouby
## Login   <barthe_g@epitech.net>
## 
## Started on  Tue Jan  6 16:25:53 2015 barthelemy gouby
## Last update Sun Jan 11 22:50:26 2015 barthelemy gouby
##

CC	= gcc

RM	= rm -f

CFLAGS  += -I./include -g3
CFLAGS 	+= -Wextra -Wall -Werror
CFLAGS 	+= -ansi -pedantic

LDFLAGS	= -L./lib -lmy -lncurses

SRCS	= list.c \
	  display.c \
	  termattr.c \
	  main.c \

OBJS	= $(SRCS:.c=.o)

NAME 	= my_select

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
