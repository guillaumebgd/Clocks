***

# My Clock - C Library

A little C library that allows you to launch clocks alongside the main track of your project.<br>

Clocks are launched on different detached threads and this library wraps thread processings.<br>

## Table of Contents

To work with clocks, you will need to use the structure below. (defined at <code>include/my_clock.h:32</code>)<br>

```C
typedef struct my_clock_s {
    atomic_char communicator;
    pthread_t assigned_thread;
    pthread_attr_t thread_attr;
    atomic_uint seconds;
    atomic_uint minutes;
    atomic_ullong hours;
} my_clock_t;
```

The only important variables of the data structure, as a user of the library, are the __*timer variables*__:<br>

* <code>atomic_uint seconds</code> (This variable is an <code>unsigned int</code>.)
* <code>atomic_uint minutes</code> (This variable is an <code>unsigned int</code>.)
* <code>atomic_ullong hours</code> (This variable is a <code>long long unsigned int</code>.)

After launching a clock alongside your main track, the timer will be constantly updating
stacks of 60 <code>seconds</code> to <code>minutes</code> and stacks of 60 <code>minutes</code> to <code>hours</code>.

---

```C
my_clock_t *my_clock_create(void);
```

Allocates memory for a new pointer onto a <code>my_clock</code>.<br>
Initializes the __*timer variables*__ and to <code>0</code>.<br>

---

```C
void my_clock_start(my_clock_t *my_clock);
```

Starts the counter of a given initialized <code>my_clock</code> onto a new detached thread.<br>
The __*timer variables*__ will start incrementing as <code>seconds</code> pass and
increment <code>minutes</code> and <code>hours</code> when needed.<br>

---

```C
void my_clock_update(my_clock_t *my_clock);
```

Redistributes the overflow of time stored in <code>seconds</code> and in <code>minutes</code>
respectively to <code>minutes</code> and to <code>hours</code>.<br>

The overflow of time describes the excess above <code>60 seconds</code> or <code>60 minutes</code>.<br>
That amount of time can be stored into the higher storage variable.<br>

---

```C
void my_clock_stop(my_clock_t *my_clock);
```

Freezes a given <code>my_clock</code>'s counter.<br>
It can be brought back to normal by using the <code>my_clock_continue</code> or the <code>my_clock_restart</code> functions.

---

```C
void my_clock_continue(my_clock_t *my_clock);
```

A <code>my_clock</code>'s counter can be frozen using the <code>my_clock_stop</code> function.<br>
Defreezes a given <code>my_clock</code>'s counter.<br>

---

```C
void my_clock_restart(my_clock_t *my_clock);
```

Resets the __*timer variables*__ of a given <code>my_clock</code> to <code>0</code> and then
defreezes a given <code>my_clock</code>'s counter.<br>

---

```C
void my_clock_destroy(my_clock_t *my_clock);
```

Frees allocated memory given to a <code>my_clock</code> and its thread.<br>

---

##

Thanks for reading about my work !

This project has been made to make me discover threads in C.
