/*
// Solo Project - C Library
// Clocks
// File description:
// Continues a the counter of a 'clock'.
*/

#include "clocks.h"

void clock_continue(t_clock *clock)
{
    if (!clock)
        return;
    clock->communicator = 'c';
}
