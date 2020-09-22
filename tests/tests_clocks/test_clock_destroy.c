/*
// Solo Project - C Library
// clock_C_Library
// File description:
// Tests the clock_destroy() function.
*/

#include <criterion/criterion.h>
#include "clocks.h"

Test(clock_destroy, easy_destroy)
{
    t_clock *clock = clock_create();

    clock_destroy(clock);
}

Test(clock_destroy, null_given)
{
    clock_destroy(NULL);
}
