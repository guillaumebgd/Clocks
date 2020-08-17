/*
// Solo Project - C Library
// My_clock_C_Library
// File description:
// Starts a "my_clock".
*/

#include <stdio.h>
#include "my_clock.h"

void my_clock_start(my_clock_t *my_clock)
{
    if (!my_clock)
        return;
    pthread_create(&(my_clock->assigned_thread), &(my_clock->thread_attr), __my_clock_counting, my_clock);
}
