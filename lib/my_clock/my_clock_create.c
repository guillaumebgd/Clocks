/*
// Solo Project C Library
// My_clock_C_Library
// File description:
// Allocates basic data for a 'my_clock'.
*/

#include <stdlib.h>
#include "my_clock.h"

my_clock_t *my_clock_create(void)
{
    my_clock_t *my_clock = malloc(sizeof(my_clock_t));

    if (!my_clock)
        return (NULL);
    (*my_clock) = (my_clock_t){0};
    pthread_attr_init(&my_clock->thread_attr);
    return (my_clock);
}
