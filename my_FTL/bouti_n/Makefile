CC		=		gcc

NAME	=		ftl

SRC		=		air_shed.c\
				my_string.c\
				readline.c\
				main.c\
				container.c\
				system_control.c\
				system_repair.c\

RM		=		rm -f

OBJ		=		$(SRC:%.c=%.o)

CFLAGS	=		-W -Wall -Werror -ansi -pedantic -g3


all		:		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean	:
				$(RM) $(OBJ)

fclean	:		clean
				$(RM) $(NAME)

re 		:		fclean all
