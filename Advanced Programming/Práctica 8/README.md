# Insurance Management System in C++

Complete C++ application that models an insurance management system using advanced object-oriented programming and custom data structures.

## Features

### Entity Management
- Clients (`CCliente`)
- Companies (`CEmpresa`)
- Contracts (`CContrato`)
- Claims (`CSiniestro`, `CSiniestroNormal`, `CSiniestroUrgente`)

### Advanced Data Structures
- Custom linked list implementation:
  - `CLista`
  - `CNodoLista`
- Dynamic data storage and management

### Object-Oriented Design
- Class hierarchy and inheritance:
  - Base class: `CSiniestro`
  - Derived classes: `CSiniestroNormal`, `CSiniestroUrgente`
- Composition between entities (clients, contracts, records)

### System Features
- Record and data management (`CFicha`)
- Time handling (`CHora`)
- Exception handling (`CIndiceIncorrecto`)
- Utility functions (`utils`)

## Project Structure

- `main.cpp` → Main application
- `CCliente.*` → Client management
- `CEmpresa.*` → Company management
- `CContrato.*` → Contract logic
- `CSiniestro.*` → Claim system (base class)
- `CSiniestroNormal.*` → Standard claims
- `CSiniestroUrgente.*` → Urgent claims
- `CLista.*` → Custom linked list
- `CNodoLista.*` → List node implementation
- `CFicha.*` → Data structure
- `CHora.*` → Time handling
- `utils.*` → Helper functions
- `MemoryManager.h` → Memory utilities

## Concepts Covered

- Advanced Object-Oriented Programming (OOP)
- Inheritance and polymorphism
- Data modeling and system design
- Custom data structures (linked lists)
- Dynamic memory management
- Exception handling
- Modular architecture
- Real-world system simulation

## Technologies

- C++
- Standard Library
