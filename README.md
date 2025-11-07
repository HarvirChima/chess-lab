# Chess Lab 🎮♟️

A beginner-friendly C++ chess game application designed as a hands-on lab for learning GitHub Copilot and C++ programming.

## 🚀 Quick Start

**Choose your path:**

| I want to... | Start here |
|--------------|------------|
| 🎓 **Learn GitHub Copilot** | [GET_STARTED.md](GET_STARTED.md) → Path A |
| ♟️ **Play chess now** | [GET_STARTED.md](GET_STARTED.md) → Path B |
| 🤝 **Contribute code** | [CONTRIBUTING.md](CONTRIBUTING.md) |

## 🎯 What is This Lab?

An **interactive learning project** perfect for:
- 🆕 **Complete beginners** learning to code with AI assistance
- 💻 **Developers** exploring GitHub Copilot capabilities
- 🎓 **Students** learning C++ and game development  
- 🤖 **Anyone** wanting hands-on AI-assisted coding experience

**No prior chess programming experience needed!** Everything is explained step by step.

## 🎓 The Lab Experience

**6-part hands-on lab (2.5 hours total):**

1. **Lab 1 (15 min)**: Ask Mode - Query code naturally
2. **Lab 2 (20 min)**: Copilot Instructions - Customize AI behavior
3. **Lab 3 (25 min)**: Agent Mode - Fix bugs autonomously
4. **Lab 4 (20 min)**: Prompt Files - Create reusable prompts
5. **Lab 5 (25 min)**: Custom Chat - Build specialized AI assistants
6. **Lab 6 (30 min)**: Advanced - Master best practices

**→ Start learning:** [GET_STARTED.md](GET_STARTED.md)

## 📚 Documentation Hub

### 🎓 For Students & Learners
- **[GET_STARTED.md](GET_STARTED.md)** - Start here! Choose your path (Learning or Playing)
- **[LAB_GUIDE.md](LAB_GUIDE.md)** - Complete lab exercises (6 parts, 2.5 hours)
- **[REFERENCE.md](REFERENCE.md)** - Quick reference card for commands
- **[BUG_GUIDE.md](BUG_GUIDE.md)** - Details on intentional bugs (for Lab 3)

### 🤝 For Contributors & Teachers
- **[CONTRIBUTING.md](CONTRIBUTING.md)** - How to contribute code or improvements
- **[PROJECT_SUMMARY.md](PROJECT_SUMMARY.md)** - Technical architecture details

