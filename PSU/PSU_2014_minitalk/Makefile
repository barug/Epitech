##
## Makefile for makefile in /home/barthe_g/rendu/MUL_2014_wolf3d
## 
## Made by barthelemy gouby
## Login   <barthe_g@epitech.net>
## 
## Started on  Mon Dec 15 19:43:27 2014 barthelemy gouby
## Last update Sun Mar 22 23:35:55 2015 barthelemy gouby
##

SRCSSR	= ./server/main.c

SRCSCL	= ./client/main.c

SRCSBSR	= ./server/multiclient.c \
	  ./server/mainb.c

SRCSBCL	= ./client/mainb.c	

OBJSSR	= $(SRCSSR:.c=.o)

OBJSCL	= $(SRCSCL:.c=.o)

OBJSBSR	= $(SRCSBSR:.c=.o)

OBJSBCL	= $(SRCSBCL:.c=.o)


NAME1	= ./server/server

NAME2	= ./client/client

CC	= gcc

RM	= rm -f

CFLAGS	+= -I./include
CFLAGS += -Wextra -Wall -Werror
CFLAGS += -ansi -pedantic

LDFLAGS = -L./lib -lmy

all:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJSSR)
	$(CC) -o $(NAME1) $(OBJSSR) $(LDFLAGS)

$(NAME2):	$(OBJSCL)
	$(CC) -o $(NAME2) $(OBJSCL) $(LDFLAGS)

bonus:	bonussr bonuscl

bonussr:	$(OBJSBSR)
	$(CC) -o $(NAME1) $(OBJSBSR) $(LDFLAGS)

bonuscl:	$(OBJSBCL)
	$(CC) -o $(NAME2) $(OBJSBCL) $(LDFLAGS)

clean:
	$(RM) $(OBJSSR) $(OBJSCL)

bonusclean:
	$(RM) $(OBJSBSR) $(OBJSBCL)

fclean:	clean
	$(RM) $(NAME1) $(NAME2)

bonusfclean: bonusclean
	$(RM) $(NAME1) $(NAME2)

re:	fclean all

.PHONY:	all clean fclean re
