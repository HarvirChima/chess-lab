# ⚡ Quick Start Guide - Get Playing in 5 Minutes!

This is the **fast track** to get the chess game running. If you want detailed explanations, see [README.md](README.md).

## 📋 Step 1: Check What You Have

First, verify your system is ready. Open a terminal and run:

```bash
# Check if you have the C++ compiler
g++ --version

# Check if you have CMake
cmake --version

# Check if you have git
git --version
```

**If any command fails** (says "command not found"), you need to install that tool first. See Step 2.

## 🔧 Step 2: Install Required Tools

**Choose your operating system:**

### Ubuntu/Debian Linux
```bash
sudo apt-get update
sudo apt-get install libncurses5-dev libncursesw5-dev cmake g++ git
```

### macOS
```bash
# First install Homebrew from https://brew.sh if you don't have it
brew install ncurses cmake git
```

### Fedora/RHEL Linux
```bash
sudo dnf install ncurses-devel cmake gcc-c++ git
```

### Windows
Use WSL (Windows Subsystem for Linux):
1. Install WSL: Open PowerShell as admin, run `wsl --install`
2. Restart your computer
3. Open Ubuntu from Start menu
4. Follow Ubuntu instructions above

## 📥 Step 3: Get the Code

### Recommended: Download as ZIP

1. Go to https://github.com/HarvirChima/chess-lab
2. Click the green "Code" button
3. Click "Download ZIP"
4. Extract the ZIP file to `~/projects/chess-lab` (or your preferred location)
5. Open the folder in VS Code:
   ```bash
   cd ~/projects/chess-lab  # or wherever you extracted it
   code .  # Opens in VS Code
   ```

### Alternative: Clone with Git

If you prefer using Git:
```bash
# Go to your projects folder (or create one)
mkdir -p ~/projects
cd ~/projects

# Download the code
git clone https://github.com/HarvirChima/chess-lab.git

# Enter the project folder
cd chess-lab
```

## 🔨 Step 4: Build the Game

```bash
# Create and enter build directory
mkdir build && cd build

# Configure the project (checks your system)
cmake ..

# Build all programs (this takes 30-60 seconds)
make
```

**What you should see:** Progress messages like "[14%] Building..." up to "[100%] Built target chess"

