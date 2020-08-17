##
## Duo Project C Library
## DCLL_C_Library
## File description:
## Makefile use for DCLL_C_library compilation
##

SRC_LIBMYCLOCK	=	lib/my_clock/	\

NAME_LIBMYCLOCK	=	-lmyclock	\

all:
	$(MAKE) -C $(SRC_LIBMYCLOCK)

debug:
	$(MAKE) debug -C $(SRC_LIBMYCLOCK)

tests_run:
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	$(MAKE) tests_run -C $(SRC_LIBMYCLOCK)
	find -name "test_*.gcda" -delete
	find -name "test_*.gcno" -delete

coverage: tests_run
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete

clean:
	$(RM) -rf $(UNIT_TESTS_BINARY)
	$(RM) -rf $(TEST_COVERAGE_DIR)
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	$(MAKE) clean -C $(SRC_LIBMYCLOCK)

fclean: clean
	$(MAKE) fclean -C $(SRC_LIBMYCLOCK)

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run coverage clean fclean re
