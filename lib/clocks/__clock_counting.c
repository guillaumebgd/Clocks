/*
// Solo Project C Library
// Clocks
// File description:
// Counts seconds by seconds adding it up to a 'clock'.
*/

#include <stdio.h>
#include <stdlib.h>
#include "clocks.h"

static void __clock_free_resources(t_clock *clock)
{
    pthread_attr_destroy(&clock->thread_attr);
    free(clock);
}

void *__clock_counting(void *data)
{
    t_clock *clock = (t_clock *)data;

    if (!data)
        pthread_exit(NULL);
    if (pthread_detach(clock->assigned_thread) != 0) {
        goto end;
    }
    do {
        clock->seconds += 1;
        clock->seconds += sleep(1);
        clock_update(clock);
        if (clock->communicator == 's') {
            while (clock->communicator != 'c' && clock->communicator != 'd');
        }
    } while (clock->communicator != 'd');
    end:
    __clock_free_resources(clock);
    pthread_exit(NULL);
}
