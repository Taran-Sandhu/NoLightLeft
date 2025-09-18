# No Light Left

_No Light Left_ is a console-based text adventure game where you explore interconnected rooms while managing your dwindling torchlight. The goal is to navigate the dungeon before your light runs out.

---

## Features
- ASCII-style dungeon map that updates as you explore.
- Fog-of-war style discovery:  
  - `P` = player’s current room  
  - `.` = previously visited room  
  - `?` = unexplored room
- Torchlight system: each movement decreases your light level.  
  Run out of light, and the game ends.
- Intro sequence loaded from `assets/intro.txt`.

---

## How to Play
- When the game starts, an intro text will be displayed with a typewriter effect.
- Type commands at the prompt (`>`).  
  Examples:
  - `go north` or simply `north`
  - `go east` or simply `east`
  - `quit` or `exit` to leave the game
- The map updates after each move, showing explored and unexplored rooms.
- Watch your light level — it drops by 1 with every move.

---

## Building
This is a standard C++17 (or newer) project.

### Requirements
- A C++ compiler (GCC, Clang, or MSVC).
- [CMake](https://cmake.org/) (recommended).
- The `assets/intro.txt` file must exist (or create your own intro text).

### Instructions
```bash
git clone https://github.com/Taran-Sandhu/NoLightLeft.git
cd NoLightLeft
mkdir build && cd build
cmake ..
cmake --build .
