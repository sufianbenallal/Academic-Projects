# Hybrid P2P Chat and File Sharing System in Python

Distributed communication system implemented in Python using a hybrid P2P architecture with a central server for user registration and direct peer-to-peer connections for communication.

## Architecture

- Central server → manages user authentication and peer discovery
- Peer nodes → connect directly to each other for communication
- Fully distributed messaging after registration

## Features

### User Management
- Authentication system with predefined users :contentReference[oaicite:0]{index=0}
- Peer registration and discovery
- Dynamic peer list distribution

### Communication
- Real-time messaging between peers
- Broadcast messages
- Private messaging using commands (`/w user message`)

### File Transfer
- Send and receive files between peers
- Chunk-based file transmission
- Automatic file reconstruction

### Concurrency
- Non-blocking sockets
- Multiple connections handled with `select`
- Simultaneous input/output handling

### Network Design
- Hybrid architecture (centralized + P2P)
- Dynamic peer connections
- Incoming and outgoing connection handling :contentReference[oaicite:1]{index=1}

## Components

### Central Server
- `servidor_usuarios.py` → user registration and authentication

### Communication Server
- `servidor.py` → message broadcasting server :contentReference[oaicite:2]{index=2}

### Peer System
- `peer.py` → P2P communication node :contentReference[oaicite:3]{index=3}
- `cliente.py` → client interface and messaging :contentReference[oaicite:4]{index=4}

## Concepts Covered

- Socket programming in Python
- Distributed systems (P2P architecture)
- Client-server and peer-to-peer models
- Concurrency with select
- File transfer protocols
- User authentication
- Network protocol design

## Technologies

- Python
- Sockets
- Select (non-blocking I/O)
