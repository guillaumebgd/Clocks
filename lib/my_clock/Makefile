##
## Solo Project C Library
## My_clock_C_Library
## File description:
## Makefile use for My_clock_C_Library compilation
##

SRC	=	__my_clock_counting.c	\
	my_clock_continue.c	\
	my_clock_create.c	\
	my_clock_destroy.c	\
	my_clock_restart.c	\
	my_clock_start.c	\
	my_clock_stop.c	\
	my_clock_update.c	\

override CFLAGS	=	-Wall -Wextra	\

override CPPFLAGS	+=	-I ./../../include/	\

OBJ	=	$(SRC:.c=.o)	\

NAME	=	libmyclock.a	\

MV	=	mv	\

AR	=	ar	\

OBJ	=	$(SRC:.c=.o)	\

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	$(MV) $(NAME) ../

debug:
	$(CC) -g -o ../../$@ ../../main.c $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -lpthread

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ../../debug
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all

.PHONY: all debug clean fclean re
