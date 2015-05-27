##
## Makefile for makefile in /home/barthe_g/rendu/printf
## 
## Made by barthelemy gouby
## Login   <barthe_g@epitech.net>
## 
## Started on  Tue Nov 11 17:42:05 2014 barthelemy gouby
## Last update Tue Jan  6 15:12:35 2015 barthelemy gouby
##

SRC=	get_next_line.c \
	functions.c \
	functions2.c \
	my_printf.c \
	my_find_prime_sup.c \
	my_getnbr.c \
	my_getnbr_base.c \
	my_isneg.c \
	my_is_prime.c \
	my_number_to_str.c \
	my_power_it.c \
	my_putchar.c \
	my_putnbr_base.c \
	my_putnbr_base_uns.c \
	my_put_nbr.c \
	my_putstr.c \
	my_revstr.c \
	my_showmem.c \
	my_showstr.c \
	my_square_root.c \
	my_strcapitalize.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_strdup.c \
	my_str_isalpha.c \
	my_str_islower.c \
	my_str_isnum.c \
	my_str_isprintable.c \
	my_str_isupper.c \
	my_strlen.c \
	my_strlowcase.c \
	my_strncat.c \
	my_strncmp.c \
	my_strncpy.c \
	my_strstr.c \
	my_strupcase.c \
	my_swap.c \
	add_array_entry.c \
	my_str_to_wordtab.c \

OBJ=	$(SRC:.c=.o)

NAME=	libmy.a

CFLAGS	+= -I./include -g3 

all= $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm *.o

fclean:	clean
	rm $(NAME)
