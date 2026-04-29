# File I/O and Inter-Process Communication in C

Systems programming project demonstrating low-level file operations and inter-process communication using Unix system calls.

## Overview

This project explores how operating systems manage files and how processes communicate and synchronize using classic IPC patterns.

## Features

### File Management (Low-Level I/O)

- File creation using `open()`
- File reading using `read()`
- File writing using `write()`
- File access verification using `access()`
- Manual management of file descriptors

### File Operations Examples

- `ejemplo1_create.c` → file creation
- `ejemplo1_read.c` → reading from files
- `ejemplo1_write.c` → writing to files
- `ejemplo2_create.c` → advanced file creation
- `ejemplo2_acc.c` → access permission checking

### Inter-Process Communication (IPC)

- Producer-consumer model implementation
- Synchronization between processes
- Data exchange between producer and consumer

### Producer-Consumer System

- `ejemplo5_prod.c` → producer process
- `ejemplo5_cons.c` → consumer process
- Shared logic defined in headers

### Build System

- Makefile for compilation and execution
- Modular program structure

## Concepts Covered

- Low-level file I/O
- File descriptors
- System calls (`open`, `read`, `write`, `access`)
- Inter-process communication (IPC)
- Producer-consumer pattern
- Process synchronization
- Unix systems programming

## Technologies

- C
- POSIX system calls
- Linux / Unix
