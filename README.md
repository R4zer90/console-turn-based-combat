# Console Turn-Based Combat (C++)

A small console-based turn-based combat game created as a C++ learning project.

## Features
- Narrative intro with a typewriter-style text effect
- Player name input with validation
- Turn-based combat loop
- Player actions: Attack, Defend, Heal
- Simple enemy AI
- Victory and Defeat screens

## Concepts practiced
- if / else
- loops (while)
- switch
- strings and input handling (cin / getline)
- functions
- basic game state management
- basic multi-file project structure (headers / source files)

## Project structure
```
console-turn-based-combat/
├── include/
├── src/
├── CMakeLists.txt
└── README.md
```

## Build & Run (CMake)

### Requirements
- CMake 3.20+
- C++ compiler (MSVC / GCC / Clang)

### Build (Debug)
```bash
cmake -S . -B build
cmake --build build
```

### Run (Debug)
```bash
./build/Debug/ConsoleTurnBasedCombat
```

### Build (Release)
```bash
cmake --build build --config Release
```

### Run (Release)
```bash
./build/Release/ConsoleTurnBasedCombat
```

> On Linux/macOS the output path may differ depending on the generator.

## How to run (Visual Studio)
- Open the `.sln` file and run the project
- Recommended: Start Without Debugging (Ctrl + F5)

## Notes
This project is part of my C++ learning path and focuses on fundamentals and clean game flow.
