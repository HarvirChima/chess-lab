# Get Started with Chess Lab 🚀

This guide will get you up and running in **5 minutes**!

## 🎯 Choose Your Path

**What do you want to do?**

### 🎓 I want to learn GitHub Copilot
→ Follow [**Path A: Learning Labs**](#path-a-learning-labs) below

### ♟️ I just want to play chess
→ Follow [**Path B: Play the Game**](#path-b-play-the-game) below

---

## Path A: Learning Labs

Perfect for learning GitHub Copilot through hands-on exercises!

### Prerequisites Check

Run these commands to verify you have what you need:

```bash
g++ --version    # C++ compiler (need 7.0+)
cmake --version  # Build tool (need 3.10+)
git --version    # Version control
code --version   # VS Code (optional but recommended)
```

**Missing something?** Jump to [Installation Guide](#installation-guide) below.

### Quick Setup

```bash
# 1. Get the code
# Download ZIP from https://github.com/HarvirChima/chess-lab
# OR clone with git:
git clone https://github.com/HarvirChima/chess-lab.git
cd chess-lab

# 2. Open in VS Code
code .

# 3. Build the project
mkdir build && cd build
cmake ..
make

# 4. Verify it works
./test_chess
```

### Start Learning!

Once setup is complete, **open [LAB_GUIDE.md](LAB_GUIDE.md)** and start with Lab 1!

**Lab Overview** (2.5 hours total):
1. **Lab 1 (15 min)**: Ask Mode - Query code naturally
2. **Lab 2 (20 min)**: Copilot Instructions - Customize AI behavior  
3. **Lab 3 (25 min)**: Agent Mode - Fix bugs autonomously
4. **Lab 4 (20 min)**: Prompt Files - Create reusable prompts
5. **Lab 5 (25 min)**: Custom Chat - Build specialized AI assistants
6. **Lab 6 (30 min)**: Advanced - Master best practices

---

## Path B: Play the Game

Just want to play chess? Here's the fastest way!

### Prerequisites Check

```bash
g++ --version    # C++ compiler (need 7.0+)
cmake --version  # Build tool (need 3.10+)
```

**Missing something?** Jump to [Installation Guide](#installation-guide) below.

### Quick Setup

```bash
# Get the code
git clone https://github.com/HarvirChima/chess-lab.git
cd chess-lab

# Build and play
mkdir build && cd build
cmake .. && make
./chess
```

### Game Controls

| Key | Action |
|-----|--------|
| ↑ ↓ ← → | Move cursor around board |
| SPACE | Select piece, then move it |
| Q | Quit game |

**Your First Move:**
1. Use arrows to move to `e2` (white pawn, 2nd row from bottom)
2. Press SPACE to select
3. Move to `e4` (4th row, same column)
4. Press SPACE to move
5. You just made the classic "King's Pawn Opening"! ♔

---

## Installation Guide

### macOS 🍎

```bash
# Install Homebrew if you don't have it
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install required packages
brew install ncurses cmake git
```

### Windows 🪟

**Use WSL2 (Windows Subsystem for Linux):**

1. Open PowerShell as Administrator:
```powershell
wsl --install
```

2. Restart your computer

3. Open Ubuntu from Start menu

4. Install packages:
```bash
sudo apt-get update
sudo apt-get install -y libncurses5-dev libncursesw5-dev cmake g++ git
```

### Linux 🐧

**Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install -y libncurses5-dev libncursesw5-dev cmake g++ git
```

**Fedora/RHEL:**
```bash
sudo dnf install ncurses-devel cmake gcc-c++ git
```

---

## Troubleshooting

### Build Issues

**"cmake: command not found"**
```bash
# Install CMake for your OS (see Installation Guide above)
```

**"ncurses.h: No such file or directory"**
```bash
# Ubuntu/Debian
sudo apt-get install libncurses5-dev libncursesw5-dev

# macOS
brew install ncurses
```

**"make: command not found"**
```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# macOS
xcode-select --install
```

### Game Issues

**Weird characters or display problems**
- Try a different terminal program
- Make sure terminal is at least 80x24 characters
- Increase font size

**Permission denied when running ./chess**
```bash
# Make sure you're in the build directory
cd build
./chess
```

### Copilot Issues (Lab Path)

**Copilot not providing suggestions**
1. Check VS Code status bar - ensure Copilot icon shows checkmark
2. Press Ctrl+Shift+P → "Reload Window"
3. Sign in to GitHub in VS Code
4. Verify subscription at github.com/settings/copilot

---

## What's Next?

### For Learners (Lab Path)
✅ Setup complete? **Open [LAB_GUIDE.md](LAB_GUIDE.md)** to start Lab 1!

### For Players (Game Path)
- Want to understand the code? See [README.md](README.md)
- Want to contribute? See [CONTRIBUTING.md](CONTRIBUTING.md)
- Want quick reference? See [REFERENCE.md](REFERENCE.md)

### For Instructors
Teaching this lab? See [INSTRUCTOR_GUIDE.md](INSTRUCTOR_GUIDE.md)

---

## Quick Reference

### Essential Commands

```bash
# After building (run from build/ directory):
./chess          # Play the chess game
./test_chess     # Run unit tests
./demo_board     # View demo board

# To rebuild after code changes:
make

# Clean rebuild:
rm -rf * && cmake .. && make
```

### Project Structure

```
chess-lab/
├── GET_STARTED.md         ← YOU ARE HERE
├── README.md              ← Project overview
├── LAB_GUIDE.md           ← Complete lab exercises
├── REFERENCE.md           ← Quick reference card
├── CONTRIBUTING.md        ← How to contribute
└── INSTRUCTOR_GUIDE.md    ← For instructors
```

---

**Need more help?** 
- 📖 Full details: [README.md](README.md)
- 🎓 Lab exercises: [LAB_GUIDE.md](LAB_GUIDE.md)
- 📋 Quick reference: [REFERENCE.md](REFERENCE.md)
- 🐛 Report issues: [GitHub Issues](https://github.com/HarvirChima/chess-lab/issues)

**Enjoying the lab?** ⭐ Star the project on GitHub!
