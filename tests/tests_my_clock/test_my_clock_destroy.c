/*
// Solo Project - C Library
// My_clock_C_Library
// File description:
// Tests the my_clock_destroy() function.
*/

#include <criterion/criterion.h>
#include "my_clock.h"

Test(my_clock_destroy, easy_destroy)
{
    my_clock_t *clock = my_clock_create();

    my_clock_destroy(clock);
}

Test(my_clock_destroy, null_given)
{
    my_clock_destroy(NULL);
}
