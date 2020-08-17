/*
// Solo Project - C Library
// My_clock_C_Library
// File description:
// Tests the my_clock_update() function.
*/

#include <criterion/criterion.h>
#include "my_clock.h"

Test(my_clock_update, no_changes_needed)
{
    my_clock_t *clock = my_clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 2;
    clock->minutes = 10;
    clock->seconds = 50;
    my_clock_update(clock);
    cr_expect_eq(clock->hours, 2);
    cr_expect_eq(clock->minutes, 10);
    cr_expect_eq(clock->seconds, 50);
    my_clock_destroy(clock);
}

Test(my_clock_update, seconds_overflow)
{
    my_clock_t *clock = my_clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 0;
    clock->minutes = 0;
    clock->seconds = 180;
    my_clock_update(clock);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 3);
    cr_expect_eq(clock->seconds, 0);
    my_clock_destroy(clock);
}

Test(my_clock_update, seconds_overflow_plus_one)
{
    my_clock_t *clock = my_clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 0;
    clock->minutes = 0;
    clock->seconds = 181;
    my_clock_update(clock);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 3);
    cr_expect_eq(clock->seconds, 1);
    my_clock_destroy(clock);
}

Test(my_clock_update, minutes_overflow)
{
    my_clock_t *clock = my_clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 0;
    clock->minutes = 60;
    clock->seconds = 10;
    my_clock_update(clock);
    cr_expect_eq(clock->hours, 1);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 10);
    my_clock_destroy(clock);
}

Test(my_clock_update, minutes_overflow_plus_one)
{
    my_clock_t *clock = my_clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 0;
    clock->minutes = 61;
    clock->seconds = 10;
    my_clock_update(clock);
    cr_expect_eq(clock->hours, 1);
    cr_expect_eq(clock->minutes, 1);
    cr_expect_eq(clock->seconds, 10);
    my_clock_destroy(clock);
}

Test(my_clock_update, seconds_and_minutes_overflow)
{
    my_clock_t *clock = my_clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 5;
    clock->minutes = 192;
    clock->seconds = 78;
    my_clock_update(clock);
    cr_expect_eq(clock->hours, 8);
    cr_expect_eq(clock->minutes, 13);
    cr_expect_eq(clock->seconds, 18);
    my_clock_destroy(clock);
}

Test(my_clock_update, null_given)
{
    my_clock_t *clock = my_clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 5;
    clock->minutes = 192;
    clock->seconds = 78;
    my_clock_update(NULL);
    cr_expect_eq(clock->hours, 5);
    cr_expect_eq(clock->minutes, 192);
    cr_expect_eq(clock->seconds, 78);
    my_clock_destroy(clock);
}
