# GitHub Copilot Chess Lab 🎮♟️

Welcome to the GitHub Copilot Chess Lab! This hands-on lab will guide you through 6 different exercises to master GitHub Copilot's features using a real chess game application.

## 🎯 What You'll Learn

By the end of this lab, you'll be proficient with:
- **Ask Mode**: Query and understand code using natural language
- **Copilot Instructions**: Customize Copilot's behavior for your project
- **Agent Mode**: Let Copilot make multi-file changes autonomously
- **Prompt Files**: Create reusable prompts for consistent workflows
- **Custom Chat Modes**: Build specialized AI assistants for your domain

## ⚙️ Prerequisites & Installation

Before starting the labs, ensure your environment is properly configured.

### Required Software

You'll need the following installed:

1. **Visual Studio Code** (VS Code)
2. **GitHub Copilot** (subscription required)
3. **C++ Compiler** and **CMake**
4. **ncurses library**
5. **Git**

### Installation Instructions

#### For macOS 🍎

```bash
# Install Homebrew if you don't have it
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install required packages
brew install ncurses cmake git

# Verify installations
cmake --version    # Should be 3.10+
git --version
g++ --version      # Should be 7.0+
```

#### For Windows 🪟

**Option 1: Using WSL2 (Recommended)**

1. Open PowerShell as Administrator and run:
```powershell
wsl --install
```

2. Restart your computer when prompted

3. Open Ubuntu from the Start menu and set up your username/password

4. Inside WSL Ubuntu terminal, run:
```bash
# Update package list
sudo apt-get update

# Install all required tools
sudo apt-get install -y libncurses5-dev libncursesw5-dev cmake g++ git build-essential

# Verify installations
cmake --version    # Should be 3.10+
git --version
g++ --version      # Should be 7.0+
```

**Option 2: Using MinGW (Alternative - Advanced Users)**

⚠️ **Note**: MinGW setup is more complex than WSL. We strongly recommend using WSL2 (Option 1) for the best experience.

