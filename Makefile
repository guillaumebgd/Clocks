##
## Duo Project C Library
## DCLL_C_Library
## File description:
## Makefile use for DCLL_C_library compilation
##

SRC_LIBMYCLOCK	=	lib/my_clock	\

NAME_LIBMYCLOCK	=	-lmyclock	\

override LDFLAGS	+=	-L./lib	\

override LDLIBS	+=	$(NAME_LIBMYCLOCK)	\

override CPPFLAGS	+=	-I ./include/	\

UNIT_TESTS_BINARY	=	unit_tests	\

TEST_COVERAGE_DIR	=	tests/coverage	\

all:
	$(MAKE) -C $(SRC_LIBMYCLOCK)

debug:
	$(MAKE) debug -C $(SRC_LIBMYCLOCK)

tests_run:	LDLIBS += -lcriterion --coverage
tests_run:	CFLAGS += --coverage
tests_run:
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	$(MAKE) -C $(SRC_LIBMYCLOCK)
	$(CC) -o $(UNIT_TESTS_BINARY) tests/test_*.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -lpthread
	./$(UNIT_TESTS_BINARY)
	$(RM) -rf $(UNIT_TESTS_BINARY)
	mkdir $(TEST_COVERAGE_DIR)
	mv *.gc* $(TEST_COVERAGE_DIR)

clean:
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	$(RM) -rf $(UNIT_TESTS_BINARY)
	$(RM) -rf $(TEST_COVERAGE_DIR)
	$(MAKE) clean -C $(SRC_LIBMYCLOCK)

fclean: clean
	$(MAKE) fclean -C $(SRC_LIBMYCLOCK)

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run clean fclean re
