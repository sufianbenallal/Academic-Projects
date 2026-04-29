# Multithreaded Numerical Integration in C

High-performance computing project implementing numerical integration in C with both sequential and parallel (multithreaded) approaches.

## Overview

This project computes the value of π using numerical integration techniques, comparing a single-threaded implementation with a parallel version using POSIX threads.

## Features

### Numerical Integration

- Implementation of trapezoidal integration method
- Modular function definitions (`integrate.c`, `f1.c`, `f2.c`)
- Support for different mathematical functions

### Multithreading

- Parallel computation using `pthread`
- Workload distribution across multiple threads
- Thread coordination and result aggregation

### Performance Comparison

- Sequential vs parallel execution (`picalc.c` vs `picalc_mt.c`)
- Execution time measurement
- Performance improvement through concurrency

### Modular Design

- `integrate.c / .h` → integration logic
- `integrate_mt.c / .h` → multithreaded version
- `picalc.c` → sequential program
- `picalc_mt.c` → parallel program
- `f1.c`, `f2.c` → functions to integrate

### Build System

- Makefile for compilation and testing
- Support for multiple executables

## Concepts Covered

- Parallel programming
- Multithreading (pthreads)
- Work distribution
- Synchronization
- Numerical methods
- Performance optimisation
- CPU-bound computation

## Technologies

- C
- POSIX threads (pthread)
- Linux / Unix
- GCC / Makefile
