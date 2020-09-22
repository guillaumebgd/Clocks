/*
// Solo Project - C Library
// Clocks
// File description:
// Stops a the counter of a 'clock'.
*/

#include "clocks.h"

void clock_stop(t_clock *clock)
{
    if (!clock)
        return;
    clock->communicator = 's';
}
