##
## Makefile for makefile in /home/barthe_g/rendu/PSU_2014_my_ls
## 
## Made by barthelemy gouby
## Login   <barthe_g@epitech.net>
## 
## Started on  Tue Nov 25 13:28:40 2014 barthelemy gouby
## Last update Sun Nov 30 23:16:01 2014 barthelemy gouby

SRC=	my_ls.c \
	get_files.c \
	get_files2.c \
	get_files3.c \
	sort_files.c \

OBJ=	$(SRC:.c=.o)

NAME=	my_ls

all= $(NAME)

CFLAGS+= -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ) -L./lib -lmy

clean:
	rm $(OBJ)

fclean:
	rm $(NAME)
