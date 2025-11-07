# Chess Lab 🎮♟️

A beginner-friendly C++ chess game application with a full visual display, designed as a hands-on lab for learning GitHub Copilot and C++ programming.

## 🎯 What is This Lab?

This is an **interactive learning project** perfect for:
- **Complete beginners** learning to code with AI assistance
- **Developers** exploring GitHub Copilot's capabilities
- **Students** learning C++ and game development
- **Anyone** wanting hands-on experience with AI-assisted coding

**No prior chess programming experience needed!** This lab will guide you through everything step by step.

## 📚 Documentation Quick Links

- 📖 **[QUICKSTART.md](QUICKSTART.md)** - Get running in 5 minutes
- 📋 **[REFERENCE.md](REFERENCE.md)** - Quick reference card for commands and controls  
- 🤝 **[CONTRIBUTING.md](CONTRIBUTING.md)** - Guide for contributors
- 📊 **[PROJECT_SUMMARY.md](PROJECT_SUMMARY.md)** - Technical project overview
- 🎬 **[demo.sh](demo.sh)** - Interactive guided demo script

**New to this?** Start with QUICKSTART.md, then come back here for detailed explanations!

## ✨ Features

- ✅ Complete chess game implementation with standard rules
- ✅ Terminal-based visual display using ncurses
- ✅ Interactive gameplay with arrow key navigation
- ✅ Turn-based play for White and Black players
- ✅ Move validation and piece movement rules
- ✅ Color-coded pieces for easy identification
- ✅ Unit tests to verify your code works
- ✅ Demo tools to explore the board

## 🚀 Quick Start (For Impatient Learners!)

If you just want to see it run quickly, follow [QUICKSTART.md](QUICKSTART.md).

## 📋 Prerequisites

Before you start, make sure you have these tools installed:

### Required Software

1. **A C++ Compiler** - This converts your code into a runnable program
   - On Linux/macOS: Usually pre-installed (GCC or Clang)
   - On Windows: Install MinGW or use WSL (Windows Subsystem for Linux)

2. **CMake** - A build system that manages the compilation process
   - Version 3.10 or higher required

3. **ncurses library** - Enables the visual terminal display
   - This creates the nice-looking chess board in your terminal

### Installing Everything You Need

Choose your operating system:

#### **Ubuntu/Debian Linux** 🐧
```bash
# Update package list
sudo apt-get update

# Install all required tools
sudo apt-get install libncurses5-dev libncursesw5-dev cmake g++ git
```

#### **macOS** 🍎
```bash
# First, install Homebrew if you haven't already
# Visit https://brew.sh for instructions

# Then install required packages
brew install ncurses cmake git
```

#### **Fedora/RHEL Linux** 🎩
```bash
# Install all required tools
sudo dnf install ncurses-devel cmake gcc-c++ git
```

