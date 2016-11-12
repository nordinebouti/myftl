CC		=		gcc

NAME	=		ftl

SRC		=		air_shed.c\
				my_string.c\
				my_string2.c\
				readline.c\
				main.c\
				container.c\
				system_control.c\
				system_repair.c\
				game.c\
				game_info.c\
				enemy.c\
				bonus.c\

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
