/*
// Solo Project - C Library
// Clocks
// File description:
// Starts the counter of a "clock".
*/

#include <stdio.h>
#include "clocks.h"

int clock_start(t_clock *clock)
{
    if (!clock)
        return (0);
    return (pthread_create(&(clock->assigned_thread), &(clock->thread_attr),
                            __clock_counting, clock) == 0);
}
