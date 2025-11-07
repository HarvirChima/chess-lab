# Quick Start Guide

## Prerequisites

Install ncurses library:

**Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install libncurses5-dev libncursesw5-dev cmake g++
```

**macOS:**
```bash
brew install ncurses cmake
```

**Fedora/RHEL:**
```bash
sudo dnf install ncurses-devel cmake gcc-c++
```

## Build in 3 Steps

```bash
# 1. Create build directory
mkdir build && cd build

# 2. Configure with CMake
cmake ..

# 3. Build
make
```

## Run

```bash
# Play the game
./chess

# Run tests
./test_chess

# View demo
./demo_board
```

## Game Controls

| Key | Action |
|-----|--------|
| ↑ ↓ ← → | Move cursor |
| Space | Select piece / Make move |
| Q | Quit |

## First Game

1. Start the game: `./chess`
2. Use arrow keys to move to a white piece (bottom of board)
3. Press Space to select it
4. Move cursor to a valid destination square
5. Press Space to move
6. Take turns between White and Black

## Example Opening Moves

**King's Pawn Opening:**
1. Move cursor to e2 (white pawn)
2. Press Space (select)
3. Move cursor to e4
4. Press Space (move)

## Need Help?

- Check `README.md` for detailed documentation
- Run `./demo_board` to see board layout
- Run `./test_chess` to verify installation

## For Lab Instructors

Use this project to demonstrate:
- AI-assisted code completion
- Refactoring with GitHub Copilot
- Adding new features (check detection, castling, etc.)
- Writing tests with AI assistance
- Code documentation generation

Enjoy coding with GitHub Copilot! 🎮♟️
