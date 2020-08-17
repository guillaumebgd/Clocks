/*
// Solo Project C Library
// My_clock_C_Library
// File description:
// Main function of the my_clock.
*/

#include <stdio.h>
#include "my_clock.h"

int main(void)
{
    my_clock_t *clock = my_clock_create();

    my_clock_start(clock);
    sleep(3);
    my_clock_stop(clock);
    sleep(3);
    my_clock_restart(clock);
    sleep(4);
    printf("Hours = %llu\n", clock->hours);
    printf("Minutes = %lu\n", clock->minutes);
    printf("Seconds = %lu\n", clock->seconds);
    my_clock_destroy(clock);
    return (0);
}
