/*
// Solo Project - C Library
// My_clock_C_Library
// File description:
// Restarts data of a "my_clock".
*/

#include "my_clock.h"

void my_clock_restart(my_clock_t *my_clock)
{
    if (!my_clock)
        return;
    my_clock->hours = 0;
    my_clock->minutes = 0;
    my_clock->seconds = 0;
    my_clock->communicator = 'c';
}
