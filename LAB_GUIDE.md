# Chess Lab - Complete Step-by-Step Guide 🎮♟️

Welcome to the Chess Lab! This is your complete guide to learning GitHub Copilot through building and working with a real chess game. Everything you need is in this one document - from installation to advanced techniques.

## 📋 Table of Contents

1. [What is This Lab?](#what-is-this-lab)
2. [What You'll Learn](#what-youll-learn)
3. [Installation & Setup](#installation--setup)
4. [Building the Project](#building-the-project)
5. [Lab 1: Ask Mode](#lab-1-ask-mode-15-minutes)
6. [Lab 2: Copilot Instructions](#lab-2-copilot-instructions-20-minutes)
7. [Lab 3: Agent Mode](#lab-3-agent-mode-25-minutes)
8. [Lab 4: Prompt Files](#lab-4-prompt-files-20-minutes)
9. [Lab 5: Custom Chat Modes](#lab-5-custom-chat-modes-25-minutes)
10. [Lab 6: Advanced Topics](#lab-6-advanced-topics-30-minutes)
11. [For Instructors](#for-instructors)
12. [Troubleshooting](#troubleshooting)
13. [Next Steps](#next-steps)

---

## What is This Lab?

An interactive learning project where you'll:
- **Build** a working C++ chess game
- **Learn** GitHub Copilot features through hands-on exercises
- **Fix** intentional bugs using AI assistance
- **Add** new features with Copilot's help
- **Master** AI-assisted development workflows

**Perfect for:**
- 🆕 Complete beginners learning to code with AI
- 💻 Developers exploring GitHub Copilot
- 🎓 Students learning C++ and game development
- 🤖 Anyone wanting hands-on AI coding experience

**Time Required:** 2.5 hours total (you can do it in chunks!)

---

## What You'll Learn

By the end of this lab, you'll be able to:
- ✅ Use Copilot Chat to understand and explore code
- ✅ Customize Copilot's behavior with instructions
- ✅ Use Agent Mode to fix bugs across multiple files
- ✅ Create reusable prompt files for your team
- ✅ Build custom AI assistants for specific tasks
- ✅ Apply best practices for AI-assisted development

---

## Installation & Setup

Let's get your computer ready! Don't worry if you're new to this - we'll explain everything.

### What You Need to Install

Before you can run the chess game, you need these tools:

1. **C++ Compiler** - Translates code into a program your computer can run
2. **CMake** - Helps organize and build C++ projects
3. **ncurses Library** - Creates the chess board display in your terminal
4. **Git** - Downloads code from GitHub
5. **VS Code** (recommended) - Code editor with GitHub Copilot support

### For macOS 🍎

#### Understanding Homebrew
Homebrew is a **package manager** for macOS. Think of it like an app store for developer tools - instead of downloading installers from websites, you just type one command and it installs everything for you automatically.

#### Step 1: Install Homebrew

1. **Open Terminal** (press `Cmd + Space`, type "Terminal", press Enter)

2. **Check if Homebrew is already installed:**
   ```bash
   brew --version
   ```
   - If you see a version number, skip to Step 2!
   - If you see "command not found", continue below:
   - If you need to Install Homebrew:
      ```bash
      /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
      ```
      - Press Enter when prompted
      - Enter your Mac password (the one you use to log in)
      - Installation takes 2-5 minutes

4. **Follow any additional instructions** that appear (like adding Homebrew to your PATH)

#### Step 2: Install Required Packages

```bash
brew install ncurses cmake git
```

**What this does:** Downloads and installs all three packages automatically (takes about 2-3 minutes)

#### Step 3: Install VS Code

1. Download from [code.visualstudio.com](https://code.visualstudio.com/)
2. Open the downloaded file and drag VS Code to Applications
3. Open VS Code from Applications

### For Windows 🪟

#### Understanding WSL2
WSL2 (Windows Subsystem for Linux) lets you run Linux on Windows. Think of it like a mini Linux computer inside your Windows computer. We use it because the chess game works best on Linux/Unix systems, and it's much easier than setting up native Windows tools.

#### Step 1: Install WSL2

1. **Open PowerShell as Administrator:**
   - Press Windows key
   - Type "PowerShell"
   - Right-click "Windows PowerShell"
   - Click "Run as administrator"
   - Click "Yes" when asked

2. **Install WSL2:**
   ```powershell
   wsl --install
   ```
   - This downloads and installs WSL2 and Ubuntu Linux
   - Takes 5-10 minutes
   - **Restart your computer** when prompted

#### Step 2: Set Up Ubuntu

After restarting:

1. **Open Ubuntu:**
   - Press Windows key
   - Type "Ubuntu"
   - Click on "Ubuntu"

2. **First-time setup:**
   - Wait a minute while Ubuntu finishes installing
   - Create a username (can be anything, like your name in lowercase)
   - Create a password (**Important:** When typing your password, you won't see any characters appear - this is normal for security!)

#### Step 3: Install Required Packages

Now you're in Ubuntu Linux. We need to install the development tools.

**What is apt-get?** It's Ubuntu's package manager - like an app store for Linux programs.

```bash
# Update the package list (like refreshing an app store)
sudo apt-get update

# Install all the tools we need
sudo apt-get install -y libncurses5-dev libncursesw5-dev cmake g++ git
```

**What is sudo?** It means "super user do" - it gives you administrator permissions. You'll need to enter the password you just created.

#### Step 4: Install VS Code

1. Download from [code.visualstudio.com](https://code.visualstudio.com/)
2. Install normally (it will work with WSL automatically)
3. Install the "WSL" extension in VS Code when prompted

**From now on, use the Ubuntu terminal** for all commands in this guide!

### For Linux 🐧

Good news - you're already running Linux! You just need to install the development tools.

#### Understanding Package Managers
Linux uses package managers to install software (like an app store). Different Linux versions use different ones:
- **Ubuntu/Debian**: `apt-get`
- **Fedora/RHEL**: `dnf`
- **Arch**: `pacman`

#### For Ubuntu/Debian (including Ubuntu, Mint, Pop!_OS)

**Open your terminal** (usually `Ctrl + Alt + T`)

```bash
# Update package list
sudo apt-get update

# Install required tools
sudo apt-get install -y libncurses5-dev libncursesw5-dev cmake g++ git
```

#### For Fedora/RHEL/CentOS

```bash
sudo dnf install ncurses-devel cmake gcc-c++ git
```

#### For Arch Linux

```bash
sudo pacman -S ncurses cmake gcc git
```

#### Install VS Code

Most Linux distros can install VS Code through their package manager, or download from [code.visualstudio.com](https://code.visualstudio.com/)

### Installing GitHub Copilot in VS Code

1. **Open VS Code**
2. **Press `Ctrl+Shift+X`** (Windows/Linux) or `Cmd+Shift+X`** (Mac) to open Extensions
3. **Search for "GitHub Copilot"**
4. **Click Install**
5. **Sign in** with your GitHub account when prompted
6. **Verify it's working:** Look for the Copilot icon (✓) in the bottom status bar

**Don't have Copilot access?**
- Students: Get free access at [education.github.com](https://education.github.com/)
- Others: Start a free trial at [github.com/features/copilot](https://github.com/features/copilot)

### ✅ Verify Everything is Installed

Run these commands to check:

```bash
# Check C++ compiler (need 7.0+)
g++ --version

# Check CMake (need 3.10+)
cmake --version

# Check Git
git --version
```

**If any command shows "command not found":** Go back and reinstall that tool.

---

## Building the Project

Now let's get the chess game code and build it!

### Step 1: Get the Code

**Option 1: Download as ZIP (Easier for Beginners)**
1. Go to https://github.com/HarvirChima/chess-lab
2. Click the green "Code" button
3. Click "Download ZIP"
4. Extract the ZIP file to a location you'll remember (like `Documents/chess-lab`)

**Option 2: Clone with Git**
```bash
# Create a projects folder
mkdir -p ~/projects
cd ~/projects

# Clone the repository
git clone https://github.com/HarvirChima/chess-lab.git
cd chess-lab
```

### Step 2: Build the Project

```bash
# Create a build directory (this keeps compiled files separate)
mkdir build
cd build

# Configure the project (CMake checks your system and prepares to build)
cmake ..

# Build the project (this compiles the C++ code)
make
```

**What you should see:** Progress messages like "[14%] Building..." up to "[100%] Built target chess"

**This creates three programs:**
- `chess` - The playable chess game
- `test_chess` - Unit tests to verify everything works
- `demo_board` - A demo to show the board layout

### Step 3: Verify It Works

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
✓ Pawn movement test passed
✓ Knight movement test passed
✓ Invalid move test passed
✓ Capture test passed
=========================
All tests passed! ✓
```

### Step 4: Try the Game!

```bash
# Start the chess game
./chess
```

**You should see:** A chess board with pieces in your terminal!

**Game Controls:**
- **Arrow keys** (↑ ↓ ← →) - Move cursor
- **SPACE** - Select piece, then move it
- **Q** - Quit game

**Your first move:**
1. Use arrow keys to move to `e2` (white pawn, 2nd row from bottom)
2. Press SPACE (piece highlights)
3. Move to `e4` (4th row, same column)
4. Press SPACE (pawn moves)
5. Congrats! You just made the classic "King's Pawn Opening"! ♔

**Play a few moves to get familiar with the game, then press Q to quit.**

### Step 5: Open in VS Code

```bash
# From the chess-lab directory (not the build directory)
cd ..  # if you're still in build/
code .
```

This opens the entire project in VS Code where you can see all the code files.

---

## Lab 1: Ask Mode (15 Minutes)

**Objective:** Learn to use Copilot Chat to understand and explore code.

### What is Ask Mode?

Ask Mode (Copilot Chat) lets you have a conversation with an AI that understands your code. You can ask questions about how things work, find bugs, get explanations, and more - all in natural language!

### Opening Copilot Chat

**Three ways to open it:**
1. Press `Ctrl+Shift+I` (Windows/Linux) or `Cmd+Shift+I` (Mac)
2. Click the chat icon in the left sidebar
3. Click the Copilot icon in the status bar and select "Open Chat"

### Exercise 1.1: Explore the Codebase

Open Copilot Chat and ask these questions. **Copy and paste them exactly:**

**Basic Understanding:**

```
@workspace What does this chess game project do?
```

```
@workspace How is the chess board represented in the code?
```

```
@workspace Explain the game loop in the Game class
```

**Finding Specific Code:**

```
@workspace Where is pawn movement logic implemented?
```

```
@workspace How does the code validate chess moves?
```

```
@workspace What piece types are supported in this chess game?
```

**Investigating Features:**

```
@workspace Does this chess game support castling?
```

```
@workspace Is checkmate detection implemented?
```

```
@workspace Can pawns be promoted when they reach the end?
```

**💡 What's happening?** Copilot is analyzing all the code files and answering your questions. The `@workspace` tells it to look at the entire project.

### Exercise 1.2: Ask About Specific Code

1. **Open** `src/Board.cpp` in VS Code
2. **Find** the `isValidMove` function (around line 70)
3. **Select the entire function** (click and drag to highlight it)
4. **Open Copilot Chat**
5. **Ask:**

```
Explain what this function does and how it validates moves
```

Try the same with other functions:
- Open `src/Game.cpp` and ask about the `run()` function
- Open `src/Display.cpp` and ask about the `drawBoard()` function

### Exercise 1.3: Find Potential Issues

```
@workspace Are there any potential bugs or edge cases in the move validation?
```

```
@workspace Review the Board::isValidMove function for potential issues
```

**🐛 Interesting note:** This chess game has intentional bugs that you'll fix in Lab 3!

### Exercise 1.4: Understanding the Display

Open `src/Display.cpp` and look at the `drawBoard()` function. Then ask:

```
How does ncurses work to create the chess board display? Explain like I'm 5.
```

### ✅ Lab 1 Checkpoint

You should now be able to:
- ✅ Open and use Copilot Chat
- ✅ Ask questions about code with `@workspace`
- ✅ Get explanations of specific functions
- ✅ Understand the chess game architecture
- ✅ Identify missing features (castling, promotion, checkmate)

**Take a 5-minute break before Lab 2!** ☕

---

## Lab 2: Copilot Instructions (20 Minutes)

**Objective:** Learn to customize Copilot's behavior using instructions files.

### What are Copilot Instructions?

Copilot Instructions let you tell Copilot about your project's conventions, preferences, and even add personality! This makes Copilot give better, more context-aware suggestions tailored to your project.

### Exercise 2.1: View Existing Instructions

1. **Open** `.github/copilot-instructions.md`
2. **Read through it** - you'll see it already has chess-specific guidelines!
3. Notice sections like:
   - Code Style (naming conventions)
   - Chess Domain (chess rules)
   - Fun Personality (chess puns!)

**This file already exists in the project**, but let's see how to create one from scratch.

### Exercise 2.2: Generate Instructions (Optional)

Want to see how VS Code can auto-generate instructions?

1. **Delete or rename** `.github/copilot-instructions.md` temporarily
2. **Open Command Palette:** `Ctrl+Shift+P` (Windows/Linux) or `Cmd+Shift+P` (Mac)
3. **Type:** `GitHub Copilot: Generate Instructions`
4. **Review** what VS Code generates based on your code

VS Code analyzes your code and suggests instructions automatically! Pretty cool, right?

**Restore the original file** after trying this.

### Exercise 2.3: Add Your Own Instructions

Let's add some custom instructions! Open `.github/copilot-instructions.md` and add this at the end:

```markdown
### My Custom Preferences

- When suggesting variable names, prefer descriptive names over short abbreviations
- Add a fun chess-themed comment at the start of any new function I write
- If I'm implementing a chess rule, include a brief explanation of that rule in a comment
- Suggest test cases when I add new functionality
- When I make a mistake, use encouraging language like "That's a rookie mistake - let's improve it!"
```

**Save the file** (`Ctrl+S` or `Cmd+S`).

### Exercise 2.4: Test Your Instructions

Now let's see if Copilot follows your instructions!

1. **Open** `src/Board.cpp`
2. **At the bottom of the file** (before the last `}`), start typing:

```cpp
// Function to implement castling
```

3. **Press Enter** and let Copilot suggest the function
4. **Notice:** It should include chess-themed comments and a rule explanation!

Try this too:

```cpp
// Check if position is under attack
bool Board::isUnderAttack
```

Let Copilot complete it. Does it add explanatory comments?

### Exercise 2.5: Add More Personality

Add these fun instructions to make Copilot more entertaining:

```markdown
### Emoji Usage
- Use ♔♕♖♗♘♙ (unicode chess symbols) in comments occasionally
- Use ✅ for validation that passes
- Use ❌ for validation that fails
- Use 🏆 for victory/checkmate conditions
- Use ⚠️ for important warnings

### Chess Puns
When appropriate, include chess puns like:
- "Check this out!" (for reviewing something)
- "That's a grandmaster move!" (for clever solutions)
- "Don't be a pawn, be a queen!" (for optimizations)
- "Time to castle away from that bug!" (for bug fixes)
```

### ✅ Lab 2 Checkpoint

You should now understand:
- ✅ What Copilot instructions are and why they're useful
- ✅ How to generate instructions automatically
- ✅ How to customize Copilot's behavior
- ✅ How to add personality to make coding more fun
- ✅ How instructions affect code suggestions

**Take a break! When ready, move to Lab 3 where we'll fix bugs!** 🔧

---

## Lab 3: Agent Mode (25 Minutes)

**Objective:** Use Copilot Agent Mode to fix bugs and add features across multiple files.

### What is Agent Mode?

Agent Mode (also called Copilot Edits) allows Copilot to make changes across multiple files autonomously. Instead of just suggesting code, it can actually edit files, create new files, and refactor code based on your instructions. Think of it as Copilot taking control of the keyboard!

### The Intentional Bugs

This chess game has two intentional bugs that you'll fix:

**Bug 1: Pawns Can Move Backwards! 🐛**
- In chess, pawns can ONLY move forward
- White pawns move toward row 0
- Black pawns move toward row 7
- **But our game lets them move backwards!** (illegal!)

**Bug 2: Unhelpful Error Messages**
- When you try an invalid move, the game just says "Invalid move! Try again."
- It doesn't explain WHY the move is invalid
- This is bad UX - users should learn from their mistakes!

### Opening Agent Mode

**Two ways to open it:**
1. Press `Ctrl+Shift+I` to open Chat, then click "Open Edits" button
2. Press `Ctrl+K` then `I` (or `Cmd+K` then `I` on Mac)

You'll see an "Edits" panel appear!

### Exercise 3.1: Fix Bug 1 - Pawn Backward Movement

#### Step 1: Add Files to Working Set

In the Edits panel:
1. Click "Add files" or drag files into the panel
2. Add these files:
   - `src/Board.cpp`
   - `include/Board.h`
   - `src/test_chess.cpp`

These are the files Agent Mode will be allowed to modify.

#### Step 2: Give Instructions

In the Edits panel input box, type this prompt:

```
Fix the bug that allows pawns to move backwards. In chess, pawns can only move forward:
- White pawns (uppercase P) should move from higher row numbers to lower row numbers (toward row 0)
- Black pawns (lowercase p) should move from lower row numbers to higher row numbers (toward row 7)

The bug is in the isValidMove function in Board.cpp around line 110. It currently uses absRowDiff == 1 which allows movement in ANY direction. It should check that the pawn moves in the correct direction for its color.

Also add a test case in test_chess.cpp to verify pawns cannot move backwards.
```

#### Step 3: Review the Changes

Agent Mode will:
1. Analyze the code
2. Propose changes to fix the bug
3. Show you a diff of what it wants to change

**Review carefully!** Look at:
- Does it change `absRowDiff == 1` to `rowDiff == direction`?
- Does it add proper directional checking?
- Does it add a test case?

#### Step 4: Accept or Modify

- If the changes look good, click "Accept"
- If not, click "Discard" and try a more specific prompt

#### Step 5: Test the Fix

```bash
cd build
make
./test_chess
```

All tests should pass! Now try playing:

```bash
./chess
```

Try to move a pawn backwards - it should be blocked now! ✅

### Exercise 3.2: Fix Bug 2 - Better Error Messages

#### Step 1: Add Files

Add to the working set:
- `src/Game.cpp`
- `include/Game.h`
- `src/Display.cpp` (optional)

#### Step 2: Give Instructions

```
When a player attempts an invalid move, the game should display a helpful message explaining WHY the move is invalid, not just "Invalid move! Try again."

Consider different reasons a move might be invalid:
1. Wrong turn (trying to move opponent's piece)
2. Piece can't move that way (e.g., bishop moving straight)
3. Path is blocked
4. Moving into check (future improvement)
5. No piece at starting position

Update the Game class to:
- Determine the specific reason for invalid moves
- Display educational error messages
- Help players learn chess rules

Make the messages friendly and encouraging for beginners.
```

#### Step 3: Review and Accept

Look at what Agent Mode proposes. Does it:
- Add logic to detect why moves are invalid?
- Create helpful error messages?
- Keep the beginner-friendly tone?

#### Step 4: Test

```bash
cd build
make
./chess
```

Try making invalid moves:
- Try to move a knight straight (should explain knights move in L-shape)
- Try to move your opponent's piece (should say it's not your turn)
- Try to move from an empty square (should say no piece there)

### Exercise 3.3: Add a New Feature - Move Counter

Let's add something completely new!

#### Add Files
- `src/Game.cpp`
- `include/Game.h`
- `src/Display.cpp`
- `include/Display.h`

#### Prompt

```
Add a move counter to the chess game that:
1. Tracks the total number of moves made (increments by 1 each time any player moves)
2. Displays the move count at the bottom of the board
3. Shows both the current move number and whose turn it is

Example display: "Move 5 - White's turn" or "Move 12 - Black's turn"

Add a private member variable to the Game class to track this.
```

Test it and see your move counter in action!

### Exercise 3.4: Challenge - Add Move History (Optional)

If you have extra time:

```
Add move history tracking that:
1. Stores each move with notation (e.g., "e2 to e4")
2. Displays the last 5 moves on the right side of the board
3. Uses proper chess algebraic notation if possible (e.g., "e4", "Nf3")
4. Scrolls as new moves are made

This helps players review what happened in the game.
```

### ✅ Lab 3 Checkpoint

You should now be able to:
- ✅ Open and use Agent Mode (Copilot Edits)
- ✅ Add files to the working set
- ✅ Write effective prompts for bug fixes
- ✅ Fix bugs across multiple files
- ✅ Add new features with AI assistance
- ✅ Review and validate AI-generated changes
- ✅ Test your changes thoroughly

**Great job! The chess game is getting better!** 🎉

---

## Lab 4: Prompt Files (20 Minutes)

**Objective:** Create reusable prompt files for consistent, repeatable workflows.

### What are Prompt Files?

Prompt Files (`.prompt.md` files) are reusable prompts you can invoke with a simple command. Instead of typing the same instructions over and over, you create a prompt file once and reuse it anytime! They're perfect for:
- Generating tests
- Code reviews
- Documentation
- Refactoring tasks
- Any repetitive workflow

### Exercise 4.1: Understanding Existing Prompt Files

The project already has a prompt file! Let's look at it:

1. **Open** `.github/chess-test.prompt.md`
2. **Read through it** - see how it's structured:
   - Front matter (name, description)
   - Instructions for the AI
   - Guidelines and format
   - Template variables like `{{FEATURE_NAME}}`

This prompt helps generate chess-specific test cases!

### Exercise 4.2: Use the Existing Prompt File

Let's use it to generate tests!

1. **Open Copilot Chat** (`Ctrl+Shift+I` or `Cmd+Shift+I`)
2. **Type:**

```
#file:.github/chess-test.prompt.md

Generate tests for rook movement. The rook should be able to move any number of squares horizontally or vertically, but cannot jump over pieces.
```

3. **Review the generated tests** - Copilot will create test functions following the project's patterns!
4. **Copy the good parts** to `src/test_chess.cpp`
5. **Build and run tests** to see if they work

### Exercise 4.3: Create a Code Review Prompt

Let's create your own prompt file!

1. **Create** `.github/chess-code-review.prompt.md`
2. **Add this content:**

```markdown
---
name: Chess Code Reviewer
description: Reviews chess game code for correctness and quality
---

# Chess Code Review Expert

You are an expert code reviewer specializing in game development and chess applications.

## Review Checklist

### Chess Rules
- [ ] Code follows official chess rules correctly
- [ ] Move validation is complete and accurate
- [ ] Edge cases are handled
- [ ] Special moves (castling, en passant) follow FIDE rules if implemented

### Code Quality
- [ ] Functions are focused and single-purpose
- [ ] Variable names are clear and meaningful
- [ ] Magic numbers are avoided or explained
- [ ] Comments explain "why" not just "what"
- [ ] No code duplication

### Safety
- [ ] Array bounds are checked
- [ ] No potential null pointer issues
- [ ] No memory leaks
- [ ] Error conditions are handled

### Testing
- [ ] New features have tests
- [ ] Tests cover both valid and invalid cases
- [ ] Edge cases are tested

## Output Format

For each issue found:
1. **Severity:** Critical / Major / Minor
2. **Location:** File and line number
3. **Issue:** What's wrong
4. **Suggestion:** How to fix it
5. **Example:** Show corrected code if helpful

Be constructive and educational. Remember this is a learning project!

---

Now review the following code:

{{CODE_TO_REVIEW}}
```

3. **Save the file**

### Exercise 4.4: Use Your Code Review Prompt

1. **Open** `src/Board.cpp`
2. **Select** the `isValidMove` function
3. **Open Copilot Chat**
4. **Type:**

```
#file:.github/chess-code-review.prompt.md

Review this function
```

5. **Paste or reference the code** (Copilot might automatically include it)
6. **Review the feedback** - does it find any issues?

### Exercise 4.5: Create a Documentation Prompt

Create `.github/chess-doc.prompt.md`:

```markdown
---
name: Chess Documentation Generator
description: Generates beginner-friendly documentation for chess code
---

# Chess Documentation Generator

Generate clear, educational documentation for chess game code.

## Documentation Style
- Explain chess concepts for non-chess players
- Include examples of how to use functions
- Document parameters and return values clearly
- Mention relevant chess rules
- Add "why this matters" context
- Use Doxygen-style comments

## Format
```cpp
/**
 * @brief Brief description (one line)
 * 
 * Longer description explaining what this does and why.
 * Include chess context if relevant.
 * 
 * @param paramName Description with chess context
 * @return What it returns and what that means
 * 
 * @note Any important chess rules or edge cases
 * 
 * Example usage:
 * @code
 * Board board;
 * bool valid = board.functionName(params);
 * @endcode
 */
```

---

Generate documentation for: {{FUNCTION_OR_CLASS}}
```

### Exercise 4.6: Create Your Own Prompt

Think of a repetitive task you might need. Create a prompt file for it! Ideas:
- **Bug Hunter:** `.github/find-bugs.prompt.md` - Systematically finds potential bugs
- **Refactoring Helper:** `.github/refactor.prompt.md` - Suggests code improvements
- **Feature Planner:** `.github/feature-design.prompt.md` - Plans new features
- **Performance Optimizer:** `.github/optimize.prompt.md` - Finds performance issues

### ✅ Lab 4 Checkpoint

You should now be able to:
- ✅ Understand what prompt files are and why they're useful
- ✅ Use existing prompt files
- ✅ Create your own prompt files
- ✅ Invoke prompt files in Copilot Chat
- ✅ Build a library of reusable prompts
- ✅ Share prompts with your team

**Prompt files are super powerful for team consistency!** 📋

---

## Lab 5: Custom Chat Modes (25 Minutes)

**Objective:** Create specialized AI assistants (custom chat modes) for specific tasks.

### What are Custom Chat Modes?

Custom Chat Modes are specialized AI assistants you can create for specific domains. They have their own personality, expertise, and context. Instead of generic Copilot, you can talk to a "Chess Expert" or "Test Expert"!

### Understanding Chat Modes

The project already has some defined! Look at `.github/copilot-chat-modes.json`:

```json
{
  "chatModes": [
    {
      "id": "chessexpert",
      "name": "Chess Expert",
      "description": "Chess grandmaster and programming expert",
      "systemMessage": "You are a Chess Grandmaster..."
    }
  ]
}
```

### Exercise 5.1: Use the Chess Expert

1. **Open Copilot Chat**
2. **Type `@` and see** if `@chessexpert` appears in the suggestions
3. **Try these queries:**

```
@chessexpert Can a knight jump over other pieces?
```

```
@chessexpert What are the conditions required for castling?
```

```
@chessexpert Explain how en passant works
```

```
@chessexpert Review the pawn movement logic in Board.cpp for chess rule correctness
```

**Notice:** The chess expert has deep knowledge of chess rules AND programming!

### Exercise 5.2: Add More Chat Modes

Let's add more specialized assistants. Edit `.github/copilot-chat-modes.json`:

```json
{
  "chatModes": [
    {
      "id": "chessexpert",
      "name": "Chess Expert",
      "description": "Chess grandmaster and programming expert",
      "systemMessage": "You are a Chess Grandmaster and expert programmer. Explain chess rules clearly, validate code against official chess rules, use algebraic notation, and be encouraging to learners. Include chess metaphors and occasionally reference famous games."
    },
    {
      "id": "testexpert",
      "name": "Test Expert",
      "description": "Expert in writing comprehensive test cases",
      "systemMessage": "You are a testing expert specializing in chess game applications. Generate thorough test cases covering edge cases, boundary conditions, and error scenarios. Follow TDD principles. Make tests clear and maintainable."
    },
    {
      "id": "perfexpert",
      "name": "Performance Expert",
      "description": "Expert in code optimization and performance",
      "systemMessage": "You are a performance optimization expert. Analyze code for bottlenecks, suggest algorithmic improvements, recommend profiling strategies. Focus on practical improvements that matter for real-world use."
    },
    {
      "id": "uxexpert",
      "name": "UX Expert",
      "description": "Expert in user experience design",
      "systemMessage": "You are a UX expert focusing on developer experience and end-user experience. Make error messages helpful and educational. Design intuitive interfaces. Consider accessibility and usability for beginners."
    }
  ]
}
```

### Exercise 5.3: Test Your New Chat Modes

**Test Expert:**
```
@testexpert What test cases should I write for the bishop movement validation?
```

**Performance Expert:**
```
@perfexpert Review the Board::isValidMove function for performance issues. It's called every time a move is attempted.
```

**UX Expert:**
```
@uxexpert How can I improve the error messages when players make invalid moves?
```

### Exercise 5.4: Create an Advanced Chat Mode (Optional)

Want to make the chess expert even better? You can create a full VS Code extension!

Create `.github/chess-expert/package.json`:

```json
{
  "name": "chess-expert-chat",
  "displayName": "Chess Expert Chat Mode",
  "description": "A chess expert that helps with chess programming and rules",
  "version": "0.1.0",
  "engines": {
    "vscode": "^1.85.0"
  },
  "categories": ["Chat Modes"],
  "contributes": {
    "chatModes": [
      {
        "id": "chess.expert",
        "name": "chessexpert",
        "description": "Chess expert that understands both chess rules and code",
        "isSticky": true
      }
    ]
  },
  "main": "./extension.js"
}
```

This is more advanced and optional - the JSON file method works great for most needs!

### ✅ Lab 5 Checkpoint

You should now be able to:
- ✅ Understand what chat modes are
- ✅ Use existing chat modes
- ✅ Create new chat modes
- ✅ Define specialized system prompts
- ✅ Invoke chat modes with @mentions
- ✅ Build a team of AI specialists

**You now have a team of AI assistants!** 🤖🤖🤖

---

## Lab 6: Advanced Topics (30 Minutes)

**Objective:** Master advanced Copilot techniques and best practices for professional development.

### Exercise 6.1: Advanced Prompt Engineering

Learn to write better prompts for complex tasks.

**Good Prompt Structure:**
```
[Context] + [Task] + [Constraints] + [Output Format]
```

**Example - Poor Prompt:**
```
Add checkmate detection
```

**Example - Good Prompt:**
```
Context: This is a chess game with basic move validation but no checkmate detection.

Task: Implement checkmate detection that verifies the current player has no legal moves and their king is in check.

Constraints:
- Must check all pieces for possible moves
- Must verify king is currently in check
- Should distinguish from stalemate (no legal moves but not in check)
- Add appropriate test cases
- Keep functions under 50 lines

Output Format: 
- Modify Board.cpp and Board.h
- Add isCheckmate() and isStalemate() functions
- Add test cases to test_chess.cpp
- Include comments explaining the chess rules
```

**Practice prompts:**

1. **Implementing Castling:**
```
Context: The chess game doesn't support castling yet.

Task: Implement both kingside (O-O) and queenside (O-O-O) castling according to FIDE rules.

Constraints:
- King and rook must not have moved
- No pieces between king and rook
- King not in check, doesn't move through check, doesn't end in check
- Update both Board and Game classes
- Add comprehensive tests

Output Format: Changes to Board.cpp, Board.h, Game.cpp, test_chess.cpp with clear comments explaining castling rules.
```

2. **Adding Pawn Promotion:**
```
Context: Pawns reaching the opposite end don't promote.

Task: Implement pawn promotion allowing the pawn to become Queen, Rook, Bishop, or Knight.

Constraints:
- Prompt user to choose promotion piece
- Default to Queen if no response within 5 seconds
- Update piece type and display
- Add tests for all promotion types

Output Format: Modify Board.cpp, Game.cpp, Display.cpp with promotion logic and user interface.
```

Try writing your own structured prompts!

### Exercise 6.2: Test-Driven Development with Copilot

**TDD Workflow:**
1. Write a failing test
2. Use Copilot to implement the feature
3. Verify test passes
4. Refactor if needed

**Example - Let's add move notation:**

**Step 1: Write the test first**

Open `src/test_chess.cpp` and add:

```cpp
void testMoveNotation() {
    Board board;
    board.initialize();
    
    // Test pawn move notation
    std::string notation = board.getMoveNotation(6, 4, 4, 4);
    if (notation != "e4") {
        std::cout << "✗ Pawn notation test failed" << std::endl;
        exit(1);
    }
    
    // Test knight move notation  
    notation = board.getMoveNotation(7, 1, 5, 2);
    if (notation != "Nc3") {
        std::cout << "✗ Knight notation test failed" << std::endl;
        exit(1);
    }
    
    std::cout << "✓ Move notation test passed" << std::endl;
}

// Add to main():
testMoveNotation();
```

**Step 2: Build and verify it fails**

```bash
cd build
make
./test_chess  # Should fail - function doesn't exist yet!
```

**Step 3: Ask Copilot to implement it**

Open Copilot Chat:

```
The test testMoveNotation expects a function getMoveNotation(fromRow, fromCol, toRow, toCol) that converts chess moves to algebraic notation.

Algebraic notation rules:
- Pawns: just the destination (e.g., "e4")
- Other pieces: piece letter + destination (e.g., "Nf3" for knight to f3)
- Captures: add "x" (e.g., "Bxc4")
- Castling: "O-O" (kingside) or "O-O-O" (queenside)

Implement this function in the Board class with proper algebraic notation.
```

**Step 4: Test passes!**

```bash
make
./test_chess  # Should pass now!
```

### Exercise 6.3: Code Review with Copilot

Use Copilot for systematic code reviews.

1. **Select any function** in `src/Board.cpp`
2. **Right-click** → **Copilot** → **Review Selection**
3. Or use your code review prompt:

```
#file:.github/chess-code-review.prompt.md

Review the selected code
```

Look for:
- Chess rule correctness
- Edge cases
- Code quality
- Performance issues
- Security concerns

### Exercise 6.4: Documentation Generation

Generate comprehensive documentation:

```
@workspace Generate API documentation for all public methods in the Board class. Include:
- Brief description
- Parameter descriptions with chess context
- Return value explanation
- Example usage
- Chess rules relevant to the method
- Time complexity if relevant

Format as Doxygen comments.
```

### Exercise 6.5: Performance Optimization

```
@perfexpert Analyze the Board::isValidMove function. It's called frequently during gameplay. Are there any optimizations we could make?

Consider:
- Caching valid moves
- Early exit strategies
- Redundant checks
- Algorithmic improvements
```

### Exercise 6.6: Security Review

```
@workspace Perform a security review of the chess game focusing on:
- Buffer overflow risks in array operations
- Integer overflow in calculations  
- Input validation vulnerabilities
- Memory safety issues
- Potential infinite loops

Report any issues found and suggest fixes.
```

### ✅ Lab 6 Checkpoint

You've now mastered:
- ✅ Advanced prompt engineering with structure
- ✅ Test-driven development with Copilot
- ✅ Systematic code reviews
- ✅ Documentation generation
- ✅ Performance optimization
- ✅ Security analysis

**You're now a Copilot power user!** 🚀

---

## For Instructors

### Quick Start for Teaching

**If you're teaching this lab, here's what you need:**

#### Pre-Lab Preparation (1 hour)

1. **Test it yourself:**
   ```bash
   git clone https://github.com/HarvirChima/chess-lab.git
   cd chess-lab
   mkdir build && cd build
   cmake .. && make
   ./test_chess
   ./chess
   ```

2. **Walk through Labs 1-3:**
   - Complete Lab 1 (15 min) - Get familiar with Ask Mode
   - Complete Lab 2 (20 min) - Review the instructions
   - Complete Lab 3 (25 min) - Understand the intentional bugs

3. **Review support materials:**
   - Check the [BUG_GUIDE.md](BUG_GUIDE.md) to understand the bugs in detail
   - Review [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md) for technical details
   - Test the custom chat modes

#### Session Planning

**Option 1: 2.5 Hour Workshop**
- 0:00-0:20: Setup help & introduction
- 0:20-0:35: Lab 1 (Ask Mode)
- 0:35-0:55: Lab 2 (Instructions)
- 0:55-1:00: Break ☕
- 1:00-1:25: Lab 3 (Agent Mode - bug fixing)
- 1:25-1:45: Lab 4 (Prompt Files)
- 1:45-2:10: Lab 5 (Custom Chat)
- 2:10-2:30: Lab 6 overview & Q&A

**Option 2: Self-Paced Homework**
- Students work through this guide at their own pace
- Provide office hours for questions
- Expected completion: 2.5-3 hours

**Option 3: Hybrid (Recommended)**
- **Before class:** Students complete setup + Labs 1-2
- **In class (1.5 hours):**
  - 30 min: Lab 3 walkthrough (bug fixing demo)
  - 25 min: Labs 4 & 5 guided practice
  - 20 min: Lab 6 demonstration
  - 15 min: Extensions & Q&A
- **After class:** Additional practice and extensions

#### Common Student Issues

**"I can't build the project"**
- Check they installed all prerequisites: `g++ --version`, `cmake --version`
- Common issue: ncurses not installed
- Windows users: Make sure they're using WSL, not native Windows

**"Copilot isn't working"**
- Check status bar icon (should show checkmark)
- Try reloading VS Code: `Ctrl+Shift+P` → "Reload Window"
- Verify subscription at github.com/settings/copilot

**"I don't see the bugs"**
- The bugs are intentional! Students fix them in Lab 3
- Tests still pass because tests don't cover the bug cases (by design)
- Show them [BUG_GUIDE.md](BUG_GUIDE.md) if they're stuck

**"Agent Mode isn't changing anything"**
- Make sure they added files to the working set
- Check they clicked "Accept" not "Discard"
- Try rebuilding: `cd build && make`

#### Assessment Ideas

**Quick checks:**
- Can students use `@workspace` to find code?
- Can they explain what Copilot Instructions do?
- Did they successfully fix at least one bug?
- Can they create a simple prompt file?

**Project extensions:**
- Implement castling (intermediate)
- Add checkmate detection (advanced)
- Create a simple AI opponent (advanced)
- Build move history tracking (beginner)

#### Teaching Tips

- **Demo first:** Show each lab feature before students try it
- **Pair programming:** Have students work in pairs for better learning
- **Encourage experimentation:** There's no "wrong" way to use Copilot
- **Share discoveries:** Have students share interesting Copilot responses
- **Celebrate success:** When someone fixes a bug, celebrate it! 🎉

---

## Troubleshooting

### Build Issues

**"cmake: command not found"**
```bash
# Ubuntu/Debian
sudo apt-get install cmake

# macOS
brew install cmake
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

**Build fails with compiler errors**
Your compiler might be too old. Need GCC 7.0+ or Clang 5.0+:
```bash
g++ --version  # Check version

# Ubuntu: Update if needed
sudo apt-get update
sudo apt-get upgrade g++
```

### Game Issues

**Display looks weird or has strange characters**
- Try a different terminal program
- Make sure terminal is at least 80x24 characters
- Increase font size
- Try these terminals:
  - Linux: GNOME Terminal, Konsole
  - macOS: iTerm2, Terminal.app
  - Windows: Windows Terminal (with WSL)

**"Permission denied" when running ./chess**
```bash
# Make sure you're in the build directory
cd build
./chess  # Not just "chess"
```

**Game crashes or hangs**
```bash
# Try clean rebuild
cd build
rm -rf *
cmake ..
make
```

### Copilot Issues

**Copilot not providing suggestions**
1. Check status bar - Copilot icon should show checkmark (not X)
2. Reload VS Code: `Ctrl+Shift+P` → "Reload Window"
3. Sign out and back in: `Ctrl+Shift+P` → "GitHub: Sign Out"
4. Check subscription at github.com/settings/copilot

**Chat modes not working**
1. Make sure `.github/copilot-chat-modes.json` exists
2. Reload VS Code after creating/editing the file
3. Type `@` in chat to see available chat modes

**Prompt files not found**
1. Make sure prompt files are in `.github/` directory
2. Use `#file:` prefix: `#file:.github/chess-test.prompt.md`
3. Check file extension is `.prompt.md` not just `.md`

**Agent Mode not showing up**
1. Make sure you have latest VS Code version
2. Make sure Copilot extension is up to date
3. Try opening from Chat: Click "Open Edits" button

### Git Issues

**"Permission denied" when cloning**
- Use HTTPS instead of SSH: `git clone https://github.com/HarvirChima/chess-lab.git`
- Or download as ZIP from GitHub

**Can't push changes**
- You're working on a clone - that's OK! You can't push to the original.
- To save your work: Fork the repo first, then clone your fork

---

## Next Steps

### 🎉 Congratulations!

You've completed all 6 labs and learned:
- ✅ **Lab 1:** Ask Mode for code exploration
- ✅ **Lab 2:** Copilot Instructions customization
- ✅ **Lab 3:** Agent Mode for bug fixing
- ✅ **Lab 4:** Reusable Prompt Files
- ✅ **Lab 5:** Custom Chat Modes
- ✅ **Lab 6:** Advanced techniques

### Continue Your Learning

**Project Extension Ideas:**

**Beginner:**
- Add a resign option (press R to resign)
- Implement undo/redo (take back last move)
- Add a move counter
- Improve error messages further
- Add color themes for the board

**Intermediate:**
- Implement castling (kingside and queenside)
- Add pawn promotion when reaching the end
- Implement en passant capture
- Add check detection (warn when king is in check)
- Create move history display
- Add game save/load functionality

**Advanced:**
- Implement checkmate and stalemate detection
- Create a simple AI opponent (random moves first, then improve)
- Add minimax algorithm for better AI
- Implement PGN (Portable Game Notation) import/export
- Create a chess puzzle mode
- Build a web version using Emscripten
- Add network multiplayer support
- Create a graphical interface (SDL or Qt)

### Advanced Copilot Techniques

**Architecture design:**
```
@workspace Help me design the architecture for adding an AI opponent. What classes should I create? How should they interact with existing code?
```

**Complex refactoring:**
```
@workspace The Board class is getting large. How could I refactor this into smaller, more focused classes while maintaining the same functionality?
```

**Learning from your code:**
```
@workspace Analyze my coding patterns in this project. What are my strengths and what areas could I improve?
```

### Resources

**Learning:**
- [GitHub Copilot Documentation](https://docs.github.com/en/copilot)
- [Copilot Best Practices](https://github.blog/category/copilot/)
- [LearnCpp.com](https://www.learncpp.com/) - Free C++ tutorial
- [Chess.com Learn](https://www.chess.com/learn) - Learn chess rules
- [Chess Programming Wiki](https://www.chessprogramming.org/) - Chess engine development

**Community:**
- [GitHub Issues](https://github.com/HarvirChima/chess-lab/issues) - Report bugs
- [Discussions](https://github.com/HarvirChima/chess-lab/discussions) - Ask questions
- Share your projects on social media with #ChessLab #GitHubCopilot

**Contributing:**
- Found a bug? Open an issue!
- Improved something? Submit a pull request!
- Created a cool extension? Share it with the community!
- Check [CONTRIBUTING.md](CONTRIBUTING.md) for details

### Share Your Success

- ⭐ **Star this repository** if it helped you learn!
- 📢 **Share on social media** what you built
- 💬 **Write about your experience** in Discussions
- 🎓 **Teach someone else** what you learned

---

## Final Thoughts

You've just completed a comprehensive journey through GitHub Copilot's features using a real chess game. You learned to:

- 🤖 Chat with AI to understand code
- ⚙️ Customize AI behavior for your projects
- 🔧 Let AI fix bugs across multiple files
- 📋 Create reusable workflows with prompts
- 👥 Build specialized AI assistants
- 🚀 Apply professional development practices

**The most important lesson:** GitHub Copilot is a powerful tool, but YOU are still the developer. Always review AI suggestions, understand what they do, and test thoroughly. AI assists, but you decide.

**Keep coding, keep learning, and have fun!** 🎮♟️🤖

---

**Need help?** Open an issue or start a discussion on GitHub!

**Built something cool?** Share it with us!

**Enjoying the lab?** Give it a ⭐ star on GitHub!
