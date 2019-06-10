##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

CC	=	gcc

RM	=	rm -rf

SRC	=	paterns/display_a_line.c	\
		main.c			\
		options.c		\
		paterns/draw_a_circle.c		\
		paterns/my_putpixel_rand.c	\
		my_put_spiral.c				\
		square.c

CFLAGS	=	-I./include -g3

LIB	=	-l csfml-graphics

OBJ	=	$(SRC:.c=.o)

NAME	=	my_screensaver

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

mr_clean :
	find -type f -name "*~" -delete -o -type f -name "#*#" -delete

.PHONY : all clean fclean mr_clean re
