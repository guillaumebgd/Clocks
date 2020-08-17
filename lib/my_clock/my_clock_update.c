/*
// Solo Project C Library
// My_clock_C_Library
// File description:
// Updates data of a 'my_clock'.
*/

#include "my_clock.h"

void my_clock_update(my_clock_t *my_clock)
{
    if (!my_clock)
        return;
    if (my_clock->seconds >= 60) {
        my_clock->minutes += my_clock->seconds / 60;
        my_clock->seconds %= 60;
    }
    if (my_clock->minutes >= 60) {
        my_clock->hours += my_clock->minutes / 60;
        my_clock->minutes %= 60;
    }
}
