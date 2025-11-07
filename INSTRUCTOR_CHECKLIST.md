# Instructor Checklist - Chess Lab Setup

Use this checklist to verify the Chess Lab is ready for students.

## Pre-Lab Setup (Instructor)

### 1. Repository Verification
- [ ] Clone the repository
- [ ] Run `./verify-lab.sh` - all checks should pass
- [ ] Build the project: `mkdir build && cd build && cmake .. && make`
- [ ] Run tests: `./build/test_chess` - all 6 tests should pass
- [ ] Try the game: `./build/chess` - should run without errors

### 2. Documentation Review
- [ ] Open `LAB_GUIDE.md` - verify all 6 labs are complete
- [ ] Check `QUICKSTART_LAB.md` - instructions are clear
- [ ] Review `BUG_GUIDE.md` - bugs are documented
- [ ] Verify `LAB_IMPLEMENTATION.md` - summary is accurate

### 3. Copilot Configuration
- [ ] `.github/copilot-instructions.md` exists
- [ ] `.github/chess-test.prompt.md` exists
- [ ] `.github/copilot-chat-participants.json` exists
- [ ] `.vscode/settings.json` exists

### 4. Intentional Bugs Present
- [ ] **Bug 1**: Pawn backward movement (src/Board.cpp line ~110)
  - Check: `grep "absRowDiff == 1" src/Board.cpp` should find it
- [ ] **Bug 2**: Generic error message (src/Game.cpp line ~120)
  - Check: `grep "Invalid move! Try again." src/Game.cpp` should find it

### 5. GitHub Copilot Requirements
- [ ] Students have GitHub accounts
- [ ] Students have Copilot access (subscription or trial)
- [ ] Students have VS Code installed
- [ ] Copilot extension is available

## Student Prerequisites

### Required Knowledge
- [ ] Basic terminal/command line usage
- [ ] Basic text editor skills
- [ ] Willingness to learn (no C++ or chess knowledge required!)

### Required Software (Students Must Install)
- [ ] **VS Code** - Latest version
- [ ] **GitHub Copilot** - Extension installed and activated
- [ ] **C++ Compiler** - GCC 7+ or Clang 5+
- [ ] **CMake** - Version 3.10+
- [ ] **ncurses** - Development libraries
- [ ] **Git** - Any recent version

### Installation Guides Available
- [ ] macOS instructions (Homebrew) - in LAB_GUIDE.md
- [ ] Windows WSL2 instructions - in LAB_GUIDE.md
- [ ] Linux instructions (apt/dnf) - in LAB_GUIDE.md

## Lab Session Planning

### Recommended Schedule (2.5 hours total)

**Session 1: Introduction & Labs 1-2 (50 minutes)**
- [ ] 10 min: Introduction, setup verification
- [ ] 15 min: Lab 1 - Ask Mode
- [ ] 20 min: Lab 2 - Copilot Instructions
- [ ] 5 min: Break

**Session 2: Labs 3-4 (50 minutes)**
- [ ] 25 min: Lab 3 - Agent Mode (bug fixing)
- [ ] 20 min: Lab 4 - Prompt Files
- [ ] 5 min: Break

**Session 3: Labs 5-6 & Wrap-up (50 minutes)**
- [ ] 25 min: Lab 5 - Custom Chat Modes
- [ ] 15 min: Lab 6 - Advanced Topics (overview)
- [ ] 10 min: Q&A, next steps, extensions

### Alternative: Self-Paced
- [ ] Share repository link
- [ ] Students follow LAB_GUIDE.md at their own pace
- [ ] Provide office hours for questions
- [ ] Estimated completion time: 2.5-3 hours

## Common Issues & Solutions

### Issue: Build Fails
**Causes:**
- Missing ncurses library
- Compiler too old
- CMake too old

**Solutions:**
- Refer to LAB_GUIDE.md installation section
- Try WSL2 on Windows
- Check `g++ --version` and `cmake --version`

### Issue: Copilot Not Working
**Causes:**
- Not signed in
- Subscription expired
- Extension disabled

**Solutions:**
- Check status bar icon
- Sign in to GitHub in VS Code
- Reload VS Code window
- Verify subscription at github.com/settings/copilot

### Issue: Students Don't See Bugs
**Explanation:**
- The bugs are intentional!
- They're supposed to fix them in Lab 3
- Tests still pass because tests don't cover the bug cases

**Verification:**
- Run `./verify-lab.sh` to confirm bugs are present

### Issue: Game Won't Run
**Causes:**
- Terminal too small
- ncurses display issues
- Not built yet

**Solutions:**
- Resize terminal to at least 80x24
- Try different terminal emulator
- Run `make` in build directory

## Lab Completion Criteria

Students successfully completed the lab if they can:
- [ ] Use Copilot Chat to query code
- [ ] Explain what Copilot Instructions do
- [ ] Fix at least one intentional bug
- [ ] Create a custom prompt file
- [ ] Invoke a custom chat participant
- [ ] Describe 3 best practices for using Copilot

## Post-Lab Activities

### Homework Ideas
- [ ] Implement castling
- [ ] Add pawn promotion
- [ ] Create en passant capture
- [ ] Implement checkmate detection
- [ ] Build an AI opponent

### Assessment Options
- [ ] Have students fix all remaining bugs
- [ ] Ask them to add a new feature
- [ ] Request they create a custom prompt file
- [ ] Have them write tests for new functionality

### Extensions
- [ ] Implement additional chess features
- [ ] Port to a graphical interface
- [ ] Add network multiplayer
- [ ] Create chess puzzle mode
- [ ] Build opening book database

## Instructor Resources

### Documentation
- **LAB_GUIDE.md** - Main student guide
- **LAB_IMPLEMENTATION.md** - Technical overview
- **BUG_GUIDE.md** - Bug documentation
- **README.md** - Project overview

### Support
- GitHub Issues - For questions or bugs
- verify-lab.sh - Automated verification
- test_chess - Automated testing

### Customization
- Edit `.github/copilot-instructions.md` for custom guidelines
- Add more prompt files in `.github/`
- Modify labs in LAB_GUIDE.md as needed
- Add custom chat participants

## Troubleshooting During Lab

### Quick Commands
```bash
# Verify setup
./verify-lab.sh

# Clean rebuild
cd build && rm -rf * && cmake .. && make

# Run tests
./build/test_chess

# Check for bugs (should find them)
grep "absRowDiff == 1" src/Board.cpp
grep "Invalid move! Try again." src/Game.cpp
```

### Student Help Commands
```bash
# Check installations
g++ --version
cmake --version
git --version

# Check VS Code Copilot
# Open VS Code and check status bar
```

## Final Checklist Before Starting

- [ ] All documentation reviewed
- [ ] Lab tested personally
- [ ] Students notified of prerequisites
- [ ] Installation guides shared in advance
- [ ] GitHub Copilot access confirmed
- [ ] Room/setup prepared (if in-person)
- [ ] Time allocated appropriately
- [ ] Support resources ready

---

## Quick Start for Instructors

1. **Clone and verify**:
   ```bash
   git clone https://github.com/HarvirChima/chess-lab.git
   cd chess-lab
   ./verify-lab.sh
   ```

2. **Review LAB_GUIDE.md** to familiarize yourself with exercises

3. **Try Lab 3 yourself** to understand the bug-fixing workflow

4. **Test custom chat participants** (@chessexpert, @testexpert)

5. **You're ready!** Share the repository with students

---

**Questions?** Open an issue on GitHub or refer to LAB_IMPLEMENTATION.md

**Ready to teach!** 🎓♟️
