CC		=		gcc

NAME	=		ftl

SRC		=		air_shed.c\
				my_string.c\
				readline.c\
				main.c

RM		=		rm -f

OBJ		=		$(SRC:%.c=%.o)

CFLAGS	=		-W -Wall -Werror -ansi -pedantic

all		:		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean	:
				$(RM) $(OBJ)

fclean	:		clean
				$(RM) $(NAME)

re 		:		fclean all