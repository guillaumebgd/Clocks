##
## Solo Project - C Library
## Clocks
## File description:
## Makefile use for Clocks compilation
##

SRC_LIBCLOCKS	=	lib/clocks/

all:
	$(MAKE) -C $(SRC_LIBCLOCKS)

debug:
	$(MAKE) debug -C $(SRC_LIBCLOCKS)

tests_run:
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	-$(MAKE) tests_run -C $(SRC_LIBCLOCKS)
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
	$(MAKE) clean -C $(SRC_LIBCLOCKS)

fclean: clean
	$(MAKE) fclean -C $(SRC_LIBCLOCKS)

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run coverage clean fclean re
