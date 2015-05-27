##
## Makefile for 42sh in /home/dupard_e/rendus/PSU_2014_42sh
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Tue May 12 14:14:02 2015 Erwan Dupard
## Last update Sun May 24 17:28:11 2015 karine aknin
##

CC	= gcc

RM 	= rm -f

CFLAGS 	+= -I./include -Werror -Wall -Wextra
CFLAGS	+= -ansi -pedantic

LDFLAGS += -L./lib -lmy

SRCS	= builtins/builtins2.c		\
	  builtins/builtins3.c		\
	  builtins/builtins.c		\
	  builtins/cd.c			\
	  shell/cmd_sequence.c		\
	  shell/env.c			\
	  shell/exec.c			\
	  shell/exec2.c			\
	  main.c			\
	  shell/misc.c			\
	  parser/parser.c		\
	  parser/build_my_args.c	\
	  parser/make_command.c		\
	  shell/pathtab.c		\
	  shell/redirections.c

OBJS	= $(SRCS:.c=.o)

NAME	= 42sh

all: library $(NAME)

library:
	make -C lib/my/

library-re:
	make -C lib/my/ re

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean : 
	$(RM) $(OBJS)
	make -C lib/my/ clean

fclean: clean
	$(RM) $(NAME)
	make -C lib/my/ fclean

re: fclean library-re all

.PHONY: clean fclean all library re
