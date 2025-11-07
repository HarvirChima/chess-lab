# Chess Lab - Quick Reference Card 📋

Quick reference for common commands and controls. Keep this handy while learning!

## 🚀 One-Line Setup (Copy & Paste)

```bash
# Complete setup in one command chain
git clone https://github.com/HarvirChima/chess-lab.git && cd chess-lab && mkdir build && cd build && cmake .. && make && ./test_chess && ./demo_board
```

## 🎮 Game Controls

| Key | Action |
|-----|--------|
| `↑` `↓` `←` `→` | Move cursor on board |
| `SPACE` | Select piece / Move piece |
| `Q` | Quit game |

## 🔨 Essential Commands

### Building

```bash
# From chess-lab directory
mkdir build && cd build
cmake ..
make
```

### Running

```bash
# From build directory
./chess          # Play game
./test_chess     # Run tests
./demo_board     # View demo
```

### Rebuilding After Changes

```bash
# From build directory
make             # Quick rebuild
```

### Clean Build

```bash
# From build directory
rm -rf *         # Clean everything
cmake ..         # Reconfigure
make             # Build fresh
```

## 🎯 Making Your First Move

1. Run: `./chess`
2. Use arrows to move to `e2` (white pawn)
3. Press `SPACE` (select)
4. Move to `e4`
5. Press `SPACE` (move)

## 🧩 Chess Piece Symbols

| Symbol | Piece | Symbol | Piece |
|--------|-------|--------|-------|
| `P` | White Pawn | `p` | Black pawn |
| `R` | White Rook | `r` | Black rook |
| `N` | White Knight | `n` | Black knight |
| `B` | White Bishop | `b` | Black bishop |
| `Q` | White Queen | `q` | Black queen |
| `K` | White King | `k` | Black king |

## 📂 Key Files

| File | Purpose |
|------|---------|
| `src/main.cpp` | Program entry point |
| `src/Game.cpp` | Game logic & input |
| `src/Board.cpp` | Move validation |
| `src/Display.cpp` | Visual rendering |
| `include/*.h` | Header declarations |

## 🐛 Quick Troubleshooting

| Problem | Solution |
|---------|----------|
| `cmake: command not found` | Install CMake: `sudo apt-get install cmake` |
| `ncurses.h not found` | Install ncurses: `sudo apt-get install libncurses5-dev` |
| `make: command not found` | Install build tools: `sudo apt-get install build-essential` |
| Build errors | Try clean build: `rm -rf build && mkdir build && cd build && cmake .. && make` |
| Weird characters in game | Try different terminal or increase font size |

## 🤖 GitHub Copilot Quick Tips

### In VS Code with Copilot:

1. **Understand code**: Highlight function → Right-click → "Copilot: Explain This"
2. **Add feature**: Type comment → Let Copilot suggest code
3. **Write tests**: Start test function → Copilot completes it
4. **Fix bugs**: Select error → Ask Copilot for fix

### Example Prompts:

```cpp
// Add function to detect checkmate
// Implement castling for the king
// Create a function to save game state
// Add move history tracking
```

## 📚 Common Lab Exercises

### Beginner (30 min)
- [ ] Build and run the game
- [ ] Play a complete game
- [ ] Read and understand `main.cpp`
- [ ] Add comments with Copilot

### Intermediate (1-2 hours)
- [ ] Add move counter
- [ ] Modify board colors
- [ ] Add "new game" option
- [ ] Write new test case

### Advanced (2-4 hours)
- [ ] Implement check detection
- [ ] Add castling support
- [ ] Implement pawn promotion
- [ ] Create simple AI opponent

## 🔗 Quick Links

- **Get Started**: [GET_STARTED.md](GET_STARTED.md)
- **Full Guide**: [README.md](README.md)
- **Lab Exercises**: [LAB_GUIDE.md](LAB_GUIDE.md)
- **Contributing**: [CONTRIBUTING.md](CONTRIBUTING.md)
- **Project Info**: [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md)

## 📱 Terminal Setup

### Minimum Requirements
- Terminal size: 80x24 characters
- Color support: 256 colors recommended
- Font: Monospace, size 12 or larger

### Recommended Terminals
- **Linux**: GNOME Terminal, Konsole
- **macOS**: iTerm2, Terminal.app
- **Windows**: Windows Terminal (with WSL)

## ✅ Pre-Flight Checklist

Before starting, verify:
- [ ] C++ compiler installed (`g++ --version`)
- [ ] CMake installed (`cmake --version`)
- [ ] ncurses library installed
- [ ] Git installed (`git --version`)
- [ ] Terminal supports colors
- [ ] Repository cloned

## 🎓 Learning Path

1. **Day 1**: Build, test, play
2. **Day 2**: Read code, add comments
3. **Day 3**: Small modifications
4. **Day 4**: Add simple feature
5. **Day 5**: Complex feature with Copilot

## 💡 Tips for Success

- ✅ **Save often** - Commit working code
- ✅ **Test frequently** - Run tests after changes
- ✅ **Read before coding** - Understand existing code
- ✅ **Start small** - Small changes, test, repeat
- ✅ **Use Copilot wisely** - Review all suggestions
- ✅ **Ask for help** - Open GitHub issue if stuck

## 🏆 Achievement Unlocked!

Track your progress:
- [ ] 🥉 Built the project
- [ ] 🥉 Ran all tests successfully
- [ ] 🥉 Played a complete game
- [ ] 🥈 Made first code modification
- [ ] 🥈 Added a simple feature
- [ ] 🥈 Wrote a new test
- [ ] 🥇 Implemented complex feature
- [ ] 🥇 Used Copilot effectively
- [ ] 🥇 Contributed to the project

## 🆘 Get Help

- **Issues**: [GitHub Issues](https://github.com/HarvirChima/chess-lab/issues)
- **Discussions**: [GitHub Discussions](https://github.com/HarvirChima/chess-lab/discussions)
- **Stack Overflow**: Tag `c++` and `chess`

---

**Print this card and keep it handy!** 📄

**Star the project if it helps!** ⭐
