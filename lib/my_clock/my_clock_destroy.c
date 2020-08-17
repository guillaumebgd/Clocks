/*
// Solo Project C Library
// My_clock_C_Library
// File description:
// Recovers memory allocated to a 'my_clock'.
*/

#include <stdlib.h>
#include "my_clock.h"

void my_clock_destroy(my_clock_t *my_clock)
{
    if (!my_clock)
        return;
    my_clock->communicator = 'd';
}
