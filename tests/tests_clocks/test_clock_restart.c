/*
// Solo Project - C Library
// Clocks
// File description:
// Tests the clock_restart() function.
*/

#include <criterion/criterion.h>
#include "clocks.h"

Test(clock_restart, simple_restart)
{
    t_clock *clock = clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    cr_expect(clock_start(clock));
    sleep(3);
    clock_restart(clock);
    offset += sleep(2);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 2 + offset);
    clock_destroy(clock);
}

Test(clock_restart, null_given)
{
    t_clock *clock = clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    cr_expect(clock_start(clock));
    sleep(3);
    clock_restart(NULL);
    offset += sleep(2);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 5 + offset);
    clock_destroy(clock);
}
