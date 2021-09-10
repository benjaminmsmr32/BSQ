##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

COMP	=	gcc -O2 -o

NAME	=	bsq

SRC		=	$(wildcard srcs/*.c)

OBJ		=	$(SRC:.c=.o)

INC		=	-I./include/

RM		=	rm -f

CFLAGS += -g -Wall -Wextra

all:	$(OBJ)
	$(COMP) $(NAME) $(OBJ) $(INC) $(CFLAGS)

clean:
	$(RM) bsq

fclean:	clean
	$(RM) $(wildcard srcs/*.o)

re: fclean all

.phony: all clean fclean re