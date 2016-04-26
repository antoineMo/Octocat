##
## Makefile for Makefile in /home/antoine/Desktop/pataugoire/octo
##
## Made by MORISSET Antoine
## Login   <moriss_a@etna-alternance.net>
##
## Started on  Wed Jan  20 16:16:32 2016 MORISSET Antoine
## Last update Fri jan  21 14:45:59 2016 MORISSET Antoine
##

CC = gcc
NAME = octocat
SRC =	octocat.c			\
	core_function.c		\
	GM_redirection.c	\
	other_function.c	\
	my_putchar.c

OBJ = $(SRC:%.c=%.o)
CFLAGS = -W -Wall -Wextra -Werror
RM = rm -f

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all
