##
## EPITECH PROJECT, 2018
## joan
## File description:
## joan
##

SRC	=	sample.c			\
		./files/my_strdup.c		\
		./files/my_strcat.c		\
		./files/my_strcpy.c		\
		./files/my_strcmp.c		\
		./files/remove_space_tab.c	\
		./files/my_bzero.c		\
		./files/my_strlen.c		\
		./files/my_putstr.c		\
		./files/str_to_word_tab.c	\
		./files/my_putchar.c		\
		./files/my_strncmp.c		\
		./builtins/my_exec.c		\
		./builtins/env.c		\
		./builtins/cd.c			\
		./builtins/path.c		\
		./builtins/sig_exec_error.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I./include -L./include -ggdb -g -g3

LDFLAGS	=	-lgnl

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm *.gcda -f $(NAME)
	rm *.gcno -f $(NAME)
	rm *~ -f $(NAME)
	rm *# -f $(NAME)
	rm ./builtins/*~ -f $(NAME)
	rm ./builtins/*# -f $(NAME)
	rm ./files/*~ -f $(NAME)
	rm ./files/*# -f $(NAME)
	rm ./tests/*~ -f $(NAME)
	rm ./tests/*# -f $(NAME)
	rm ./tests/*.o -f $(NAME)
	rm ./tests/*.gcno -f $(NAME)
	rm ./tests/*.gcda -f $(NAME)
	rm ./tests/unit-tests -f $(NAME)

re:	fclean all

c:	fclean clean

tests_run:
		make -C ./tests
		./tests/unit-tests
