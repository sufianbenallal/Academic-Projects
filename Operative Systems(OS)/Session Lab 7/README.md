# Process Creation and Execution in C

Systems programming project demonstrating how operating systems manage processes using low-level system calls.

## Overview

This project explores the lifecycle of processes in Unix-like systems, including creation, execution and synchronization.

## Features

### Process Creation

- Use of `fork()` to create child processes
- Parent-child process relationships
- Parallel execution

### Program Execution

- Use of `exec()` family to replace process image
- Execution of external programs from within processes

### Process Synchronization

- Use of `wait()` and `waitpid()`
- Parent process waiting for child termination
- Exit status handling

### Example Programs

- `ejemplo1.c` → basic fork usage
- `ejemplo2.c` → fork + exec
- `ejemplo3.c` → multiple processes
- `ejemplo4.c` → synchronization with wait

## Concepts Covered

- Process lifecycle
- Fork-exec model
- Process hierarchy
- Synchronization
- System calls
- Unix process model

## Technologies

- C
- POSIX system calls
- Linux / Unix
