/*
// Solo Project - C Library
// Clocks
// File description:
// Restarts data of a "clock".
*/

#include "clocks.h"

void clock_restart(t_clock *clock)
{
    if (!clock)
        return;
    clock->hours = 0;
    clock->minutes = 0;
    clock->seconds = 0;
    clock->communicator = 'c';
}
