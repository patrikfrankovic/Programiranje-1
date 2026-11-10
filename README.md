# Battleship — Console Game

A single-player, terminal-based **Battleship** game developed as a programming coursework project. The program randomly places ships on a hidden 10 × 10 board and asks the player to find every occupied cell by entering coordinates.

## Features

- Random placement of a fleet of ships on a **10 × 10** grid
- Horizontal and vertical ship placement, with checks intended to avoid overlapping or adjacent ships
- Coordinate-based input: **rows A–J**, **columns 1–10**
- Feedback for hits (`x`) and misses (`.`)
- A visible tracking board that updates after every attempt
- A final summary with the number of attempts and hit percentage

The generated fleet contains one length-5 ship, two length-4 ships, three length-3 ships, and four length-2 ships.

## Technology

- C-style procedural programming using `stdio.h`, `stdlib.h`, and `time.h`
- Source stored as **C++ (`Source.cpp`)** in a Microsoft Visual Studio project
- Fixed-size arrays, randomization, loops, conditions, and functions

> Although the implementation uses C standard-library functions, the repository's source file is `.cpp` and the Visual Studio project compiles it as C++. No object-oriented C++ features are used.

## Building and running

### Visual Studio (Windows)

Open [`Potapanje Brodova/brod.sln`](Potapanje%20Brodova/brod.sln), build, and run the console project.

### Linux / macOS (C++ compiler)

```bash
g++ -std=c++11 'Potapanje Brodova/brod/Source.cpp' -o battleship
./battleship
```

### Gameplay

Run the application and enter a row letter followed by a column number when prompted. The game finishes after all ship cells have been hit.

## Project structure

```text
Potapanje Brodova/
├── brod.sln          # Visual Studio solution
└── brod/
    ├── Source.cpp    # Game implementation
    └── brod.vcxproj  # Visual Studio project
```

## Limitations

This is a **coursework implementation**, not a polished game engine. Input handling relies on `scanf`, and ship placement and repeated guesses are not backed by automated tests. The original gameplay logic is unchanged.
