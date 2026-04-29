# File Sorting and Memory Mapping in C

Systems programming project comparing traditional file I/O with memory-mapped file access for efficient data processing.

## Overview

This project implements sorting algorithms on binary data stored in files, using two different approaches:

- Standard file access (`read`, `write`)
- Memory-mapped files (`mmap`)

The goal is to analyse performance differences and understand how operating systems manage file access and virtual memory.

## Features

### File-Based Data Processing

- Sorting records stored in binary files
- Handling structured data (`evaluation`)
- Reading and writing using file descriptors

### Standard I/O Implementation

- `gradesort_std.c`
- Uses `read()`, `write()`, `lseek()`
- Explicit file management

### Memory-Mapped Implementation

- `gradesort_mmap.c`
- Uses `mmap()` for direct memory access
- Faster access through virtual memory

### Utility Programs

- `filesort.c` → sorting logic
- `showgrades.c` → display file contents
- Additional examples:
  - `ejemplo1.c`, `ejemplo2.c` → file handling basics
  - `ejemplo1_add.c`, `ejemplo1_uchar.c` → data manipulation
  - `ejemplo2_readall.c` → full file reading

## Concepts Covered

- File descriptors
- Low-level file I/O (`read`, `write`, `lseek`)
- Memory mapping (`mmap`)
- Virtual memory
- Binary file processing
- Performance comparison
- Data structures in files

## Technologies

- C
- POSIX system calls
- mmap (memory mapping)
- Linux / Unix
