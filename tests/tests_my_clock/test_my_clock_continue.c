/*
// Solo Project - C Library
// My_clock_C_Library
// File description:
// Tests the my_clock_continue() function.
*/

#include <criterion/criterion.h>
#include "my_clock.h"

Test(my_clock_continue, easy_continue)
{
    my_clock_t *clock = my_clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    my_clock_start(clock);
    offset += sleep(3);
    my_clock_stop(clock);
    sleep(3);
    my_clock_continue(clock);
    offset += sleep(2);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 5 + offset);
    my_clock_destroy(clock);
}

Test(my_clock_continue, null_given)
{
    my_clock_t *clock = my_clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    my_clock_start(clock);
    offset += sleep(3);
    my_clock_stop(clock);
    sleep(3);
    my_clock_continue(NULL);
    offset += sleep(2);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 3 + offset);
    my_clock_destroy(clock);
}
