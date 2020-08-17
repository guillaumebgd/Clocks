/*
// Solo Project C Library
// My_clock_C_Library
// File description:
// Stops a "my_clock".
*/

#include "my_clock.h"

void my_clock_stop(my_clock_t *my_clock)
{
    if (!my_clock)
        return;
    my_clock->communicator = 's';
}
