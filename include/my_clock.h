/*
// Solo Project C Library
// My_clock_C_Library
// File description:
// Header of the My_clock C Library
*/

#ifndef MY_CLOCK_H_

//////////////////////
#include <unistd.h>
#include <pthread.h>
#include <stdatomic.h>
//////////////////////

/////////////////////////////////////////

// This is a typedef of a clock element that can be executed alongside your main program.
//
// The following variables are used for intern library purposes
// and shouldn't be externaly used:
//
// - atomic_char communicator;
// - pthread_t assigned_thread;
// - pthread_attr_t thread_attr;
//
// Therefore, you can freely manipulate the following variables:
//
// - atomic_uint seconds;
// - atomic_uint minutes;
// - atomic_ullong hours;
typedef struct my_clock_s {
    atomic_char communicator;
    pthread_t assigned_thread;
    pthread_attr_t thread_attr;
    atomic_uint seconds;
    atomic_uint minutes;
    atomic_ullong hours;
} my_clock_t;

/////////////////////////////////////////

// Counts seconds by seconds, inscribing data onto extern-usable variables of a given 'my_clock'
// and using the 'communicator'.
//
// - This function shouldn't be used for library users.
void *__my_clock_counting(void *my_clock);

/////////////////////////////////////////

// Allocates memory for a new 'my_clock_t' pointer and initializes values.
my_clock_t *my_clock_create(void);

// Starts a given 'my_clock'.
void my_clock_start(my_clock_t *my_clock);

// Updates extern-usable variables data values to the reable.
//
// - Hours -> long long unsigned limit.
// - Minutes -> 0-59.
// - Seconds -> 0-59.
void my_clock_update(my_clock_t *my_clock);

// Freezes a 'my_clock' counter.
void my_clock_stop(my_clock_t *my_clock);

// Defreezes a 'my_clock' counter.
void my_clock_continue(my_clock_t *my_clock);

// Resets a 'my_clock' extern-usable variables to 0.
void my_clock_restart(my_clock_t *my_clock);

// Recovers memory allocated to a given 'my_clock'.
void my_clock_destroy(my_clock_t *my_clock);

/////////////////////////////////////////

#endif /* MY_CLOCK_H_ */
