# Advanced Insurance Management System in C++

Improved and extended version of an insurance management system developed in C++, focusing on advanced object-oriented design, data structures and system scalability.

## Improvements Over Previous Version

- Refined class hierarchy with better use of inheritance and polymorphism
- Improved interaction between entities (clients, contracts, claims and companies)
- Enhanced modular architecture with clearer separation of responsibilities
- Optimized linked list implementation for dynamic data management
- Better memory management and code organization
- Increased scalability and maintainability of the system
- Cleaner and more structured codebase

## Features

### Entity Management
- Clients (`CCliente`)
- Companies (`CEmpresa`)
- Contracts (`CContrato`)
- Claims:
  - `CSiniestro` (base class)
  - `CSiniestroNormal`
  - `CSiniestroUrgente`

### Advanced OOP Design
- Inheritance and polymorphism for claim handling
- Composition between entities (clients, contracts, records)
- Encapsulation and abstraction

### Data Structures
- Custom linked list implementation:
  - `CLista`
  - `CNodoLista`
- Dynamic storage and data management

### Additional Components
- Record handling (`CFicha`)
- Time management (`CHora`)
- Exception handling (`CIndiceIncorrecto`)
- Utility functions (`utils`)
- Memory management utilities

## Project Structure

- `main.cpp` → Main application
- `CCliente.*` → Client management
- `CEmpresa.*` → Company management
- `CContrato.*` → Contract logic
- `CSiniestro.*` → Base class for claims
- `CSiniestroNormal.*` → Standard claims
- `CSiniestroUrgente.*` → Urgent claims
- `CLista.*` → Linked list implementation
- `CNodoLista.*` → List node
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
- Code refactoring and system evolution

## Technologies

- C++
- Standard Library