If you still want to use MinGW:
1. Download and install [MinGW-w64](https://www.mingw-w64.org/) with MSYS2
2. Install [CMake for Windows](https://cmake.org/download/)
3. Install ncurses through MSYS2: `pacman -S mingw-w64-x86_64-ncurses`
4. Add MinGW and CMake to your PATH environment variable
5. Use the MSYS2 terminal for building the project

**If you have issues with MinGW**, please use WSL2 instead - it provides a much smoother experience!

### VS Code Setup

1. **Install Visual Studio Code**: Download from [code.visualstudio.com](https://code.visualstudio.com/)

2. **Install GitHub Copilot Extension**:
   - Open VS Code
   - Press `Ctrl+Shift+X` (Windows/Linux) or `Cmd+Shift+X` (Mac)
   - Search for "GitHub Copilot"
   - Click Install
   - Sign in with your GitHub account when prompted

3. **Install C++ Extension (Optional but helpful)**:
   - Search for "C/C++" by Microsoft
   - Click Install

4. **Verify Copilot is Active**:
   - Look for the Copilot icon in the bottom status bar
   - It should show a checkmark when active
   - If you see a warning, click it to resolve any authentication issues

### Clone and Build the Chess Lab

```bash
# Clone the repository
git clone https://github.com/HarvirChima/chess-lab.git
cd chess-lab

# Build the project
mkdir build
cd build
cmake ..
make

# Run tests to verify everything works
./test_chess

# Try the game
./chess
```

**Expected output from tests:**
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

If you see all tests passing, you're ready to start the labs! 🎉

### Troubleshooting Common Issues

**Issue: "cmake: command not found"**
- **Solution**: CMake is not installed. Follow the installation instructions above for your OS.

**Issue: "ncurses.h: No such file or directory"**
- **Solution**: ncurses library is missing. 
  - macOS: `brew install ncurses`
  - Linux/WSL: `sudo apt-get install libncurses5-dev libncursesw5-dev`

**Issue: Copilot not providing suggestions**
- **Solution**: 
  1. Check the status bar icon - ensure Copilot is enabled
  2. Try reloading VS Code: Press `Ctrl+Shift+P` and type "Reload Window"
  3. Sign out and back in to GitHub in VS Code

---

## 📚 Lab 1: Using Ask Mode with the Chess Repository

**Estimated Time**: 15 minutes

**Objective**: Learn to use Copilot Chat to understand and explore the codebase.

### What is Ask Mode?

Ask Mode (Copilot Chat) lets you have a conversation with an AI that understands your code. You can ask questions about how things work, find bugs, get explanations, and more.

### How to Access Copilot Chat

1. **Open Chat Panel**: 
   - Press `Ctrl+Shift+I` (Windows/Linux) or `Cmd+Shift+I` (Mac)
   - Or click the chat icon in the left sidebar

2. **Chat with Context**:
   - Select code first, then open chat to ask about specific code
   - Use `@workspace` to ask about the entire repository

### Exercise 1.1: Explore the Codebase

Open Copilot Chat and ask these questions (copy and paste them):

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

**Bug Hunting:**

```
@workspace Are there any potential bugs or edge cases in the move validation?
```

```
@workspace Review the Board::isValidMove function for potential issues
```

### Exercise 1.2: Play the Game and Investigate

1. **Run the game**:
   ```bash
   cd build
   ./chess
   ```

2. **Try making some moves** using arrow keys and SPACE

3. **Ask Copilot about what you experienced**:
   - "How do I capture an enemy piece?"
   - "Why can't the knight move to certain squares?"
   - "What happens if I try to move into check?"

4. **Test missing features** (you'll notice some things don't work):
   - Try to castle (K + R move)
   - Try to promote a pawn
   - See if checkmate is detected

### Exercise 1.3: Understanding the Display

Open `src/Display.cpp` and select a function, then ask:

```
Explain what this function does and how ncurses is used here
```

Try this with:
- `drawBoard()`
- `highlightSquare()`
- `initialize()`

### ✅ Lab 1 Checkpoint

You should now be comfortable:
- ✅ Opening and using Copilot Chat
- ✅ Asking questions about code
- ✅ Understanding the chess game architecture
- ✅ Identifying missing features

---

## 📚 Lab 2: Generating Copilot Instructions

**Estimated Time**: 20 minutes

**Objective**: Learn to customize Copilot's behavior using instructions files.

### What are Copilot Instructions?

Copilot Instructions let you tell Copilot about your project's conventions, preferences, and patterns. This helps Copilot give better, more context-aware suggestions.

### Exercise 2.1: Auto-Generate Instructions

VS Code has a built-in feature to generate instructions based on your code!

1. **Open Command Palette**: `Ctrl+Shift+P` (Windows/Linux) or `Cmd+Shift+P` (Mac)

2. **Type and select**: `GitHub Copilot: Generate Instructions`

3. **Review the generated instructions** that appear in `.github/copilot-instructions.md`

4. **Look at what was auto-detected**:
   - Language and frameworks used
   - Code style patterns
   - Project structure

### Exercise 2.2: Add Custom Instructions

Now let's add some fun and practical custom instructions! Open `.github/copilot-instructions.md` and add:

```markdown
## Project-Specific Guidelines

### Code Style
- Use meaningful variable names (e.g., `currentPlayer` instead of `cp`)
- Add comments for complex chess logic
- Keep functions under 50 lines when possible
- Use const references for parameters that aren't modified

### Chess Domain
- This is a chess game application
- Always validate moves according to chess rules
- Consider check and checkmate scenarios
- Piece notation: K=King, Q=Queen, R=Rook, B=Bishop, N=Knight, P=Pawn

### Testing
- Write test cases for any new move validation logic
- Test both valid and invalid moves
- Include edge cases in tests

### Fun Personality Instructions 🎉
- When generating comments, occasionally include chess puns (e.g., "Check this out!", "Don't be a pawn, be a queen!")
- If suggesting a clever solution, you can say "That's a grandmaster move!"
- When catching potential bugs, say "That's a rookie mistake - let's castle away from that bug!"
- For optimization suggestions, say "Time to promote this code from pawn to queen!"

### Error Messages
- Make error messages friendly and educational
- Explain WHY a move is invalid (e.g., "Knights move in an L-shape" instead of just "Invalid move")

### Documentation
- When documenting chess logic, reference the actual chess rules
- Include examples in function comments
```

### Exercise 2.3: Test Your Instructions

1. **Open** `src/Board.cpp`

2. **Start typing a new function**:
```cpp
// Function to check if en passant is possible
bool Board::canEnPassant
```

3. **Let Copilot suggest the implementation** - notice how it follows your instructions!

4. **Try adding a comment**:
```cpp
// Function to move the knight
```
Watch for chess puns in the suggested code!

### Exercise 2.4: More Fun Instructions Ideas

Add these additional personality tweaks:

```markdown
### Code Generation Preferences
- When creating new classes, include a fun chess-themed comment at the top
- Suggest variable names inspired by famous chess players when appropriate (e.g., `carlsenScore`, `kasparovMode`)
- For particularly elegant code, add a comment like "// *chef's kiss* - this code is poetry"

### Learning Mode
- When implementing complex chess rules, include educational comments
- Add references to chess terminology
- Explain the "why" not just the "how"

### Emoji Usage (optional, for fun!)
- Use ♔♕♖♗♘♙ (unicode chess symbols) in comments occasionally
- Use 🏆 for victory/checkmate conditions
- Use ⚠️ for important validation checks
```

### ✅ Lab 2 Checkpoint

You should now understand:
- ✅ How to generate Copilot instructions automatically
- ✅ How to customize Copilot's behavior with instructions
- ✅ How to add personality and project-specific guidelines
- ✅ How instructions affect code suggestions

---

## 📚 Lab 3: Playing with Agent Mode

**Estimated Time**: 25 minutes

**Objective**: Use Copilot Agent Mode to fix bugs and add missing features autonomously.

### What is Agent Mode?

Agent Mode (also called Copilot Edits) allows Copilot to make changes across multiple files autonomously. Instead of just suggesting code, it can actually edit files, create new files, and refactor code based on your instructions.

### How to Access Agent Mode

1. **Open Copilot Edits**:
   - Press `Ctrl+Shift+I` to open Copilot Chat
   - Click the "Open Edits" button in the chat interface
   - Or press `Ctrl+K` then `I` (Windows/Linux) or `Cmd+K` then `I` (Mac)

2. **Add Files to Working Set**:
   - Drag files into the Edits panel, or
   - Click "Add files" and select relevant files

### Known Bugs and Missing Features

This chess game intentionally has some issues for you to fix! Here's what's broken:

#### Bug 1: Pawns Can Move Backwards! 🐛
The pawn validation logic has a bug that allows pawns to move backwards, which violates chess rules.

**Location**: `src/Board.cpp` - in the `isValidMove` function
**Impact**: Pawns can move in any direction, breaking the game

#### Bug 2: No Move Validation Message
When a player tries an invalid move, the game doesn't explain WHY it's invalid.

**Location**: `src/Game.cpp` - in the move handling logic
**Impact**: Players get confused when moves are rejected

#### Missing Feature 1: En Passant
The special pawn capture move "en passant" is not implemented.

**Impact**: Advanced chess players notice this is missing

#### Missing Feature 2: Move History
The game doesn't track or display move history.

**Impact**: Players can't review what moves were made

### Exercise 3.1: Fix Bug 1 - Pawn Movement

1. **Open Agent Mode** (`Ctrl+K I` or via Chat)

2. **Add relevant files**:
   - `src/Board.cpp`
   - `include/Board.h`
   - `src/test_chess.cpp`

3. **Give this prompt**:
```
Fix the bug that allows pawns to move backwards. Pawns should only move forward (white pawns toward row 0, black pawns toward row 7). Also add a test case to verify this fix works.
```

4. **Review the changes** Copilot suggests

5. **Accept or modify** the changes

6. **Build and test**:
```bash
cd build
make
./test_chess
```

### Exercise 3.2: Fix Bug 2 - Validation Messages

1. **In Agent Mode, add**:
   - `src/Game.cpp`
   - `include/Game.h`

2. **Give this prompt**:
```
When a player attempts an invalid move, display a helpful message explaining WHY the move is invalid. Consider different reasons: wrong turn, piece can't move that way, path blocked, or moving into check.
```

3. **Review and accept the changes**

4. **Test by running the game**:
```bash
./chess
```

Try making some invalid moves and check if you get helpful messages!

### Exercise 3.3: Add Missing Feature - Move History

1. **In Agent Mode, add**:
   - `src/Game.cpp`
   - `include/Game.h`
   - `src/Display.cpp`
   - `include/Display.h`

2. **Give this prompt**:
```
Add move history tracking to the chess game. Store each move with notation (e.g., "e2 to e4"). Display the last 5 moves on the right side of the board during gameplay. Use proper chess notation if possible.
```

3. **Review the changes**:
   - Check if a move history vector/list was added
   - Check if moves are recorded
   - Check if the display shows history

4. **Build and test**:
```bash
cd build
make
./chess
```

Play a few moves and see if they're tracked!

### Exercise 3.4: Explore Agent Mode Further

Try these additional prompts:

**Add a Feature**:
```
Add a resign option - when a player presses 'R', ask for confirmation, then end the game with a message about who resigned.
```

**Refactor Code**:
```
Extract the move validation logic for each piece type into separate functions to make the code more maintainable.
```

**Improve Error Handling**:
```
Add try-catch blocks around user input processing to handle unexpected inputs gracefully.
```

### Agent Mode Tips 💡

- **Be specific**: The more detailed your prompt, the better the results
- **Add relevant files**: Include all files that need to be changed
- **Review before accepting**: Always check what Agent Mode suggests
- **Iterate**: If the first attempt isn't perfect, refine your prompt
- **Test frequently**: Build and test after each change

### ✅ Lab 3 Checkpoint

You should now be able to:
- ✅ Open and use Agent Mode (Copilot Edits)
- ✅ Fix bugs across multiple files
- ✅ Add new features with Copilot's help
- ✅ Review and test AI-generated changes
- ✅ Iterate on prompts for better results

---

## 📚 Lab 4: Working with Prompt Files

**Estimated Time**: 20 minutes

**Objective**: Create reusable prompt files for consistent testing workflows.

### What are Prompt Files?

Prompt Files (`.prompt.md` files) are reusable prompts that you can invoke with a simple command. They're perfect for repetitive tasks like testing, code review, or documentation generation.

### Exercise 4.1: Create a Testing Prompt File

1. **Create the .github directory** (if it doesn't exist):
```bash
mkdir -p .github
```

2. **Create a new file**: `.github/chess-test.prompt.md`

3. **Add this content**:

```markdown
---
name: Chess Test Generator
description: Generates comprehensive test cases for chess game functionality
---

# Chess Test Generator

You are a test generation expert for chess game applications. Generate comprehensive test cases following these guidelines:

## Test Structure
- Use the existing test framework in `src/test_chess.cpp`
- Follow the naming convention: `test[FeatureName]`
- Include both positive and negative test cases
- Test edge cases and boundary conditions

## Chess-Specific Testing
- Test all piece movement rules
- Test capture mechanics
- Test turn-based logic
- Test invalid move rejection
- Test special moves (castling, en passant, promotion)
- Test check and checkmate detection

## Test Format
Each test should:
1. Set up the board state
2. Perform the action
3. Assert the expected outcome
4. Clean up if necessary

## Output Format
Generate complete, compilable test functions that can be added to test_chess.cpp.

---

Based on the current codebase, generate test cases for: {{FEATURE_NAME}}

Include:
- At least 3 test scenarios
- Both valid and invalid cases
- Edge cases
- Clear, descriptive test names
- Comments explaining what each test verifies
```

### Exercise 4.2: Use Your Prompt File

1. **Open Copilot Chat** (`Ctrl+Shift+I`)

2. **Invoke your prompt file**:
   - Type `/` to see available commands
   - Type `#file:.github/chess-test.prompt.md`
   - Or reference it in your prompt

3. **Use it to generate tests**:
```
#file:.github/chess-test.prompt.md

Generate tests for bishop diagonal movement
```

4. **Review the generated tests**

5. **Add them to** `src/test_chess.cpp`

6. **Build and run**:
```bash
cd build
make
./test_chess
```

### Exercise 4.3: Create More Prompt Files

Create additional prompt files for different purposes:

#### Code Review Prompt: `.github/chess-code-review.prompt.md`

```markdown
---
name: Chess Code Reviewer
description: Performs thorough code review with chess domain expertise
---

# Chess Code Review Expert

You are an expert code reviewer specializing in game development and chess applications.

## Review Checklist
- [ ] Code follows chess rules correctly
- [ ] Move validation is complete and accurate
- [ ] Edge cases are handled
- [ ] Code is readable and well-commented
- [ ] Performance is acceptable for a chess game
- [ ] Memory management is safe (no leaks)
- [ ] Error handling is comprehensive

## Chess Domain Checks
- [ ] Piece movement follows official chess rules
- [ ] Special moves (castling, en passant, promotion) are correctly implemented or noted as missing
- [ ] Check and checkmate logic is sound
- [ ] Turn-based logic prevents illegal moves

## Code Quality Checks
- [ ] Functions are focused and single-purpose
- [ ] Variable names are clear and meaningful
- [ ] Magic numbers are avoided or explained
- [ ] Comments explain "why" not just "what"

---

Review this code for correctness and suggest improvements:

{{CODE_TO_REVIEW}}
```

#### Documentation Prompt: `.github/chess-doc.prompt.md`

```markdown
---
name: Chess Documentation Generator
description: Generates clear, educational documentation for chess code
---

# Chess Documentation Generator

Generate clear, beginner-friendly documentation for chess game code.

## Documentation Style
- Explain chess concepts for non-chess players
- Include examples of how to use functions
- Document parameters and return values
- Mention chess rules where relevant
- Add "why this matters" context

## Format
Use Doxygen-style comments:
```cpp
/**
 * @brief Brief description
 * @param paramName Description with chess context
 * @return What it returns and why
 * @note Any special chess rules or edge cases
 */
```

---

Generate documentation for: {{FUNCTION_OR_CLASS}}
```

### Exercise 4.4: Test Your Prompt Files

Use each prompt file you created:

1. **Testing Prompt**:
```
#file:.github/chess-test.prompt.md
Generate tests for rook movement along ranks and files
```

2. **Code Review Prompt**:
```
#file:.github/chess-code-review.prompt.md
Review the Board::isValidMove function in src/Board.cpp
```

3. **Documentation Prompt**:
```
#file:.github/chess-doc.prompt.md
Document the Board class in include/Board.h
```

### Exercise 4.5: Create a Specialized Prompt

Create your own prompt file for a specific task. Ideas:

- **Bug Hunter**: `.github/find-bugs.prompt.md` - Finds potential bugs
- **Optimizer**: `.github/optimize.prompt.md` - Suggests performance improvements  
- **Feature Planner**: `.github/feature-design.prompt.md` - Plans new features
- **Refactoring**: `.github/refactor.prompt.md` - Suggests code refactoring

### ✅ Lab 4 Checkpoint

You should now be able to:
- ✅ Create reusable prompt files
- ✅ Invoke prompt files in Copilot Chat
- ✅ Generate consistent test cases
- ✅ Create domain-specific prompts
- ✅ Build a library of helpful prompts for your project

---

## 📚 Lab 5: Implementing a Custom Chat Mode

**Estimated Time**: 25 minutes

**Objective**: Create a custom chat participant that acts as a chess expert assistant.

### What are Custom Chat Modes?

Custom Chat Modes (also called Chat Participants) are specialized AI assistants you can create for specific domains or tasks. They have their own personality, expertise, and context.

### Exercise 5.1: Create Chess Expert Chat Participant

1. **Create the extension directory**:
```bash
mkdir -p .github/chess-expert
cd .github/chess-expert
```

2. **Create** `package.json`:

```json
{
  "name": "chess-expert-chat",
  "displayName": "Chess Expert Chat Participant",
  "description": "A chess expert that helps with chess programming and rules",
  "version": "0.1.0",
  "engines": {
    "vscode": "^1.85.0"
  },
  "categories": ["Chat Participants"],
  "contributes": {
    "chatParticipants": [
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

3. **Create** `extension.js`:

```javascript
const vscode = require('vscode');

function activate(context) {
    // Register the chess expert chat participant
    const chessExpert = vscode.chat.createChatParticipant(
        'chess.expert',
        async (request, context, stream, token) => {
            // System prompt for the chess expert
            const systemPrompt = `You are a Chess Grandmaster and expert programmer specializing in chess game development.

Your expertise includes:
- Official FIDE chess rules and regulations
- Chess strategy and tactics
- Chess notation (algebraic, descriptive, PGN)
- Chess programming algorithms (minimax, alpha-beta pruning)
- Move validation and game state management
- Chess engine design

When helping with code:
- Explain chess rules clearly
- Validate logic against official chess rules
- Suggest edge cases specific to chess
- Reference famous games or positions when relevant
- Use proper chess terminology

When discussing moves:
- Use algebraic notation (e.g., e4, Nf3, O-O)
- Explain why moves are legal or illegal
- Consider tactical implications

Your personality:
- Enthusiastic about chess
- Patient and educational
- Uses chess metaphors
- Occasionally references famous games/players
- Encouraging to learners`;

            // Get the user's message
            const userMessage = request.prompt;
            
            // Stream the response
            stream.markdown("♔ **Chess Expert**: ");
            
            // Check if asking about chess rules
            if (userMessage.toLowerCase().includes('rule') || 
                userMessage.toLowerCase().includes('legal') ||
                userMessage.toLowerCase().includes('allowed')) {
                
                stream.markdown("\n\nLet me explain the chess rules relevant to your question...\n\n");
            }
            
            // Check if asking about code
            if (userMessage.toLowerCase().includes('code') || 
                userMessage.toLowerCase().includes('function') ||
                userMessage.toLowerCase().includes('implement')) {
                
                stream.markdown("\n\nFrom a chess programming perspective:\n\n");
            }

            // Use language model with chess expertise
            const messages = [
                vscode.LanguageModelChatMessage.User(systemPrompt),
                vscode.LanguageModelChatMessage.User(userMessage)
            ];

            const chatResponse = await request.model.sendRequest(
                messages,
                {},
                token
            );

            for await (const fragment of chatResponse.text) {
                stream.markdown(fragment);
            }

            return;
        }
    );

    context.subscriptions.push(chessExpert);
}

function deactivate() {}

module.exports = { activate, deactivate };
```

4. **Create** `README.md` in the chess-expert directory:

```markdown
# Chess Expert Chat Participant

A custom Copilot chat participant that acts as a chess grandmaster and programming expert.

## How to Use

1. Install this extension in your VS Code
2. Open Copilot Chat
3. Type `@chessexpert` to talk to the chess expert
4. Ask about chess rules, strategies, or code implementation

## Example Queries

- `@chessexpert Can a pawn move backwards?`
- `@chessexpert How should I implement castling validation?`
- `@chessexpert Explain the en passant rule`
- `@chessexpert Review my move validation function`
- `@chessexpert What's the best way to detect checkmate?`

## Features

- Explains chess rules clearly
- Validates code against official chess rules
- Suggests edge cases for testing
- Uses proper chess notation
- Educational and encouraging
```

### Exercise 5.2: Alternative - Use Participant Files (Simpler)

If creating a full extension is complex, VS Code supports a simpler approach with participant files:

1. **Create** `.github/copilot-chat-participants.json`:

```json
{
  "participants": [
    {
      "id": "chessexpert",
      "name": "Chess Expert",
      "description": "Chess grandmaster and programming expert",
      "systemMessage": "You are a Chess Grandmaster and expert programmer. Explain chess rules clearly, validate code against official chess rules, use algebraic notation, and be encouraging to learners. Include chess metaphors and occasionally reference famous games."
    }
  ]
}
```

### Exercise 5.3: Test Your Chess Expert

Open Copilot Chat and try these prompts:

**Chess Rules Questions**:
```
@chessexpert Can a knight jump over other pieces?
```

```
@chessexpert What are the conditions required for castling?
```

```
@chessexpert Explain how en passant works
```

**Code Review**:
```
@chessexpert Review the pawn movement logic in Board.cpp
```

```
@chessexpert What edge cases should I test for bishop movement?
```

**Implementation Help**:
```
@chessexpert How should I implement checkmate detection?
```

```
@chessexpert What data structure is best for tracking move history?
```

**Strategy Discussion**:
```
@chessexpert What's a good opening move for beginners?
```

### Exercise 5.4: Enhance Your Chess Expert

Add more capabilities to your chess expert:

**Add Opening Book Knowledge**:
```javascript
// In extension.js, add after systemPrompt:
const openingsDatabase = {
    'e4': 'The King\'s Pawn Opening - most popular and aggressive',
    'd4': 'The Queen\'s Pawn Opening - solid and positional',
    'Nf3': 'The Réti Opening - flexible and transpositional',
    'c4': 'The English Opening - hypermodern approach'
};
```

**Add Famous Games References**:
```javascript
const famousGames = {
    'immortal': 'Anderssen vs Kieseritzky (1851) - The Immortal Game',
    'evergreen': 'Anderssen vs Dufresne (1852) - The Evergreen Game',
    'opera': 'Morphy vs Duke of Brunswick (1858) - The Opera Game'
};
```

**Add Tactical Pattern Recognition**:
```javascript
const tacticalPatterns = {
    'fork': 'One piece attacks two or more enemy pieces',
    'pin': 'A piece cannot move without exposing a more valuable piece',
    'skewer': 'Like a pin but the more valuable piece is in front',
    'discovery': 'Moving one piece reveals an attack by another'
};
```

### Exercise 5.5: Create Additional Custom Participants

Create more specialized participants:

**Testing Expert**:
```json
{
  "id": "testexpert",
  "name": "Test Expert",
  "description": "Expert in writing comprehensive test cases",
  "systemMessage": "You are a testing expert. Generate thorough test cases covering edge cases, boundary conditions, and error scenarios. Follow TDD principles."
}
```

**Performance Expert**:
```json
{
  "id": "perfexpert", 
  "name": "Performance Expert",
  "description": "Expert in code optimization and performance",
  "systemMessage": "You are a performance optimization expert. Analyze code for bottlenecks, suggest algorithmic improvements, and recommend profiling strategies."
}
```

### ✅ Lab 5 Checkpoint

You should now be able to:
- ✅ Create custom chat participants
- ✅ Define specialized system prompts
- ✅ Use custom participants in Copilot Chat
- ✅ Build domain-specific AI assistants
- ✅ Enhance participants with knowledge bases

---

## 📚 Lab 6: Advanced Topics & Best Practices

**Estimated Time**: 30 minutes

**Objective**: Learn advanced Copilot techniques and best practices for professional development.

### Exercise 6.1: Workspace Context Optimization

Help Copilot understand your workspace better.

**Create** `.github/copilot-workspace.md`:

```markdown
# Chess Lab Workspace Context

## Project Overview
A terminal-based chess game implementation in C++ using ncurses for display.

## Architecture
- **Board**: Manages 8x8 game board and piece positions
- **Game**: Controls game flow, user input, and turn management  
- **Display**: Handles ncurses rendering and visual output
- **Piece**: Represents chess pieces with type and color

## Key Files
- `src/Board.cpp`: Core move validation and game rules
- `src/Game.cpp`: Game loop and user interaction
- `src/Display.cpp`: Terminal UI rendering
- `include/*.h`: Class declarations

## Build System
- Uses CMake 3.10+
- Requires ncurses library
- C++17 standard
- Builds three executables: chess, test_chess, demo_board

## Testing Strategy
- Unit tests in test_chess.cpp
- Tests cover: piece creation, board init, movement, validation, captures
- Run with: `./build/test_chess`

## Common Tasks
- Add new piece movement: Modify `Board::isValidMove()`
- Add visual features: Modify `Display.cpp`
- Add tests: Add to `test_chess.cpp`
- Change game flow: Modify `Game.cpp`

## Chess Rules Implemented
- [x] Basic piece movement
- [x] Capture mechanics
- [x] Turn-based play
- [x] Move validation
- [ ] Castling (TODO)
- [ ] En passant (TODO)
- [ ] Pawn promotion (TODO)
- [ ] Check detection (partial)
- [ ] Checkmate detection (TODO)

## Code Conventions
- Use const references for read-only parameters
- Validate positions before array access
- Clear error messages for invalid moves
- Comment complex chess logic
- Keep functions focused and under 50 lines
```

### Exercise 6.2: Advanced Prompt Engineering

Learn to write better prompts for complex tasks.

**Good Prompt Structure**:
```
[Context] + [Task] + [Constraints] + [Output Format]
```

**Example - Poor Prompt**:
```
Add checkmate detection
```

**Example - Good Prompt**:
```
Context: This is a chess game with basic move validation. 
Task: Implement checkmate detection that checks if the current player has no legal moves and their king is in check.
Constraints: 
- Must check all pieces for possible moves
- Must verify king is currently in check
- Should handle stalemate separately (no legal moves but not in check)
- Add appropriate tests
Output Format: Modify Board.cpp and Board.h, add test cases to test_chess.cpp
```

**Practice with these prompts**:

1. **Feature Addition**:
```
Context: The chess game currently doesn't support pawn promotion.
Task: Implement pawn promotion to allow a pawn reaching the opposite end to become a Queen, Rook, Bishop, or Knight.
Constraints:
- Prompt user to choose piece type when promotion occurs
- Default to Queen if user doesn't respond
- Update both Board and Game classes
- Validate promoted piece type
- Add tests for promotion scenarios
Output Format: Changes to Board.cpp, Board.h, Game.cpp, Game.h, and test_chess.cpp
```

2. **Bug Fix**:
```
Context: Users report that the game occasionally crashes when moving pieces near board edges.
Task: Find and fix any array out-of-bounds issues in move validation.
Constraints:
- Check all array accesses in Board.cpp
- Add bounds checking where missing
- Don't change working logic
- Add edge case tests
Output Format: Minimal changes to Board.cpp with clear comments explaining fixes
```

3. **Refactoring**:
```
Context: The Board::isValidMove function is over 200 lines and hard to maintain.
Task: Refactor move validation into separate functions per piece type.
Constraints:
- Create functions: isValidPawnMove, isValidKnightMove, etc.
- Maintain exact same behavior (no logic changes)
- Keep all existing tests passing
- Add documentation for each new function
Output Format: Refactored Board.cpp and Board.h with new private methods
```

### Exercise 6.3: Code Review with Copilot

Use Copilot for systematic code reviews.

**Create a Review Checklist** `.github/review-checklist.md`:

```markdown
# Code Review Checklist for Chess Lab

## Functionality
- [ ] Code follows official chess rules correctly
- [ ] All edge cases are handled
- [ ] Invalid inputs are rejected gracefully
- [ ] Special moves (if implemented) follow FIDE rules

## Code Quality
- [ ] Functions are single-purpose and focused
- [ ] Variable names are clear and meaningful
- [ ] No magic numbers (or they're explained)
- [ ] Complex logic has explanatory comments
- [ ] Code is readable without comments (comments explain "why")

## Performance
- [ ] No unnecessary loops or operations
- [ ] Memory is managed properly (no leaks)
- [ ] Array bounds are always checked
- [ ] Efficient algorithms for move validation

## Testing
- [ ] New features have corresponding tests
- [ ] Tests cover both valid and invalid cases
- [ ] Edge cases are tested
- [ ] All tests pass

## Safety
- [ ] No potential null pointer dereferences
- [ ] Array indices are validated before use
- [ ] Integer overflow is considered
- [ ] Error conditions are handled

## Maintainability
- [ ] Code follows existing patterns
- [ ] Changes are minimal and focused
- [ ] Public API changes are documented
- [ ] Breaking changes are avoided

## Ask Copilot to Review
Tag: @workspace using this checklist, review [file/function name]
```

**Practice Review**:
```
@workspace Using the checklist in .github/review-checklist.md, review the Board::isValidMove function in src/Board.cpp. Identify any issues and suggest improvements.
```

### Exercise 6.4: Test-Driven Development with Copilot

Learn to use Copilot in a TDD workflow.

**TDD Workflow**:
1. Write a failing test
2. Ask Copilot to implement the feature
3. Verify test passes
4. Refactor if needed

**Example - Adding Move Notation**:

1. **First, write the test**:
```cpp
void testMoveNotation() {
    Board board;
    board.initialize();
    
    // Test pawn move notation
    std::string notation = board.getMoveNotation(6, 4, 4, 4);
    assert(notation == "e4");
    
    // Test knight move notation  
    notation = board.getMoveNotation(7, 1, 5, 2);
    assert(notation == "Nc3");
    
    // Test capture notation
    // ... more test cases
}
```

2. **Then prompt Copilot**:
```
The test testMoveNotation expects a function getMoveNotation that converts chess moves to algebraic notation (e.g., "e4", "Nf3", "Bxc4"). Implement this function in Board class following standard chess notation rules.
```

3. **Run tests and iterate**.

**Try it yourself - Add a feature with TDD**:

Pick one:
- Save game to PGN format
- Implement time controls
- Add move suggestions for beginners
- Implement position evaluation scoring

### Exercise 6.5: Documentation Generation

Use Copilot to generate comprehensive documentation.

**Prompt for API Documentation**:
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

**Prompt for User Guide**:
```
Generate a user guide section explaining how to use the chess game programmatically (not as a player, but as a developer integrating it). Include:
- How to initialize a game
- How to make moves programmatically
- How to query game state
- How to implement custom displays
- Code examples for each
```

### Exercise 6.6: Performance Optimization

Ask Copilot to optimize performance.

**Optimization Prompt**:
```
@workspace Analyze the Board::isValidMove function for performance bottlenecks. Consider:
- How many times it's called per move
- Redundant checks that could be cached
- Expensive operations that could be optimized
- Early exit opportunities
Suggest specific optimizations with code examples.
```

**Profiling with Copilot**:
```
Add simple performance profiling to the chess game to measure:
- Time spent in move validation
- Time spent in display rendering
- Time spent in user input processing
Use std::chrono and output results at game end.
```

### Exercise 6.7: Security Review

Use Copilot for security analysis.

**Security Review Prompt**:
```
@workspace Perform a security review of this chess game focusing on:
- Buffer overflow risks in array operations
- Integer overflow in calculations  
- Input validation vulnerabilities
- Memory safety issues
- Denial of service possibilities (infinite loops, etc.)
Report any issues and suggest fixes.
```

### ✅ Lab 6 Checkpoint

You should now master:
- ✅ Advanced prompt engineering techniques
- ✅ Using Copilot for code reviews
- ✅ Test-driven development with Copilot
- ✅ Documentation generation
- ✅ Performance optimization strategies
- ✅ Security review practices

---

## 🎓 Lab Complete! What's Next?

Congratulations! You've completed all 6 labs and learned:

- ✅ **Lab 1**: Ask Mode for code exploration
- ✅ **Lab 2**: Copilot Instructions customization
- ✅ **Lab 3**: Agent Mode for autonomous changes
- ✅ **Lab 4**: Reusable Prompt Files
- ✅ **Lab 5**: Custom Chat Participants
- ✅ **Lab 6**: Advanced techniques and best practices

### Continue Your Learning

**Project Ideas**:
1. Implement all missing chess features (castling, en passant, promotion)
2. Add checkmate and stalemate detection
3. Create an AI opponent (start with random moves, then improve)
4. Implement PGN file import/export
5. Add a graphical interface (SDL or Qt)
6. Create a web version with Emscripten
7. Implement chess puzzles mode
8. Add multiplayer over network

**Advanced Copilot Techniques**:
- Use Copilot for architecture design discussions
- Generate entire features from high-level descriptions
- Create domain-specific language models
- Build automated code quality pipelines

**Resources**:
- [Copilot Documentation](https://docs.github.com/en/copilot)
- [Copilot Best Practices](https://github.blog/category/copilot/)
- [Chess Programming Wiki](https://www.chessprogramming.org/)
- [FIDE Chess Rules](https://handbook.fide.com/chapter/E012023)

### Share Your Experience

- ⭐ Star this repository
- 🐛 Report issues or suggest improvements
- 📝 Share what you built on social media
- 🤝 Contribute back to the project

---

## 🎯 Quick Reference Card

### Essential Copilot Shortcuts

| Action | Shortcut (Windows/Linux) | Shortcut (Mac) |
|--------|-------------------------|----------------|
| Open Chat | `Ctrl+Shift+I` | `Cmd+Shift+I` |
| Open Edits | `Ctrl+K I` | `Cmd+K I` |
| Accept Suggestion | `Tab` | `Tab` |
| Reject Suggestion | `Esc` | `Esc` |
| Next Suggestion | `Alt+]` | `Option+]` |
| Previous Suggestion | `Alt+[` | `Option+[` |

### Copilot Chat Commands

- `@workspace` - Query entire workspace
- `#file:path` - Reference specific file or prompt file
- `@chessexpert` - Talk to your custom participant
- `/explain` - Explain code
- `/fix` - Suggest fixes
- `/tests` - Generate tests
- `/doc` - Generate documentation

### Quick Prompts

**Understanding**:
- "Explain this function"
- "What does this code do?"
- "Find potential bugs"

**Implementation**:
- "Implement [feature]"
- "Add tests for [functionality]"
- "Refactor this to be more maintainable"

**Review**:
- "Review for security issues"
- "Check for performance problems"
- "Suggest improvements"

---

**Happy Coding with Copilot! ♟️🤖**
