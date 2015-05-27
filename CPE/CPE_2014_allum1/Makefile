##
## Makefile for Allum1 in /home/barthe_g/rendu/CPE/B2/Allum1
## 
## Made by barthelemy gouby
## Login   <barthe_g@epitech.net>
## 
## Started on  Tue Feb  3 11:55:19 2015 barthelemy gouby
## Last update Fri Feb 20 17:50:21 2015 barthelemy gouby
##

CC 	= gcc

RM 	= rm -rf

CFLAGS 	+= -Wextra -Wall -Werror
CFLAGS 	+= -ansi -pedantic
CFLAGS 	+= -I./include -g3

LDFLAGS = -L./lib -lmy -lncurses	 

SRCS	= list.c \
	  playerin.c \
	  ai.c \
	  main.c \

SRCSB	= turnb.c \
	  displayb.c \
	  listb.c \
	  playerinb.c \
	  ai.c \
	  mainb.c \

OBJSB	= $(SRCSB:.c=.o)

OBJS	= $(SRCS:.c=.o)

NAME    = Allum1

all:	$(NAME)

bonus: $(OBJSB)
	$(CC) $(OBJSB) -o $(NAME) $(LDFLAGS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

cleanbonus:
	$(RM) $(OBJSB)

fcleanbonus: cleanbonus
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
