/*
// Solo Project - C Library
// Clocks
// File description:
// Tests the clock_start() function.
*/

#include <criterion/criterion.h>
#include "clocks.h"

Test(clock_start, logic_time_on_both_threads)
{
    t_clock *clock = clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    cr_expect(clock_start(clock));
    offset += sleep(3);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 3 + offset);
    clock_destroy(clock);
}

Test(clock_start, zero_seconds_passed)
{
    t_clock *clock = clock_create();

    cr_assert_neq(clock, NULL);
    cr_expect(clock_start(clock));
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 0);
    clock_destroy(clock);
}

Test(clock_start, null_given)
{
    t_clock *clock = clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    cr_expect_neq(clock_start(NULL), 1);
    offset += sleep(3);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 0);
    clock_destroy(clock);
}
