# Custom HTTP Web Server in Python

Fully functional web server developed from scratch in Python using sockets and select, implementing core HTTP features and advanced functionalities.

## Features

### HTTP Protocol Support
- GET, POST, DELETE, HEAD methods
- Custom HTTP response handling
- MIME type detection

### Server Functionality
- Concurrent client handling using `select`
- Persistent and non-persistent connections
- Timeout and inactivity management

### Security
- HTTPS support using SSL
- Basic authentication for protected routes (`/admin`)
- Access control with credentials

### Dynamic Content
- Real-time request logging
- Dynamic HTML generation
- Logs visualization via web interface
- POST data storage

### File Handling
- Static file serving (HTML, CSS, images, video)
- File deletion via DELETE method
- File upload via POST

### Frontend Integration
- Custom HTML interface :contentReference[oaicite:0]{index=0}
- Admin panel with logs visualization :contentReference[oaicite:1]{index=1}
- Styled UI using CSS :contentReference[oaicite:2]{index=2}

## Project Structure

- `servidor_web.py` → Main server logic
- `index.html` → Main interface
- `admin.html` → Admin panel
- `style.css` → Styling
- Static files (images, video, logs)

## Concepts Covered

- Socket programming (low-level)
- HTTP protocol implementation
- Concurrent programming (select)
- Web server architecture
- Authentication and security (HTTPS, Basic Auth)
- File system interaction
- Dynamic content generation

## Technologies

- Python
- Sockets
- SSL/TLS
- HTML / CSS / JavaScript
