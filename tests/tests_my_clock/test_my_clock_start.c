/*
// Solo Project - C Library
// My_clock_C_Library
// File description:
// Tests the my_clock_start() function.
*/

#include <criterion/criterion.h>
#include "my_clock.h"

Test(my_clock_start, logic_time_on_both_threads)
{
    my_clock_t *clock = my_clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    cr_expect(my_clock_start(clock));
    offset += sleep(3);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 3 + offset);
    my_clock_destroy(clock);
}

Test(my_clock_start, zero_seconds_passed)
{
    my_clock_t *clock = my_clock_create();

    cr_assert_neq(clock, NULL);
    cr_expect(my_clock_start(clock));
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 0);
    my_clock_destroy(clock);
}

Test(my_clock_start, null_given)
{
    my_clock_t *clock = my_clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    cr_expect_neq(my_clock_start(NULL), 1);
    offset += sleep(3);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 0);
    my_clock_destroy(clock);
}
