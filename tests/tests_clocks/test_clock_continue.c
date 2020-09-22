/*
// Solo Project - C Library
// clock_C_Library
// File description:
// Tests the clock_continue() function.
*/

#include <criterion/criterion.h>
#include "clocks.h"

Test(clock_continue, easy_continue)
{
    t_clock *clock = clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    cr_expect(clock_start(clock));
    offset += sleep(3);
    clock_stop(clock);
    sleep(3);
    clock_continue(clock);
    offset += sleep(2);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 5 + offset);
    clock_destroy(clock);
}

Test(clock_continue, null_given)
{
    t_clock *clock = clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    cr_expect(clock_start(clock));
    offset += sleep(3);
    clock_stop(clock);
    sleep(3);
    clock_continue(NULL);
    offset += sleep(2);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 3 + offset);
    clock_destroy(clock);
}
