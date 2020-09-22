/*
// Solo Project - C Library
// Clocks
// File description:
// Allocates basic data for a 'clock'.
*/

#include <stdlib.h>
#include "clocks.h"

t_clock *clock_create(void)
{
    t_clock *clock = malloc(sizeof(t_clock));

    if (!clock)
        return (NULL);
    (*clock) = (t_clock){0};
    if (pthread_attr_init(&clock->thread_attr) != 0) {
        free(clock);
        return (NULL);
    }
    return (clock);
}
