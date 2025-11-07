# Instructor Guide - Chess Lab 🎓

Complete guide for instructors teaching the GitHub Copilot Chess Lab.

## 📋 Table of Contents

1. [Quick Start for Instructors](#quick-start-for-instructors)
2. [Pre-Lab Setup](#pre-lab-setup)
3. [Lab Overview](#lab-overview)
4. [Session Planning](#session-planning)
5. [Common Issues & Solutions](#common-issues--solutions)
6. [Assessment & Extensions](#assessment--extensions)
7. [Technical Details](#technical-details)

---

## Quick Start for Instructors

**First time teaching this lab? Start here:**

1. **Clone and verify** (5 minutes):
   ```bash
   git clone https://github.com/HarvirChima/chess-lab.git
   cd chess-lab
   ./verify-lab.sh
   ```

2. **Walk through Lab 1-3** yourself (45 minutes):
   - Open [LAB_GUIDE.md](LAB_GUIDE.md)
   - Complete Lab 1 (Ask Mode)
   - Complete Lab 2 (Copilot Instructions)
   - Complete Lab 3 (Agent Mode - understand the intentional bugs!)

3. **Test custom features** (10 minutes):
   - Try `@chessexpert` chat participant
   - Test prompt files in `.github/`
   - Verify Copilot instructions work

4. **Review support materials**:
   - Check [BUG_GUIDE.md](BUG_GUIDE.md) for bug details
   - Review [GET_STARTED.md](GET_STARTED.md) for student instructions
   - Check [REFERENCE.md](REFERENCE.md) for quick commands

5. **You're ready!** Share repository with students.

---

## Pre-Lab Setup

### 1. Repository Verification

**Run the verification script:**
```bash
./verify-lab.sh
```

**Manual verification checklist:**
- [ ] Clone repository successfully
- [ ] Build completes: `mkdir build && cd build && cmake .. && make`
- [ ] All tests pass: `./build/test_chess` (6 tests should pass)
- [ ] Game runs: `./build/chess`
- [ ] Demo works: `./build/demo_board`

### 2. Documentation Review

**Core student materials:**
- [ ] [GET_STARTED.md](GET_STARTED.md) - Clear entry point
- [ ] [LAB_GUIDE.md](LAB_GUIDE.md) - All 6 labs complete
- [ ] [BUG_GUIDE.md](BUG_GUIDE.md) - Bugs documented
- [ ] [REFERENCE.md](REFERENCE.md) - Quick reference available

**Support materials:**
- [ ] [README.md](README.md) - Project overview
- [ ] [CONTRIBUTING.md](CONTRIBUTING.md) - For contributors
- [ ] [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md) - Technical details

### 3. Verify Intentional Bugs

**Bug 1: Pawn Backward Movement**
```bash
grep "absRowDiff == 1" src/Board.cpp
# Should find the buggy line at ~line 110
```

**Bug 2: Generic Error Messages**
```bash
grep "Invalid move! Try again." src/Game.cpp
# Should find generic error message at ~line 120
```

**Why bugs exist:** Students fix these in Lab 3 using Agent Mode!

### 4. Copilot Configuration Files

**Verify these files exist:**
- [ ] `.github/copilot-instructions.md` - Project-specific guidelines
- [ ] `.github/chess-test.prompt.md` - Test generation prompt
- [ ] `.github/copilot-chat-participants.json` - Custom chat modes
- [ ] `.github/README.md` - Configuration documentation
- [ ] `.vscode/settings.json` - VS Code settings

### 5. Student Prerequisites

**Required knowledge:**
- [ ] Basic terminal/command line usage
- [ ] Basic text editor skills
- [ ] Willingness to learn (no C++ or chess knowledge required!)

**Required software** (students must install):
- [ ] **VS Code** - Latest version
- [ ] **GitHub Copilot** - Extension + active subscription/trial
- [ ] **C++ Compiler** - GCC 7+ or Clang 5+
- [ ] **CMake** - Version 3.10+
- [ ] **ncurses** - Development libraries
- [ ] **Git** - Any recent version

**Installation guides:** All included in [GET_STARTED.md](GET_STARTED.md) for macOS, Windows (WSL), and Linux.

---

## Lab Overview

### Lab Structure

| Lab | Topic | Time | Key Skills |
|-----|-------|------|------------|
| 1 | Ask Mode | 15 min | Query code, understand codebase |
| 2 | Copilot Instructions | 20 min | Customize AI behavior |
| 3 | Agent Mode | 25 min | Fix bugs autonomously |
| 4 | Prompt Files | 20 min | Create reusable prompts |
| 5 | Custom Chat | 25 min | Build specialized AI assistants |
| 6 | Advanced Topics | 30 min | Best practices, TDD, optimization |

**Total time:** ~2.5 hours

### Learning Outcomes

After completing all labs, students will be able to:

1. **Use Ask Mode effectively**
   - Query codebases with natural language
   - Find features and bugs quickly
   - Understand unfamiliar code

2. **Customize Copilot behavior**
   - Write Copilot instructions
   - Set project conventions
   - Add personality to suggestions

3. **Use Agent Mode**
   - Fix bugs across multiple files
   - Add features autonomously
   - Review and refine AI changes

4. **Create reusable prompts**
   - Build prompt libraries
   - Generate consistent outputs
   - Share prompts with teams

5. **Build custom AI assistants**
   - Create domain-specific chat participants
   - Define specialized expertise
   - Enhance team workflows

6. **Apply advanced techniques**
   - Write effective prompts
   - Practice TDD with AI
   - Conduct AI-assisted reviews

### Intentional Bugs (For Lab 3)

**Bug 1: Pawn Backward Movement** 🐛
- **Location:** `src/Board.cpp` line ~110
- **Issue:** Uses `absRowDiff == 1` instead of `rowDiff == direction`
- **Effect:** Pawns can move backwards (illegal in chess!)
- **Learning:** Move validation, chess rules, directional logic

**Bug 2: Unhelpful Error Messages**
- **Location:** `src/Game.cpp` line ~120
- **Issue:** Generic "Invalid move! Try again." message
- **Effect:** Users don't learn why moves fail
- **Learning:** UX design, error handling, educational software

**Missing Features** (Optional extensions):
- Move history tracking
- Castling support
- En passant captures
- Pawn promotion
- Checkmate detection

---

## Session Planning

### Option 1: Instructor-Led (2.5 hours)

**Session 1: Introduction & Setup (50 minutes)**
- 10 min: Welcome, objectives, verify prerequisites
- 10 min: Clone repo, build project, run tests
- 15 min: Lab 1 - Ask Mode (explore codebase)
- 15 min: Lab 2 - Copilot Instructions (customize)
- 5 min: Break

**Session 2: Bug Fixing & Prompts (50 minutes)**
- 25 min: Lab 3 - Agent Mode (fix intentional bugs)
- 20 min: Lab 4 - Prompt Files (reusable templates)
- 5 min: Break

**Session 3: Advanced & Wrap-up (50 minutes)**
- 25 min: Lab 5 - Custom Chat (chat participants)
- 15 min: Lab 6 - Advanced (overview of best practices)
- 10 min: Q&A, next steps, extensions

### Option 2: Self-Paced

**Advantages:**
- Students work at their own pace
- Can deep-dive into areas of interest
- Flexible scheduling

**Recommended structure:**
1. Share repository link
2. Point students to [GET_STARTED.md](GET_STARTED.md)
3. Students follow [LAB_GUIDE.md](LAB_GUIDE.md)
4. Provide office hours for questions
5. Estimated completion: 2.5-3 hours

**Tips for self-paced:**
- Set a deadline for completion
- Create a discussion forum for questions
- Schedule optional check-in sessions
- Provide assessment at the end

### Option 3: Hybrid (Recommended)

**Before class:**
- Students complete setup (GET_STARTED.md)
- Students complete Lab 1 & 2 on their own

**In class (1.5 hours):**
- 30 min: Lab 3 walkthrough (bug fixing with Agent Mode)
- 25 min: Labs 4 & 5 guided practice
- 20 min: Lab 6 demonstration & best practices
- 15 min: Extensions & Q&A

**After class:**
- Students complete remaining exercises
- Work on extension projects
- Share solutions in forum

---

## Common Issues & Solutions

### Issue: Build Fails

**Common causes:**
- Missing ncurses library
- Compiler too old (need GCC 7+)
- CMake too old (need 3.10+)
- Wrong directory (must build in build/)

**Solutions:**
```bash
# Check versions
g++ --version    # Need 7.0+
cmake --version  # Need 3.10+

# Install missing packages (Ubuntu/Debian)
sudo apt-get install libncurses5-dev libncursesw5-dev cmake g++

# Try clean rebuild
rm -rf build
mkdir build && cd build
cmake .. && make
```

**Alternative for Windows:** Use WSL2 instead of native MinGW (much easier!)

### Issue: Copilot Not Working

**Common causes:**
- Not signed in to GitHub in VS Code
- Subscription expired or not activated
- Extension disabled
- Network/proxy issues

**Solutions:**
1. Check status bar - Copilot icon should show checkmark
2. Click icon if warning appears
3. Press `Ctrl+Shift+P` → "GitHub Copilot: Sign In"
4. Reload VS Code: `Ctrl+Shift+P` → "Reload Window"
5. Verify subscription at github.com/settings/copilot
6. Check if firewall/proxy blocking GitHub

### Issue: Students Don't See Bugs

**Explanation:** The bugs are **intentional**! They're supposed to fix them in Lab 3.

**Why tests still pass:** Tests don't cover the specific bug cases (intentional design).

**Verification:**
```bash
./verify-lab.sh  # Confirms bugs are present
```

### Issue: Game Display Problems

**Common causes:**
- Terminal too small
- Terminal doesn't support ncurses properly
- Font issues

**Solutions:**
- Resize terminal to at least 80x24 characters
- Try different terminal emulator:
  - Linux: GNOME Terminal, Konsole
  - macOS: iTerm2, Terminal.app
  - Windows: Windows Terminal with WSL
- Increase font size
- Check `TERM` environment variable

### Issue: Students Stuck on Labs

**Lab 1 (Ask Mode):**
- Show them how to open Copilot Chat (`Ctrl+Shift+I`)
- Demonstrate using `@workspace`
- Practice asking questions about specific files

**Lab 2 (Instructions):**
- Help them find `.github/copilot-instructions.md`
- Show how to test if instructions are working
- Encourage creativity with personality instructions

**Lab 3 (Agent Mode):**
- Demonstrate how to add files to working set
- Show the bug location if they're really stuck
- Remind them to test after fixing

**Lab 4 (Prompt Files):**
- Show how to reference prompt files with `#file:`
- Demonstrate creating a simple prompt
- Encourage trying their own prompts

**Lab 5 (Custom Chat):**
- Explain chat participants concept
- Show how to invoke with `@chessexpert`
- Help debug JSON syntax if needed

---

## Assessment & Extensions

### Lab Completion Criteria

Students successfully completed the lab if they can:
- [ ] Use Copilot Chat to query code
- [ ] Explain what Copilot Instructions do
- [ ] Fix at least one intentional bug
- [ ] Create a custom prompt file
- [ ] Invoke a custom chat participant
- [ ] Describe 3 best practices for using Copilot

### Quick Assessment Questions

1. **Understanding**: "Explain how the Board class validates moves"
2. **Copilot Usage**: "Show me how to use @workspace to find a function"
3. **Problem Solving**: "Walk me through fixing the pawn backward movement bug"
4. **Best Practices**: "What makes a good Copilot prompt?"

### Extension Projects

**Beginner:**
- [ ] Implement move counter display
- [ ] Add "new game" restart option
- [ ] Improve error messages for all invalid moves
- [ ] Create additional unit tests

**Intermediate:**
- [ ] Add move history tracking and display
- [ ] Implement castling (kingside and queenside)
- [ ] Add pawn promotion when reaching end
- [ ] Implement en passant capture
- [ ] Add game save/load functionality

**Advanced:**
- [ ] Implement check detection
- [ ] Add checkmate and stalemate detection
- [ ] Create simple AI opponent (random moves)
- [ ] Improve AI with minimax algorithm
- [ ] Add PGN import/export
- [ ] Create puzzle mode
- [ ] Build graphical interface (SDL/Qt)

### Homework Ideas

**Individual:**
- Fix all remaining bugs
- Implement castling
- Add comprehensive test suite
- Write documentation for new features

**Group Projects:**
- Build complete AI opponent as team
- Create web version with Emscripten
- Add network multiplayer
- Design chess puzzle database

---

## Technical Details

### Project Architecture

```
chess-lab/
├── include/           # Header files
│   ├── Board.h       # Board class - move validation
│   ├── Piece.h       # Piece class - piece types
│   ├── Game.h        # Game class - game flow
│   └── Display.h     # Display class - ncurses UI
│
├── src/              # Implementation files
│   ├── main.cpp      # Entry point
│   ├── Board.cpp     # Move validation logic
│   ├── Piece.cpp     # Piece definitions
│   ├── Game.cpp      # Game loop & input
│   ├── Display.cpp   # Terminal rendering
│   ├── test_chess.cpp    # Unit tests
│   └── demo_board.cpp    # Demo visualization
│
├── .github/          # Copilot configuration
│   ├── copilot-instructions.md
│   ├── chess-test.prompt.md
│   └── copilot-chat-participants.json
│
└── CMakeLists.txt    # Build configuration
```

### Key Components

**Board Class:**
- Manages 8x8 chess board
- Validates all moves according to chess rules
- Handles piece placement and capture
- Location: `include/Board.h`, `src/Board.cpp`

**Game Class:**
- Controls game flow and turns
- Handles user input (arrow keys, space)
- Manages game state
- Location: `include/Game.h`, `src/Game.cpp`

**Display Class:**
- ncurses-based terminal UI
- Draws board and pieces
- Shows messages and status
- Location: `include/Display.h`, `src/Display.cpp`

**Piece Class:**
- Represents chess pieces
- Defines piece types and colors
- Location: `include/Piece.h`, `src/Piece.cpp`

### Build System

- **CMake 3.10+** required
- **C++17** standard
- **ncurses** library dependency
- Generates 3 executables:
  - `chess` - Main game
  - `test_chess` - Unit tests
  - `demo_board` - Demo viewer

### Test Suite

**Current tests** (in `test_chess.cpp`):
1. Piece creation test
2. Board initialization test
3. Pawn movement test
4. Knight movement test
5. Invalid move test
6. Capture test

**All tests should pass** (the bugs are in code not covered by existing tests).

### Copilot Configuration

**Files created for lab:**
- `.github/copilot-instructions.md` - Project guidelines
- `.github/chess-test.prompt.md` - Test generation prompt
- `.github/copilot-chat-participants.json` - Custom chat modes
- `.vscode/settings.json` - VS Code configuration

---

## Troubleshooting Commands

### Quick Verification

```bash
# Verify setup
./verify-lab.sh

# Check for bugs (should find them)
grep "absRowDiff == 1" src/Board.cpp
grep "Invalid move! Try again." src/Game.cpp
```

### Clean Rebuild

```bash
cd build
rm -rf *
cmake ..
make
```

### Run Everything

```bash
# From build directory
./test_chess      # Run tests
./demo_board      # View demo
./chess           # Play game
```

### Check Student Environment

```bash
# Check installations
g++ --version     # Need 7.0+
cmake --version   # Need 3.10+
git --version
code --version    # VS Code
```

---

## Final Checklist

**Before starting lab:**
- [ ] Repository cloned and verified
- [ ] Personal walkthrough of Labs 1-3 completed
- [ ] All documentation reviewed
- [ ] Students notified of prerequisites
- [ ] Installation guides shared in advance
- [ ] GitHub Copilot access confirmed for all students
- [ ] Support resources prepared (this guide, BUG_GUIDE.md)
- [ ] Time allocated appropriately
- [ ] Discussion forum or Q&A channel set up

**During lab:**
- [ ] Welcome and set expectations
- [ ] Verify students can build and run
- [ ] Be available for questions
- [ ] Monitor progress, offer hints
- [ ] Encourage experimentation
- [ ] Celebrate successes!

**After lab:**
- [ ] Provide assessment or homework
- [ ] Share extension project ideas
- [ ] Gather feedback for improvement
- [ ] Offer office hours for continued help

---

## Additional Resources

**For you:**
- [BUG_GUIDE.md](BUG_GUIDE.md) - Detailed bug documentation
- [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md) - Technical overview
- verify-lab.sh - Automated verification script

**For students:**
- [GET_STARTED.md](GET_STARTED.md) - Quick start guide
- [LAB_GUIDE.md](LAB_GUIDE.md) - Complete lab exercises
- [REFERENCE.md](REFERENCE.md) - Quick reference card
- [CONTRIBUTING.md](CONTRIBUTING.md) - Contribution guide

**Support:**
- GitHub Issues - For bugs or questions
- GitHub Discussions - For general questions
- This guide - For teaching tips

---

## Questions?

**Can't find something?** Open an issue on GitHub and we'll help!

**Want to customize the lab?** Feel free to modify:
- Copilot instructions in `.github/copilot-instructions.md`
- Lab exercises in LAB_GUIDE.md
- Add more prompt files in `.github/`
- Create additional chat participants

**Want to contribute improvements?** See [CONTRIBUTING.md](CONTRIBUTING.md)

---

**Ready to teach! Good luck! 🎓♟️**
