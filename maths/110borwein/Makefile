##
## Makefile for borwein in /home/barthe_g/rendu/maths/B2/110borwein
## 
## Made by Barthelemy Gouby
## Login   <barthe_g@epitech.net>
## 
## Started on  Thu Apr 16 15:43:58 2015 Barthelemy Gouby
## Last update Thu Apr 16 16:31:57 2015 Barthelemy Gouby
##

CC	= gcc

RM	= rm -rf

LDFLAGS += -lm
CFLAGS  += -I./include -Wextra -Wall -Werror
CFLAGS  += -pedantic

SRCS	= main.c	\

OBJS	= $(SRCS:.c=.o)

NAME	= 110borwein

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
