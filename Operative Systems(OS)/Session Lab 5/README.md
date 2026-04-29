# Signal Handling and Process Control in C

Systems programming project demonstrating signal management and asynchronous execution using Unix signals in C.

## Overview

This project explores how operating systems handle asynchronous events using signals and how processes can react to them dynamically.

## Features

### Signal Handling

- Use of `signal()` and `sigaction()`
- Handling multiple signals:
  - SIGINT (Ctrl+C)
  - SIGALRM (timers)
  - SIGUSR1 (custom signals)

### Process Control

- Interaction between processes using signals
- Runtime control of execution flow
- Handling interruptions during blocking calls

### Monte Carlo Simulation

- π estimation using random sampling (`pimc.c`, `pimc1.c`, `pimc2.c`, `pimc3.c`)
- Execution controlled by signals
- Real-time monitoring of simulation progress

### Asynchronous Programming

- Signal-driven execution
- Timed events using `alarm()`
- Handling system interruptions safely

### Example Programs

- `ejemplo1.c` → basic signal handling
- `ejemplo2.c` → signal interaction
- `ejemplo3.c` → advanced signal usage
- `ejemplo4.c` → signal + process behaviour
- `ejemplo5.c` → signal handling with blocking calls

## Concepts Covered

- Unix signals
- Asynchronous events
- Process interruption
- Signal handlers
- Timers and alarms
- Concurrent behaviour
- Monte Carlo simulation

## Technologies

- C
- POSIX signals
- Linux / Unix systems
