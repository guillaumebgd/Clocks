/*
// Solo Project - C Library
// Clocks
// File description:
// Tests the clock_stop() function.
*/

#include <criterion/criterion.h>
#include "clocks.h"

Test(clock_stop, easy_stop)
{
    t_clock *clock = clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    cr_expect(clock_start(clock));
    offset += sleep(3);
    clock_stop(clock);
    sleep(5);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 3 + offset);
    clock_destroy(clock);
}

Test(clock_stop, null_given)
{
    t_clock *clock = clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    cr_expect(clock_start(clock));
    offset += sleep(3);
    clock_stop(NULL);
    offset += sleep(5);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 8 + offset);
    clock_destroy(clock);
}
