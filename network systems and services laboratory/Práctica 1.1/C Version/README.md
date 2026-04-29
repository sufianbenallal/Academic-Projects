## C Implementation (Low-Level)

This version of the project is developed in C using POSIX sockets, providing full control over network communication at a low level.

### Features

- TCP client/server implementation using stream sockets
- UDP client/server implementation using datagram sockets
- Manual socket creation, binding, listening and data transmission
- RTT (Round Trip Time) measurement for performance analysis
- Timeout handling and basic error control
- Direct interaction with the operating system networking stack

### Files

- `TCP_cliente.c` → TCP client
- `TCP_servidor.c` → TCP server
- `UDP_cliente.c` → UDP client
- `UDP_servidor.c` → UDP server

### Concepts Covered

- POSIX socket programming
- TCP vs UDP protocol behavior
- Client-server architecture
- Network performance measurement (RTT)
- Low-level memory and resource management
