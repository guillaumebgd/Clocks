/*
// Solo Project - C Library
// Clocks
// File description:
// Header of the Clocks Library
*/

#ifndef CLOCKS_H_

//////////////////////
#include <unistd.h>
#include <pthread.h>
//////////////////////

/////////////////////////////////////////

// This is a typedef of a clock element that can be executed alongside your main program.
//
// The following variables are used for intern library purposes
// and shouldn't be externaly used:
//
// - communicator
// - assigned_thread
// - thread_attr;
//
// Therefore, you can freely manipulate the following variables:
//
// - seconds
// - minutes
// - hours
#include <stdio.h>
typedef struct s_clock {
    _Atomic unsigned char communicator;
    pthread_t assigned_thread;
    pthread_attr_t thread_attr;
    _Atomic unsigned int seconds;
    _Atomic unsigned int minutes;
    _Atomic unsigned long long hours;
} t_clock;

/////////////////////////////////////////

// Counts seconds by seconds, inscribing data onto extern-usable variables of a given 'clock'
// and using its 'communicator'.
//
// - This function shouldn't be used for library users.
void *__clock_counting(void *clock);

/////////////////////////////////////////

// Allocates memory for a new 't_clock' pointer and initializes values.
//
// Returns a newly allocated (t_clock *) on success.
// Returns (NULL) otherwise.
t_clock *clock_create(void);

// Starts a given 'clock' to count.
//
// Returns (1) on success.
// Returns (0) otherwise.
int clock_start(t_clock *clock);

// Updates extern-usable variables data values to logical ranges.
//
// - Seconds -> 0-59.
// - Minutes -> 0-59.
// - Hours -> max unsigned long long.
void clock_update(t_clock *clock);

// Freezes a 'clock' counter.
void clock_stop(t_clock *clock);

// Unfreezes a 'clock' counter.
void clock_continue(t_clock *clock);

// Resets a 'clock' extern-usable variables to 0.
void clock_restart(t_clock *clock);

// Recovers memory allocated to a given 'clock'.
void clock_destroy(t_clock *clock);

/////////////////////////////////////////

#endif /* clock_H_ */
