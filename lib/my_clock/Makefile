##
## Solo Project - C Library
## My_clock_C_Library
## File description:
## Makefile use for My_clock_C_Library compilation
##

ROOT_DIR_PATH	=	../../

LIB_DIR_PATH	=	../

SRC_TESTS_LOCATION	=	$(addprefix $(ROOT_DIR_PATH), tests/tests_my_clock/)

MAIN	=	$(addprefix $(ROOT_DIR_PATH), main.c)

SRC	=	__my_clock_counting.c	\
	my_clock_continue.c		\
	my_clock_create.c		\
	my_clock_destroy.c		\
	my_clock_restart.c		\
	my_clock_start.c		\
	my_clock_stop.c			\
	my_clock_update.c		\

SRC_TESTS	=	$(addprefix $(SRC_TESTS_LOCATION), test_my_clock_continue.c)	\
	$(addprefix $(SRC_TESTS_LOCATION), test_my_clock_destroy.c)		\
	$(addprefix $(SRC_TESTS_LOCATION), test_my_clock_restart.c)		\
	$(addprefix $(SRC_TESTS_LOCATION), test_my_clock_start.c)		\
	$(addprefix $(SRC_TESTS_LOCATION), test_my_clock_stop.c)		\
	$(addprefix $(SRC_TESTS_LOCATION), test_my_clock_update.c)		\

UNIT_TESTS_BINARY	=	$(addprefix $(ROOT_DIR_PATH), unit_tests)	\

override CFLAGS	=	-Wall -Wextra	\

override CPPFLAGS	+=	-I $(addprefix $(ROOT_DIR_PATH), include/my_clock/)	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmyclock.a

MV	=	mv

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	$(MV) $(NAME) $(LIB_DIR_PATH)

debug:
	$(CC) -g -o $(ROOT_DIR_PATH)$@ $(MAIN) $(SRC) $(CPPFLAGS) -lpthread

tests_run:
	$(CC) -o $(UNIT_TESTS_BINARY) $(SRC) $(SRC_TESTS) $(CPPFLAGS) -lpthread -lcriterion --coverage
	./$(UNIT_TESTS_BINARY)
	$(RM) -rf $(UNIT_TESTS_BINARY)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(ROOT_DIR_PATH)debug
	$(RM) $(NAME)
	$(RM) $(LIB_DIR_PATH)$(NAME)

re:	fclean all

.PHONY: all debug clean fclean re
