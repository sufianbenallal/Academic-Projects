# IoT Smart Room System (Full Stack)

Full-stack IoT simulation system that integrates sensors, backend processing, database storage and web-based control interface.

## Architecture

- Sensor Emulator (REST API)
- Backend Server (Flask)
- Database (MySQL)
- Frontend Interface (HTML, CSS, JavaScript)
- Data Processing Scripts

## Project Components

### Backend (Flask)

- Main server application :contentReference[oaicite:0]{index=0}
- REST endpoints for:
  - Sensor data streaming (SSE)
  - User authentication
  - URL shortening service
  - Light control

### Sensor Emulator (IoT Simulation)

- REST API simulating sensors (temperature, humidity, etc.) :contentReference[oaicite:1]{index=1}

### Data Processing

- Sensor data collection and database insertion :contentReference[oaicite:2]{index=2}  
- Database insertion script :contentReference[oaicite:3]{index=3}  

### Frontend

- Dynamic UI with AJAX and jQuery :contentReference[oaicite:4]{index=4}  
- Custom styling :contentReference[oaicite:5]{index=5}  

## Features

### IoT Simulation
- Real-time sensor data generation (temperature, humidity, light, sound, motion)
- Continuous polling and updates
- Actuator control (RGB lighting system)

### Backend System
- Flask web server
- RESTful API design
- Server-Sent Events (SSE) for real-time updates
- Session-based authentication system

### Database Integration
- MySQL database for sensor storage
- Real-time data insertion and querying
- Historical sensor tracking

### Frontend Interaction
- AJAX communication with backend
- Dynamic UI updates
- Color control interface for lighting
- Real-time visualization

### Advanced Features
- URL shortener service
- Authentication system (login/logout)
- API-based communication between components

## Technologies

- Python
- Flask
- Flask-RESTful
- MySQL
- HTML5 / CSS3
- JavaScript / jQuery
- AJAX
- REST APIs

## Key Concepts

- IoT architecture
- Client-server communication
- RESTful services
- Real-time data streaming (SSE)
- Database integration
- Backend + frontend integration
