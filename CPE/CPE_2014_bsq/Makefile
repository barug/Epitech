##
## Makefile for makefile in /home/barthe_g/rendu/CPE/CPE_2014_bsq
## 
## Made by barthelemy gouby
## Login   <barthe_g@epitech.net>
## 
## Started on  Tue Jan 13 16:38:12 2015 barthelemy gouby
## Last update Fri Jan 23 18:07:06 2015 barthelemy gouby
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -I./include -o3 
CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic

LDFLAGS	= -L./lib -lmy -lncurses

SRCS	= loadtab.c \
	  algo.c \
	  main.c \

OBJS	= $(SRCS:.c=.o)

NAME	= bsq

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
 
