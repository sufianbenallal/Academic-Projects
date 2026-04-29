# Student Union Management System (SUMS)

Software Engineering project focused on the design and modelling of a modern distributed application for managing university student unions.

## Overview

This project presents the analysis and design of the Student Union Management System (SUMS), a subsystem responsible for managing student societies, memberships and union events within a university environment.

The work follows a full software engineering lifecycle, from requirements analysis to architectural and detailed design.

## Key Features

### Functional Requirement

- Approve New Society workflow
- Union Officer reviews, validates and approves/rejects applications
- Integration with external systems (notifications, identity, federation)

## Software Engineering Approach

### Requirements Engineering

- Functional requirements defined and analysed
- Quality requirements specified:
  - Security (RBAC, 2FA, audit logging)
  - Performance (≤2s response time)
  - Reliability (atomic transactions, consistency)
  - Scalability (up to 50,000 records, distributed systems)

📌 Example: Only authorised Union Officers can approve applications (role-based access control) :contentReference[oaicite:0]{index=0}

---

### UML Modelling

The system was designed using UML diagrams:

#### Use Case Diagram
- Defines interactions between Union Officer and system
- Covers membership, society and event management

#### Activity Diagram
- Models the approval workflow:
  - Validate application
  - Approve / Reject
  - Request additional information

#### Class Diagram
- Core entities:
  - SocietyApplication
  - SocietyApprovalService
  - Officer
  - NotificationAdapter
  - AuditLogger

#### Sequence Diagram
- Describes full approval flow:
  - Retrieve application
  - Update status
  - Persist changes
  - Send notifications
  - Log decision

---

### Software Architecture

The system follows a **service-oriented architecture**:

- IdentityService → authentication
- UnionOfficerPortal → user interface
- SocietyApprovalService → core business logic
- SocietyRegistry / UnionDatabase → persistence
- NotificationAdapter → external communication
- AuditLogger → traceability

📌 Architecture separates concerns for scalability and maintainability :contentReference[oaicite:1]{index=1}

---

### Key Design Principles

- Separation of concerns
- Modularity
- Scalability
- Service-based communication
- Clean interaction between components

---

### Technologies & Tools

- UML (Papyrus)
- Model-driven engineering
- Software architecture design
- System modelling tools

---

## Results

- Complete system design from requirements to implementation-ready models
- Fully consistent UML diagrams (structural + behavioural)
- Scalable architecture ready for cloud-based deployment