**Teaching this lab?** See the [Teaching Tips](#-teaching-tips) section below.

## ✨ Features

- ✅ Complete chess game with standard rules
- ✅ Beautiful terminal display with Unicode chess pieces (♔♕♖♗♘♙)
- ✅ Interactive gameplay with arrow key navigation
- ✅ Move validation and turn-based play
- ✅ Unit tests and demo tools
- ✅ Comprehensive learning labs for GitHub Copilot

## 🎮 Game Controls

| Key | Action |
|-----|--------|
| ↑ ↓ ← → | Move cursor |
| SPACE | Select piece / Move piece |
| Q | Quit |

**Your first move:** Use arrows → `e2` → SPACE → `e4` → SPACE

**Full instructions:** See [GET_STARTED.md](GET_STARTED.md)

## 📁 Project Structure

```
chess-lab/
├── GET_STARTED.md         # ← Start here!
├── README.md              # ← You are here
├── LAB_GUIDE.md           # Complete lab exercises
├── INSTRUCTOR_GUIDE.md    # For instructors
├── CONTRIBUTING.md        # Contribution guide
├── REFERENCE.md           # Quick reference
│
├── include/               # Header files
│   ├── Board.h           # Board class
│   ├── Piece.h           # Piece class
│   ├── Game.h            # Game class
│   └── Display.h         # Display class
│
└── src/                   # Implementation files
    ├── main.cpp          # Entry point
    ├── Board.cpp         # Move validation
    ├── Game.cpp          # Game loop
    ├── Display.cpp       # Terminal UI
    └── test_chess.cpp    # Unit tests
```

**Full details:** See [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md)

## 🎓 Learning Paths

### Beginner Path
1. ✅ Build and run the game → [GET_STARTED.md](GET_STARTED.md)
2. Play a complete game
3. Complete Lab 1 & 2 → [LAB_GUIDE.md](LAB_GUIDE.md)
4. Try modifying simple messages in code

### Intermediate Path
1. Complete all 6 labs → [LAB_GUIDE.md](LAB_GUIDE.md)
2. Fix the intentional bugs → [BUG_GUIDE.md](BUG_GUIDE.md)
3. Add a new feature (move counter, move history)
4. Write additional unit tests

### Advanced Path
1. Implement missing chess features (castling, en passant, promotion)
2. Add check and checkmate detection
3. Create an AI opponent
4. Build a graphical interface
5. Contribute back → [CONTRIBUTING.md](CONTRIBUTING.md)

## 🤝 Contributing

Want to improve this lab?
- Fix bugs you find
- Add more exercises
- Improve documentation
## 🤝 Contributing

Want to improve this lab? We welcome contributions!

**Ways to contribute:**
- 🐛 Fix bugs you find
- ✨ Add new features or exercises
- 📝 Improve documentation
- 🎓 Share your success stories

**See [CONTRIBUTING.md](CONTRIBUTING.md) for full guide**

## 👨‍🏫 Teaching Tips

**Using this lab in a classroom or workshop?** Here are some tips:

### Quick Setup for Instructors

1. **Test it yourself first** (1 hour):
   - Clone the repo and build it: `git clone https://github.com/HarvirChima/chess-lab.git && cd chess-lab && mkdir build && cd build && cmake .. && make`
   - Run through Lab 1-3 yourself to understand the flow
   - Try the intentional bugs (see [BUG_GUIDE.md](BUG_GUIDE.md))

2. **Prepare students** (share before class):
   - Send link to [GET_STARTED.md](GET_STARTED.md)
   - Students should have tools installed before class
   - Verify students have GitHub Copilot access

### Suggested Class Structure

**Option 1: 2.5 Hour Workshop**
- 0:00-0:20: Setup help & introduction
- 0:20-0:35: Lab 1 (Ask Mode)
- 0:35-0:55: Lab 2 (Copilot Instructions)
- 0:55-1:00: Break
- 1:00-1:25: Lab 3 (Agent Mode - bug fixing)
- 1:25-1:45: Lab 4 (Prompt Files)
- 1:45-2:10: Lab 5 (Custom Chat)
- 2:10-2:30: Lab 6 overview & Q&A

**Option 2: Self-Paced (Homework)**
- Students work through [LAB_GUIDE.md](LAB_GUIDE.md) at their own pace
- Provide office hours for questions
- Expected completion: 2.5-3 hours

### Common Student Issues

**"I can't build the project"**
- Check they have all prerequisites: `g++ --version`, `cmake --version`
- Common issue: ncurses not installed
- Solution: See [GET_STARTED.md](GET_STARTED.md) Installation Guide

**"Copilot isn't working"**
- Check status bar icon in VS Code (should show checkmark)
- Try reloading VS Code: `Ctrl+Shift+P` → "Reload Window"
- Verify subscription at github.com/settings/copilot

**"I don't see the bugs in Lab 3"**
- The bugs are intentional! Students fix them as part of the lab
- Tests still pass because tests don't cover the bug cases
- See [BUG_GUIDE.md](BUG_GUIDE.md) for details

### Assessment Ideas

- Have students fix all intentional bugs
- Ask them to add a new feature (e.g., move counter, castling)
- Have them create their own prompt file
- Ask them to explain 3 Copilot best practices they learned

### Time Estimates

- Building & setup: 5-10 minutes
- Each lab: 15-30 minutes (as labeled)
- Total lab time: 2.5 hours
- Adding a new feature: 30-60 minutes

## 📚 Additional Resources

**Learning:**
- [LearnCpp.com](https://www.learncpp.com/) - Free C++ tutorial
- [Chess.com Learn](https://www.chess.com/learn) - Learn chess
- [Copilot Documentation](https://docs.github.com/en/copilot) - GitHub Copilot docs

**Support:**
- [GitHub Issues](https://github.com/HarvirChima/chess-lab/issues) - Report bugs
- [Discussions](https://github.com/HarvirChima/chess-lab/discussions) - Ask questions

## ❓ FAQ

**Q: Do I need to know chess?**  
A: No! You'll learn by playing.

**Q: Do I need GitHub Copilot?**  
A: No! The game works without it, but Copilot makes learning easier.

**Q: How long does the lab take?**  
A: 5 minutes to build and play. 2.5 hours for complete lab exercises.

**Q: What if I'm stuck?**  
A: Check [GET_STARTED.md](GET_STARTED.md) troubleshooting, search online, or open a GitHub issue.

**Q: Can I use this for my own project?**  
A: Yes! This is open source for educational purposes.

---

## 🚀 Ready to Begin?

**→ [GET_STARTED.md](GET_STARTED.md)** ← Start here!

**Enjoying the lab?** Give it a ⭐ star on GitHub!


