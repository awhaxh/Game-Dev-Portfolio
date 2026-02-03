# Purrsuit of Home - Gameplay Systems

Author: Ashley Low  
Role: Gameplay Programmer  
Language: C++  
Project Type: 2D Grid-Based Arcade Game (Crossy Road–style)  
Duration: 13 weeks (Team of 5)

---

## Overview

*Purrsuit of Home* is a grid-based arcade game about guiding a stray cat across hazardous lanes and moving platforms.  

This folder contains **refactored gameplay-system excerpts** written by me for portfolio purposes.  
The original project was developed in a team academic repository and cannot be shared publicly in full.

These samples highlight my work on:

- Grid-based collision systems  
- Frame-independent obstacle movement  
- Moving platform detection and interaction  
- Lightweight, performance-friendly gameplay logic  

---

## Files Included

### `collision_system.cpp`
Demonstrates grid-aligned AABB-style collision checks between player and obstacles.

Key ideas:
- Axis-aligned overlap checks  
- Minimal arithmetic for fast runtime performance  
- Death-state triggering on collision  

---

### `obstacle_movement.cpp`
Shows frame-independent obstacle movement with looping behavior.

Key ideas:
- Delta-time (dt) based updates  
- Distance tracking for obstacle looping  
- Modular logic for reusable lane systems  

---

### `platform_system.cpp`
Implements moving-platform collision checks.

Key ideas:
- Tile-aligned overlap detection  
- Player-platform state handling  
- Extendable for moving platform mechanics  

---

## Contact
[Email](mailto:ashleylowlijia@gmail.com)  
[GitHub](https://github.com/awhaxh)  
[LinkedIn](https://www.linkedin.com/in/ashleyllj)
