/*
// Solo Project - C Library
// Clocks
// File description:
// Recovers memory allocated to a 'clock'.
*/

#include <stdlib.h>
#include "clocks.h"

void clock_destroy(t_clock *clock)
{
    if (!clock)
        return;
    clock->communicator = 'd';
}
