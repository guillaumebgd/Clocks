/*
// Solo Project - C Library
// My_clock_C_Library
// File description:
// Tests the my_clock_stop() function.
*/

#include <criterion/criterion.h>
#include "my_clock.h"

Test(my_clock_stop, easy_stop)
{
    my_clock_t *clock = my_clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    cr_expect(my_clock_start(clock));
    offset += sleep(3);
    my_clock_stop(clock);
    sleep(5);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 3 + offset);
    my_clock_destroy(clock);
}

Test(my_clock_stop, null_given)
{
    my_clock_t *clock = my_clock_create();
    int offset = 0;

    cr_assert_neq(clock, NULL);
    cr_expect(my_clock_start(clock));
    offset += sleep(3);
    my_clock_stop(NULL);
    offset += sleep(5);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 8 + offset);
    my_clock_destroy(clock);
}