**If you get errors:** See the [Troubleshooting](#-troubleshooting-quick-fixes) section below.

## ✅ Step 5: Test It Works

```bash
# Run the tests
./test_chess
```

**Expected output:**
```
Running Chess Lab Tests...
=========================
✓ Piece creation test passed
✓ Board initialization test passed
...
All tests passed! ✓
```

## 🎮 Step 6: Play!

```bash
# Start the game
./chess
```

**You should see:** A chess board with pieces in your terminal!

## 🎯 How to Play - The Basics

**Controls:**
- **Arrow keys** (↑ ↓ ← →) - Move cursor around the board
- **SPACE bar** - Select piece, then move it
- **Q key** - Quit game

**Your First Move (White starts):**
1. The cursor starts somewhere on the board
2. Use **arrow keys** to move to square `e2` (white pawn, 2nd row, 5th column)
3. Press **SPACE** to select it (it should highlight)
4. Use **arrow keys** to move to square `e4` (4th row, same column)
5. Press **SPACE** to move the pawn there
6. You just made the classic "King's Pawn Opening"! 🎉

**Continue Playing:**
- Now it's Black's turn (filled pieces at top)
- Select a black piece and move it
- Keep alternating between White and Black

**Pieces:**
- White pieces: `♔ ♕ ♖ ♗ ♘ ♙` (hollow/outlined symbols)
- Black pieces: `♚ ♛ ♜ ♝ ♞ ♟` (filled/solid symbols)
- Empty squares: light or dark (░)

## 🚀 Bonus: See the Demo

Want to see the board layout first?

```bash
# View demo board
./demo_board
```

This shows you what the starting position looks like and an example game position.

## 🔍 All Commands Quick Reference

```bash
# After building (run from build/ directory):

./chess          # Play the chess game
./test_chess     # Run unit tests (verify everything works)
./demo_board     # View demo board layout

# To rebuild after making code changes:
make             # Rebuild everything

# To clean and rebuild from scratch:
rm -rf *         # Clean build directory
cmake ..         # Reconfigure
make             # Build again
```

## 🆘 Troubleshooting Quick Fixes

### "cmake: command not found"
```bash
# Ubuntu/Debian
sudo apt-get install cmake

# macOS
brew install cmake
```

### "ncurses.h: No such file or directory"
```bash
# Ubuntu/Debian
sudo apt-get install libncurses5-dev libncursesw5-dev

# macOS
brew install ncurses
```

### "make: command not found"
```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# macOS
xcode-select --install
```

### Build fails with compiler errors
Your compiler might be too old. Update it:
```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get upgrade g++
```

### Game looks weird or has strange characters
- Try a different terminal program
- Make sure terminal is at least 80x24 characters
- Increase font size

### "Permission denied" when running ./chess
Make sure you're in the `build/` directory:
```bash
cd build
./chess
```

## 📚 What's Next?

**If you're here to learn programming:**
- ✅ You've successfully built a C++ project!
- ✅ You've run tests and verified code works!
- ✅ You've executed a compiled program!

**Now explore:**
1. Open `src/main.cpp` in a text editor to see the code
2. Read [README.md](README.md) for GitHub Copilot exercises
3. Try modifying the code and rebuilding
4. Add new features with GitHub Copilot's help!

## 🤖 Using with GitHub Copilot

If you have GitHub Copilot installed in VS Code:

1. Open the chess-lab folder in VS Code:
   ```bash
   cd ~/projects/chess-lab  # or wherever you cloned it
   code .
   ```

2. Open any `.cpp` or `.h` file

3. Try these prompts:
   - Type `// Add a function to` and see what Copilot suggests
   - Highlight a function and ask Copilot Chat: "Explain this function"
   - Start writing a new test function and let Copilot complete it

**Lab Exercises:** See the README.md file for detailed Copilot learning exercises!

## 🎓 For Teachers & Lab Instructors

**Time estimates:**
- Setup and build: 10 minutes
- First playthrough: 10 minutes
- Basic Copilot exercises: 30 minutes
- Advanced feature addition: 1-2 hours

**Learning objectives:**
- ✅ Build a C++ project with CMake
- ✅ Run and interpret unit tests
- ✅ Navigate and understand existing code
- ✅ Use GitHub Copilot for code understanding
- ✅ Use GitHub Copilot to add new features
- ✅ Test and validate code changes

**Suggested lab flow:**
1. Students build and run the game (10 min)
2. Explore code with Copilot's help (15 min)
3. Add simple feature (e.g., move counter) (20 min)
4. Add complex feature (e.g., check detection) (30 min)
5. Share and discuss implementations (15 min)

## ❓ Quick FAQ

**Q: How long does building take?**
A: Usually 30-60 seconds on modern computers.

**Q: Do I need to know chess?**
A: No! You'll learn the basics by playing.

**Q: Can I run this on Windows?**
A: Yes, via WSL (Windows Subsystem for Linux). See Step 2.

**Q: What if I'm completely stuck?**
A: Check the full [README.md](README.md) for detailed troubleshooting, or open an issue on GitHub.

**Q: Do I need GitHub Copilot?**
A: No! The game works fine without it. But Copilot makes learning and adding features much easier.

---

**🎉 Congratulations!** You've built and run a C++ chess game!

**⭐ Enjoying this?** Star the project on GitHub!

**🤔 Need more help?** Check [README.md](README.md) for detailed instructions.

**🚀 Ready to code?** Start with the GitHub Copilot exercises in [README.md](README.md)!
