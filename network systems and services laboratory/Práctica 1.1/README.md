# Network Communication System (C & Python)

Client-server network application implemented in both C and Python, supporting TCP and UDP protocols with performance analysis.

## Key Features

### Protocol Support
- TCP client/server implementation
- UDP client/server implementation
- Echo-based communication system

### Dual Implementation
- Low-level implementation in C (manual socket handling)
- High-level implementation in Python (simplified socket API)

### Performance Analysis
- Round Trip Time (RTT) measurement
- Statistical metrics:
  - Minimum RTT
  - Maximum RTT
  - Average RTT

### Network Compatibility
- IPv4 and IPv6 support
- Dynamic socket creation based on IP type

## Project Structure

### C Implementation
- `TCP_cliente.c` → TCP client
- `TCP_servidor.c` → TCP server
- `UDP_cliente.c` → UDP client
- `UDP_servidor.c` → UDP server

### Python Implementation
- `TCP_cliente.py` → TCP client
- `TCP_servidor.py` → TCP server
- `UDP_cliente.py` → UDP client
- `UDP_servidor.py` → UDP server

## Concepts Covered

- Socket programming (C and Python)
- TCP vs UDP communication
- Client-server architecture
- IPv4 / IPv6 networking
- Network performance measurement (RTT)
- Error handling and timeouts
- Cross-language comparison (low-level vs high-level)

## Example (Python TCP Client)

:contentReference[oaicite:0]{index=0}

## Technologies

- C (POSIX sockets)
- Python (socket library)
