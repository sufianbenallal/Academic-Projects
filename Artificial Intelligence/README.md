# AI Pathfinding and Logic-Based Route Planning

Advanced Artificial Intelligence project implementing and analysing pathfinding algorithms on real-world road networks using OpenStreetMap data.

## Overview

This project explores algorithmic problem solving, optimisation and logic-based reasoning applied to route planning. It combines classical graph search algorithms with AI techniques such as heuristics, constraint satisfaction and logical inference.

## Features

### Pathfinding Algorithms

- Dijkstra (baseline, optimal)
- A* (heuristic-based optimal search)
- Greedy Best-First Search (fast but non-optimal)

All algorithms were implemented using priority queues and evaluated on a real road network graph.

## Real-World Data

- Graph generated using OSMnx from OpenStreetMap :contentReference[oaicite:0]{index=0}
- ~3,388 nodes and ~7,539 edges representing a real city network :contentReference[oaicite:1]{index=1}

## Performance Analysis

Algorithms were compared using:

- Nodes visited
- Path length
- Execution time
- Memory usage
- Optimality ratio

### Key Results

- Dijkstra & A*: optimal paths (~5679m)
- Greedy BFS: fastest but worst path (~7249m)
- HPA*: near-optimal with much lower computation
- Speedups up to **4000%+** over baseline :contentReference[oaicite:2]{index=2}

## Optimisation Techniques

### Time-Based A*

- Uses travel time instead of distance
- Produces more realistic routes
- Reduces node expansions significantly

### Hierarchical A* (HPA*)

- Restricts search to a corridor subgraph
- Reduces nodes from ~2560 → ~313 :contentReference[oaicite:3]{index=3}
- Maintains near-optimal paths (≈1.03 ratio)

## Logic-Based AI Extension

### Constraint-Based Pathfinding

- Avoid unsafe edges (closed, flood, dangerous)
- Avoid specific nodes (e.g. stadiums)
- Must pass through safe hubs (hospital/police)

Implemented using propositional and predicate logic rules:

- Unsafe(e) → ¬Usable(e)
- Stadium(n) → n ∉ Path
- Must include safe nodes in route

### Logic-Enhanced A*

- Filters unsafe edges during search
- Adds heuristic penalties for risky areas
- Validates path after computation

## Algorithmic Reasoning

### Backtracking (CSP)

- Explores paths recursively
- Guarantees constraint satisfaction
- Limited due to high computational cost on large graphs

### Pattern Matching

- Classifies routes based on:
  - Safety
  - Risk exposure
  - Node types

## Results

- Logic-A* ensures constraint satisfaction with minimal overhead
- HPA* offers best trade-off between speed and optimality
- Demonstrates real-world applicability in navigation systems

## Technologies

- Python
- OSMnx
- NetworkX
- NumPy
- Matplotlib
