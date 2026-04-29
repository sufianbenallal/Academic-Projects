# Parallel Blockchain Mining System in C

Systems programming project simulating blockchain mining using SHA-256 hashing and multi-process parallel execution.

## Overview

This project implements a simplified blockchain mining system where processes search for a valid nonce that satisfies a given hash difficulty condition.

It explores CPU-intensive computation, parallelism and process coordination in Unix environments.

## Features

### Hash-Based Mining

- SHA-256 hashing using OpenSSL
- Block validation with difficulty constraint
- Nonce brute-force search

### Single-Process Mining

- Sequential search for valid nonce (`foominer.c`)
- Hash computation and validation
- Performance baseline

### Multi-Process Mining

- Parallel mining using multiple processes (`foominer_mp.c`)
- Workload distribution among processes
- Early termination when solution is found
- Process coordination and synchronization

### Block Verification

- Independent verification tool (`fooblockcheck.c`)
- Ensures correctness of mined blocks

### Modular Design

- `foominerlib.c / .h` → hashing and mining utilities
- Separation between mining logic and validation

## Concepts Covered

- Parallel computing
- Multi-process programming (`fork`)
- CPU-bound optimisation
- Cryptographic hashing (SHA-256)
- Work distribution
- Process coordination and termination
- Performance improvement through parallelism

## Technologies

- C
- POSIX processes
- OpenSSL (SHA-256)
- Linux / Unix systems
