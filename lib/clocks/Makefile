##
## Solo Project - C Library
## Clocks
## File description:
## Makefile use for Clocks compilation
##

ROOT_DIR_PATH	=	../../

LIB_DIR_PATH	=	../

SRC_TESTS_LOCATION	=	$(addprefix $(ROOT_DIR_PATH), tests/tests_clocks/)

MAIN	=	$(addprefix $(ROOT_DIR_PATH), main.c)

SRC	=	__clock_counting.c	\
	clock_continue.c		\
	clock_create.c		\
	clock_destroy.c		\
	clock_restart.c		\
	clock_start.c		\
	clock_stop.c			\
	clock_update.c		\

SRC_TESTS	=	$(addprefix $(SRC_TESTS_LOCATION), test_clock_continue.c)	\
	$(addprefix $(SRC_TESTS_LOCATION), test_clock_destroy.c)		\
	$(addprefix $(SRC_TESTS_LOCATION), test_clock_restart.c)		\
	$(addprefix $(SRC_TESTS_LOCATION), test_clock_start.c)		\
	$(addprefix $(SRC_TESTS_LOCATION), test_clock_stop.c)		\
	$(addprefix $(SRC_TESTS_LOCATION), test_clock_update.c)		\

UNIT_TESTS_BINARY	=	$(addprefix $(ROOT_DIR_PATH), unit_tests)	\

override CFLAGS	=	-Wall -Wextra	\

override CPPFLAGS	+=	-I $(addprefix $(ROOT_DIR_PATH), include/clocks/)	\

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
