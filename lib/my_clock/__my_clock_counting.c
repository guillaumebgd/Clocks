/*
// Solo Project C Library
// My_clock_C_Library
// File description:
// Counts seconds by seconds and adds up to a 'my_clock'.
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_clock.h"

void *__my_clock_counting(void *data)
{
    my_clock_t *my_clock = (my_clock_t *)data;

    pthread_detach(my_clock->assigned_thread);
    do {
        my_clock->seconds += 1;
        my_clock->seconds += sleep(1);
        my_clock_update(my_clock);
        if (my_clock->communicator == 's') {
            while (my_clock->communicator != 'c' && my_clock->communicator != 'd');
        }
    } while (my_clock->communicator != 'd');
    pthread_attr_destroy(&my_clock->thread_attr);
    free(my_clock);
    pthread_exit(NULL);
}