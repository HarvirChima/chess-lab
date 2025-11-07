# Chess Lab

A C++ chess game application with a full visual display, designed for GitHub Copilot labs and demonstrations.

## Features

- Complete chess game implementation with standard rules
- Terminal-based visual display using ncurses
- Interactive gameplay with arrow key navigation
- Turn-based play for White and Black players
- Move validation and piece movement rules
- Color-coded pieces for easy identification

## Requirements

- CMake 3.10 or higher
- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- ncurses library

### Installing ncurses

**Ubuntu/Debian:**
```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```

**macOS:**
```bash
brew install ncurses
```

**Fedora/RHEL:**
```bash
sudo dnf install ncurses-devel
```

## Building

```bash
mkdir build
cd build
cmake ..
make
```

## Running

```bash
./chess
```

## How to Play

- Use **arrow keys** to move the cursor around the board
- Press **SPACE** to select a piece or move it to the highlighted square
- Press **Q** to quit the game

### Game Rules

- White pieces are shown in UPPERCASE (P, R, N, B, Q, K)
- Black pieces are shown in lowercase (p, r, n, b, q, k)
- Select your piece first, then select the destination square
- Only valid moves are allowed according to standard chess rules

## GitHub Copilot Labs

This project is designed to help developers learn and practice with GitHub Copilot. Use it to:

- Explore AI-assisted code completion
- Practice refactoring with AI suggestions
- Learn C++ game development patterns
- Understand ncurses terminal UI programming

## Project Structure

```
chess-lab/
├── CMakeLists.txt          # CMake build configuration
├── include/                # Header files
│   ├── Board.h            # Chess board logic
│   ├── Piece.h            # Chess piece definitions
│   ├── Game.h             # Game controller
│   └── Display.h          # Visual display
├── src/                    # Source files
│   ├── main.cpp           # Application entry point
│   ├── Board.cpp          # Board implementation
│   ├── Piece.cpp          # Piece implementation
│   ├── Game.cpp           # Game implementation
│   └── Display.cpp        # Display implementation
└── README.md              # This file
```

## Future Enhancements

- Castling support
- En passant captures
- Pawn promotion
- Check and checkmate detection
- Move history and undo
- Save/load game state
- AI opponent
