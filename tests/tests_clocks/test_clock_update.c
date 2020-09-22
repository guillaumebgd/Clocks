/*
// Solo Project - C Library
// Clocks
// File description:
// Tests the clock_update() function.
*/

#include <criterion/criterion.h>
#include "clocks.h"

Test(clock_update, no_changes_needed)
{
    t_clock *clock = clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 2;
    clock->minutes = 10;
    clock->seconds = 50;
    clock_update(clock);
    cr_expect_eq(clock->hours, 2);
    cr_expect_eq(clock->minutes, 10);
    cr_expect_eq(clock->seconds, 50);
    clock_destroy(clock);
}

Test(clock_update, seconds_overflow)
{
    t_clock *clock = clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 0;
    clock->minutes = 0;
    clock->seconds = 180;
    clock_update(clock);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 3);
    cr_expect_eq(clock->seconds, 0);
    clock_destroy(clock);
}

Test(clock_update, seconds_overflow_plus_one)
{
    t_clock *clock = clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 0;
    clock->minutes = 0;
    clock->seconds = 181;
    clock_update(clock);
    cr_expect_eq(clock->hours, 0);
    cr_expect_eq(clock->minutes, 3);
    cr_expect_eq(clock->seconds, 1);
    clock_destroy(clock);
}

Test(clock_update, minutes_overflow)
{
    t_clock *clock = clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 0;
    clock->minutes = 60;
    clock->seconds = 10;
    clock_update(clock);
    cr_expect_eq(clock->hours, 1);
    cr_expect_eq(clock->minutes, 0);
    cr_expect_eq(clock->seconds, 10);
    clock_destroy(clock);
}

Test(clock_update, minutes_overflow_plus_one)
{
    t_clock *clock = clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 0;
    clock->minutes = 61;
    clock->seconds = 10;
    clock_update(clock);
    cr_expect_eq(clock->hours, 1);
    cr_expect_eq(clock->minutes, 1);
    cr_expect_eq(clock->seconds, 10);
    clock_destroy(clock);
}

Test(clock_update, seconds_and_minutes_overflow)
{
    t_clock *clock = clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 5;
    clock->minutes = 192;
    clock->seconds = 78;
    clock_update(clock);
    cr_expect_eq(clock->hours, 8);
    cr_expect_eq(clock->minutes, 13);
    cr_expect_eq(clock->seconds, 18);
    clock_destroy(clock);
}

Test(clock_update, null_given)
{
    t_clock *clock = clock_create();

    cr_assert_neq(clock, NULL);
    clock->hours = 5;
    clock->minutes = 192;
    clock->seconds = 78;
    clock_update(NULL);
    cr_expect_eq(clock->hours, 5);
    cr_expect_eq(clock->minutes, 192);
    cr_expect_eq(clock->seconds, 78);
    clock_destroy(clock);
}
