# Chess Lab Quick Start Guide 🚀

Get up and running with the Chess Lab in 5 minutes!

## Installation

### macOS
```bash
brew install ncurses cmake git
```

### Windows (WSL)
```bash
wsl --install  # Run in PowerShell as Admin, then restart
# In WSL Ubuntu:
sudo apt-get update
sudo apt-get install -y libncurses5-dev libncursesw5-dev cmake g++ git
```

### Linux
```bash
sudo apt-get update
sudo apt-get install -y libncurses5-dev libncursesw5-dev cmake g++ git
```

## Build and Run

```bash
# Download the repository as ZIP from GitHub:
# 1. Visit https://github.com/HarvirChima/chess-lab
# 2. Click "Code" button → "Download ZIP"
# 3. Extract to your preferred location
# Then navigate to the extracted folder:
cd chess-lab  # or wherever you extracted it

# Open in VS Code (recommended)
code .

# Build in terminal
mkdir build && cd build
cmake ..
make

# Run tests
./test_chess

# Play the game!
./chess
```

**Alternative - Clone with Git:**
```bash
git clone https://github.com/HarvirChima/chess-lab.git
cd chess-lab
# Then follow build steps above
```

## Game Controls

| Key | Action |
|-----|--------|
| ↑ ↓ ← → | Move cursor |
| SPACE | Select piece / Move to position |
| Q | Quit game |

## Quick Lab Overview

1. **Lab 1 (15 min)**: Use Ask Mode to explore the code
2. **Lab 2 (20 min)**: Customize Copilot with instructions
3. **Lab 3 (25 min)**: Fix bugs with Agent Mode
4. **Lab 4 (20 min)**: Create reusable prompt files
5. **Lab 5 (25 min)**: Build custom chat participants
6. **Lab 6 (30 min)**: Master advanced techniques

**Ready for details?** → Open [LAB_GUIDE.md](LAB_GUIDE.md)

## Need Help?

- **Build issues?** Check LAB_GUIDE.md troubleshooting section
- **Copilot not working?** Verify it's enabled in VS Code status bar
- **Game not running?** Ensure ncurses is installed

## Learning Resources

- 📖 [Full Lab Guide](LAB_GUIDE.md) - Complete lab instructions
- 📋 [Reference Card](REFERENCE.md) - Quick command reference
- 🤝 [Contributing](CONTRIBUTING.md) - How to contribute
- 📊 [Project Summary](PROJECT_SUMMARY.md) - Technical details

---

**Let's start coding with AI! 🤖♟️**