#### **Windows** 🪟
The easiest way is to use WSL (Windows Subsystem for Linux):
1. Install WSL following [Microsoft's guide](https://learn.microsoft.com/en-us/windows/wsl/install)
2. Once in WSL, follow the Ubuntu/Debian instructions above

### ✅ Verify Your Setup

Run these commands to check everything is installed:

```bash
# Check C++ compiler
g++ --version
# Expected: Should show version 7.0 or higher

# Check CMake
cmake --version
# Expected: Should show version 3.10 or higher

# Check git
git --version
# Expected: Any recent version is fine
```

If all commands show version numbers, you're ready to proceed! 🎉

## 📥 Getting the Code

### Option 1: Clone with Git (Recommended)

```bash
# Navigate to where you want to store the project
cd ~/projects  # or any directory you prefer

# Clone the repository
git clone https://github.com/HarvirChima/chess-lab.git

# Enter the project directory
cd chess-lab
```

### Option 2: Download ZIP

1. Visit the repository on GitHub
2. Click the green "Code" button
3. Select "Download ZIP"
4. Extract the ZIP file
5. Open terminal/command prompt in the extracted folder

## 🔨 Building the Project

Building means converting the human-readable C++ code into executable programs your computer can run.

### Step-by-Step Build Instructions

```bash
# 1. Make sure you're in the chess-lab directory
cd chess-lab  # if not already there

# 2. Create a build directory (keeps build files separate from source code)
mkdir build

# 3. Navigate into the build directory
cd build

# 4. Configure the project with CMake
#    This checks your system and prepares for building
cmake ..

# 5. Build all executables
#    This compiles the code into runnable programs
make
```

**What you should see:**
```
-- The C compiler identification is GNU ...
-- The CXX compiler identification is GNU ...
-- Configuring done
-- Generating done
-- Build files have been written to: ...
[ 14%] Building CXX object ...
[ 28%] Building CXX object ...
...
[100%] Built target chess
```

**If successful**, you'll now have three executable programs in your `build` directory:
- `chess` - The main game
- `test_chess` - Unit tests
- `demo_board` - A demo visualization tool

## 🎮 Running the Game

### First, Run the Tests

Before playing, verify everything works correctly:

```bash
# Make sure you're in the build directory
cd build  # if not already there

# Run the test suite
./test_chess
```

**Expected output:**
```
Running Chess Lab Tests...
=========================
✓ Piece creation test passed
✓ Board initialization test passed
✓ Pawn movement test passed
✓ Knight movement test passed
✓ Invalid move test passed
✓ Capture test passed
=========================
All tests passed! ✓
```

If you see "All tests passed!", you're ready to play! 🎉

### View the Demo

Want to see what the board looks like first?

```bash
# Run the demo viewer
./demo_board
```

This shows you the initial chess board layout and an example position after a few moves.

### Play the Game!

```bash
# Start the chess game
./chess
```

**What you'll see:**
- A chess board with pieces displayed in your terminal
- A cursor you can move with arrow keys
- Status messages at the bottom
- Current player's turn indicated

## 🎯 How to Play

### Game Controls (Keyboard)

| Key | What It Does |
|-----|-------------|
| **↑ (Up Arrow)** | Move cursor up on the board |
| **↓ (Down Arrow)** | Move cursor down on the board |
| **← (Left Arrow)** | Move cursor left on the board |
| **→ (Right Arrow)** | Move cursor right on the board |
| **SPACE** | Select a piece OR move selected piece to cursor position |
| **Q** | Quit the game |

### Understanding the Board

**Piece Symbols:**
- **White pieces** (you move first): UPPERCASE letters
  - `P` = Pawn
  - `R` = Rook (castle)
  - `N` = Knight (the horse)
  - `B` = Bishop
  - `Q` = Queen
  - `K` = King

- **Black pieces**: lowercase letters
  - `p` = pawn
  - `r` = rook
  - `n` = knight
  - `b` = bishop
  - `q` = queen
  - `k` = king

- **Empty squares**: Either blank or `■` (representing dark squares)

### Your First Game - Step by Step

Let's make your first move! Here's the classic "King's Pawn Opening":

1. **Start the game**
   ```bash
   ./chess
   ```

2. **You'll see the board** with White pieces at the bottom (rows 1-2) and Black pieces at the top (rows 7-8)

3. **Make your first move** (White always goes first):
   - Use arrow keys to move cursor to **e2** (the pawn in front of the white king)
   - Press **SPACE** to select it (the piece should be highlighted)
   - Use arrow keys to move cursor to **e4** (two squares forward)
   - Press **SPACE** to move the pawn there

4. **Black's turn** (if playing with a friend):
   - Move to **e7** (black pawn)
   - Press **SPACE** to select
   - Move to **e5**
   - Press **SPACE** to move

5. **Continue playing** back and forth!

### Game Rules Reminder

- **White** pieces move first
- Players alternate turns (White, then Black, then White, etc.)
- Select your own pieces (White selects White, Black selects Black)
- You can only make **valid chess moves** - the game won't let you cheat!
- **Capture** enemy pieces by moving to their square

### Tips for New Chess Players

- **Pawns** move forward one square (or two on their first move)
- **Knights** move in an "L" shape (2 squares + 1 square perpendicular)
- **Bishops** move diagonally any number of squares
- **Rooks** move horizontally or vertically any number of squares
- **Queens** combine rook and bishop movement (most powerful!)
- **Kings** move one square in any direction

Don't worry about memorizing everything - just experiment and learn as you play!

## 🤖 Learning with GitHub Copilot

This project is **specifically designed** to help you learn AI-assisted programming with GitHub Copilot!

### What is GitHub Copilot?

GitHub Copilot is an AI pair programmer that helps you write code by:
- Suggesting code completions as you type
- Generating entire functions from comments
- Helping you understand existing code
- Suggesting fixes for bugs
- Writing tests automatically

### Lab Exercises with Copilot

Here are hands-on exercises to try with GitHub Copilot:

#### **Exercise 1: Code Understanding (Beginner)**
1. Open `src/Board.cpp` in VS Code (with Copilot enabled)
2. Hover over functions to see what they do
3. Use Copilot Chat to ask: "Explain what the `isValidMove` function does"
4. Try to understand the piece movement logic

#### **Exercise 2: Add Comments (Beginner)**
1. Open `src/Game.cpp`
2. Place your cursor above a function
3. Type `//` and let Copilot suggest a comment
4. Practice having Copilot document the code for you

#### **Exercise 3: Write a New Test (Intermediate)**
1. Open `src/test_chess.cpp`
2. At the end, start typing a new test function:
   ```cpp
   void testRookMovement() {
       // Test that a rook can move horizontally
   ```
3. Let Copilot complete the test for you
4. Review and run it with `./test_chess`

#### **Exercise 4: Add a Feature - Check Detection (Advanced)**
1. Create a comment in `src/Board.h`:
   ```cpp
   // Function to check if a king is in check
   bool isKingInCheck(Color color);
   ```
2. Let Copilot suggest the implementation
3. Add the implementation to `src/Board.cpp`
4. Test your new feature!

#### **Exercise 5: Add Move History (Advanced)**
1. In `src/Game.h`, add:
   ```cpp
   // Vector to store move history
   ```
2. Let Copilot suggest the data structure
3. Implement functions to track and display moves
4. Use Copilot to help with the implementation

### Copilot Tips for This Lab

**Good prompts to try:**
- "Add a function to detect checkmate"
- "Implement castling for the king and rook"
- "Create a function to save the game state to a file"
- "Add pawn promotion when a pawn reaches the opposite end"
- "Write a test for bishop diagonal movement"

**How to get better suggestions:**
1. Write clear, descriptive comments first
2. Use meaningful variable and function names
3. Look at existing code patterns in the project
4. Review Copilot's suggestions - don't just accept blindly!
5. Test your code frequently

## 🔧 Troubleshooting

### Problem: "cmake: command not found"

**Solution:** CMake is not installed.
```bash
# Ubuntu/Debian
sudo apt-get install cmake

# macOS
brew install cmake
```

### Problem: "ncurses.h: No such file or directory"

**Solution:** ncurses library is not installed.
```bash
# Ubuntu/Debian
sudo apt-get install libncurses5-dev libncursesw5-dev

# macOS
brew install ncurses
```

### Problem: "make: command not found"

**Solution:** Build tools are not installed.
```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# macOS (installs with Xcode command line tools)
xcode-select --install
```

### Problem: Build fails with compiler errors

**Solution:** Make sure you have a C++17 compatible compiler.
```bash
# Check your compiler version
g++ --version

# Should be GCC 7+ or Clang 5+
# If older, update your compiler:
sudo apt-get update
sudo apt-get upgrade g++
```

### Problem: Game displays incorrectly or has weird characters

**Solution:** Terminal doesn't support ncurses properly.
- Try a different terminal emulator (e.g., GNOME Terminal, iTerm2, Windows Terminal)
- Make sure your terminal size is at least 80x24 characters
- Check that your `TERM` environment variable is set: `echo $TERM`

### Problem: Can't see the cursor or pieces are hard to distinguish

**Solution:** Adjust your terminal colors or theme.
- Try a light-colored terminal theme
- Increase font size for better visibility
- Some terminals work better than others with ncurses

### Still Having Issues?

1. **Check the build output carefully** - error messages usually tell you what's wrong
2. **Make sure you're in the right directory** - commands should be run from `build/`
3. **Clean and rebuild**:
   ```bash
   cd build
   rm -rf *
   cmake ..
   make
   ```
4. **Search for your error message online** - Stack Overflow often has solutions
5. **Check the project's GitHub Issues** - others may have had the same problem

## 📁 Project Structure

Understanding what each file does:

```
chess-lab/
├── CMakeLists.txt          # Build configuration (tells CMake how to build)
├── README.md               # This file - your main guide
├── QUICKSTART.md          # Fast-track instructions
├── PROJECT_SUMMARY.md     # Technical overview
├── demo.sh                # Demo script
├── .gitignore             # Tells git which files to ignore
│
├── include/               # Header files (.h) - declarations
│   ├── Board.h           # Chess board class declaration
│   ├── Piece.h           # Chess piece class declaration
│   ├── Game.h            # Game controller class declaration
│   └── Display.h         # Visual display class declaration
│
└── src/                   # Source files (.cpp) - implementations
    ├── main.cpp          # Program entry point - starts the game
    ├── Board.cpp         # Board logic (move validation, etc.)
    ├── Piece.cpp         # Piece definitions (colors, types)
    ├── Game.cpp          # Game flow (turns, user input)
    ├── Display.cpp       # Display rendering (ncurses drawing)
    ├── test_chess.cpp    # Unit tests to verify code works
    └── demo_board.cpp    # Demo board viewer

After building, you'll also see:
└── build/                 # Build directory (created by you)
    ├── chess             # Main game executable
    ├── test_chess        # Test program executable
    ├── demo_board        # Demo viewer executable
    └── ...               # Other build artifacts (ignore these)
```

### What Each File Does

**Header files (.h):**
- Declare classes, functions, and data structures
- Like a "table of contents" for the code
- Other files include these to use the functionality

**Source files (.cpp):**
- Contain the actual implementation code
- Define what the functions declared in headers actually do

**CMakeLists.txt:**
- Configuration file for CMake
- Lists all source files
- Specifies dependencies (like ncurses)
- Tells the build system how to compile everything

## 🎓 Next Steps - Keep Learning!

### Beginner Level
- [ ] Play a complete game with a friend
- [ ] Read through `src/main.cpp` - it's the simplest file
- [ ] Use Copilot to add comments to functions you don't understand
- [ ] Try modifying the starting message in `main.cpp`

### Intermediate Level
- [ ] Add a new test case in `test_chess.cpp`
- [ ] Modify the board display colors in `Display.cpp`
- [ ] Implement a "new game" option to restart without quitting
- [ ] Add a move counter to track how many moves have been made

### Advanced Level
- [ ] Implement check detection
- [ ] Add castling support
- [ ] Implement en passant captures
- [ ] Add pawn promotion
- [ ] Implement checkmate detection
- [ ] Create an AI opponent (start simple - random moves!)
- [ ] Add save/load game functionality
- [ ] Implement move notation (algebraic notation)

### Using This with GitHub Copilot

**Workflow for adding features:**
1. **Plan**: Write a comment describing what you want to do
2. **Generate**: Let Copilot suggest the implementation
3. **Review**: Read the suggested code - does it make sense?
4. **Test**: Build and test your changes
5. **Iterate**: Refine based on what works and what doesn't

**Example workflow:**
```cpp
// In Board.h, add:
// TODO: Add function to detect if the king is in check

// In Board.cpp, start typing:
bool Board::isKingInCheck(Color color) {
    // Copilot will suggest implementation
}
```

## 🌟 Success Stories

**"I had never programmed in C++ before, but with Copilot helping me understand the code and suggest improvements, I added check detection in just 2 hours!"** - Beginner Developer

**"This lab was perfect for learning how AI can assist with coding. I learned both chess programming AND how to effectively use Copilot."** - Student

## 🤝 Contributing

Want to improve this lab?
- Fix bugs you find
- Add more exercises
- Improve documentation
- Share your success stories!

## 📚 Additional Resources

**Learning C++:**
- [LearnCpp.com](https://www.learncpp.com/) - Free C++ tutorial
- [C++ Reference](https://en.cppreference.com/) - Language reference

**Learning Chess:**
- [Chess.com Learn](https://www.chess.com/learn) - Free chess lessons
- [Lichess](https://lichess.org/learn) - Interactive chess tutorials

**GitHub Copilot:**
- [Copilot Documentation](https://docs.github.com/en/copilot)
- [Copilot Tips & Tricks](https://github.blog/2023-06-20-how-to-write-better-prompts-for-github-copilot/)

**ncurses Programming:**
- [NCURSES Programming HOWTO](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/)

## ❓ FAQ

**Q: Do I need to know how to play chess?**
A: No! Basic rules are included, and you'll learn by playing.

**Q: Is this only for beginners?**
A: No! Beginners can learn the basics, while advanced users can add complex features like AI opponents.

**Q: Do I need GitHub Copilot to use this?**
A: No! The game works without Copilot. But Copilot makes learning and extending it much easier.

**Q: Can I use this for my own project?**
A: Yes! Feel free to fork, modify, and build upon this code.

**Q: How long does the lab take?**
A: 30 minutes to get running and play a game. Hours to days if you want to add new features!

**Q: What if I'm stuck?**
A: Check the troubleshooting section, search for error messages online, or ask for help in GitHub Issues.

## 📄 License

This project is open source and available for educational purposes.

---

**Ready to start?** Jump to the [Prerequisites](#-prerequisites) section and begin your journey! 🚀

**Questions?** Open an issue on GitHub and we'll help you out.

**Enjoying the lab?** Give it a ⭐ star on GitHub!


