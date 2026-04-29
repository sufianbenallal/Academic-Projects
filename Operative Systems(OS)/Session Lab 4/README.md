# Process Management and Concurrency in C

Systems programming project demonstrating process creation, execution and synchronization in Unix-like environments using low-level system calls.

## Overview

This project explores fundamental operating system concepts such as process creation, execution and coordination using C and POSIX system calls.

## Features

### Process Creation
- Use of `fork()` to create child processes
- Parent-child process relationships
- Parallel execution of processes

### Program Execution
- Use of `exec()` family to replace process image
- Running external programs from within a process

### Process Synchronization
- Use of `wait()` and `waitpid()` to manage child processes
- Detection of process termination
- Handling multiple child processes

### Race Simulation

- Multi-process simulation (`race.c`)
- Each process represents a participant
- Demonstrates concurrent execution and scheduling behaviour

### Modular Design

- `player.c / player.h` → player abstraction for simulation
- Multiple examples (`ejemplo1.c` … `ejemplo6.c`) showing different OS concepts

## Concepts Covered

- Process lifecycle
- Fork-exec model
- Parent-child synchronization
- Concurrent execution
- Scheduling behaviour
- Systems programming in Unix

## Technologies

- C
- POSIX system calls
- Linux / Unix environment
