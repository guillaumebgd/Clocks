***

# Clocks - C Library

A little C library that allows you to launch clocks alongside the main track of your project.<br>

Clocks are launched on different detached threads and this library wraps thread processings.<br>

## Table of Contents

To work with clocks, you will need to use the structure below. (defined at <code>include/clocks/clocks.h:32</code>)<br>

```C
typedef struct s_clock {
    _Atomic unsigned char communicator;
    pthread_t assigned_thread;
    pthread_attr_t thread_attr;
    _Atomic unsigned int seconds;
    _Atomic unsigned int minutes;
    _Atomic unsigned long long hours;
} t_clock;
```

The only important variables of the data structure, as a user of the library, are the __*timer variables*__:<br>

* <code>_Atomic unsigned int seconds</code> (This variable is an <code>unsigned int</code>.)
* <code>_Atomic unsigned int minutes</code> (This variable is an <code>unsigned int</code>.)
* <code>_Atomic unsigned long long hours</code> (This variable is a <code>long long unsigned int</code>.)

After launching a clock alongside your main track, the timer will be constantly updating
stacks of 60 <code>seconds</code> to <code>minutes</code> and stacks of 60 <code>minutes</code> to <code>hours</code>.

---

```C
t_clock *clock_create(void);
```

Allocates memory for a new pointer onto a <code>clock</code>.<br>
Initializes the __*timer variables*__ and to <code>0</code>.<br>

---

```C
int clock_start(t_clock *clock);
```

Starts the counter of a given initialized <code>clock</code> onto a new detached thread.<br>
The __*timer variables*__ will start incrementing as <code>seconds</code> pass and
increment <code>minutes</code> and <code>hours</code> when needed.<br>

Returns (<code>1</code>) on success.<br>
Returns (<code>0</code>) on failure.<br>

---

```C
void clock_update(t_clock *clock);
```

Redistributes the overflow of time stored in <code>seconds</code> and in <code>minutes</code>
respectively to <code>minutes</code> and to <code>hours</code>.<br>

The overflow of time describes the excess above <code>60 seconds</code> or <code>60 minutes</code>.<br>
That amount of time can be stored into the higher storage variable.<br>

---

```C
void clock_stop(t_clock *clock);
```

Freezes a given <code>clock</code>'s counter.<br>
It can be brought back to normal by using the <code>clock_continue</code> or the <code>clock_restart</code> functions.

---

```C
void clock_continue(t_clock *clock);
```

A <code>clock</code>'s counter can be frozen using the <code>clock_stop</code> function.<br>
Unfreezes a given <code>clock</code>'s counter.<br>

---

```C
void clock_restart(t_clock *clock);
```

Resets the __*timer variables*__ of a given <code>clock</code> to <code>0</code> and then
unfreezes a given <code>clock</code>'s counter.<br>

---

```C
void clock_destroy(t_clock *clock);
```

Frees allocated memory given to a <code>clock</code> and its thread.<br>

---

##

Thanks for reading about my work !

This project has been made to make me discover threads in C.
