/*
// Solo Project - C Library
// Clocks
// File description:
// Updates data of a 'clock'.
*/

#include "clocks.h"

void clock_update(t_clock *clock)
{
    if (!clock)
        return;
    if (clock->seconds >= 60) {
        clock->minutes += clock->seconds / 60;
        clock->seconds %= 60;
    }
    if (clock->minutes >= 60) {
        clock->hours += clock->minutes / 60;
        clock->minutes %= 60;
    }
}
