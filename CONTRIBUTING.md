# Contributing to Chess Lab 🎮♟️

Thank you for your interest in contributing to Chess Lab! This project welcomes contributions from developers of all skill levels.

## 🎯 Project Goals

Chess Lab is designed to:
- Help beginners learn C++ programming
- Demonstrate GitHub Copilot's capabilities
- Provide a hands-on learning experience
- Maintain clean, readable, well-documented code

## 🚀 Getting Started

### Prerequisites

Before contributing, make sure you can build and run the project:

```bash
# Clone the repository
git clone https://github.com/HarvirChima/chess-lab.git
cd chess-lab

# Build the project
mkdir build && cd build
cmake ..
make

# Run tests
./test_chess
```

If you encounter issues, check the [README.md](README.md) troubleshooting section.

## 🔧 Development Setup

### Recommended Tools

- **IDE**: VS Code with C++ extensions (and GitHub Copilot if available)
- **Compiler**: GCC 7+ or Clang 5+
- **Build System**: CMake 3.10+
- **Version Control**: Git

### Code Style

- Use consistent indentation (4 spaces)
- Follow existing naming conventions:
  - Classes: `PascalCase` (e.g., `ChessBoard`)
  - Functions: `camelCase` (e.g., `isValidMove`)
  - Variables: `camelCase` (e.g., `currentPlayer`)
  - Constants: `UPPER_SNAKE_CASE` (e.g., `BOARD_SIZE`)
- Add comments for complex logic
- Keep functions focused and small
- Use meaningful variable names

### Project Structure

```
chess-lab/
├── include/          # Header files (.h)
│   ├── Board.h      # Board class declaration
│   ├── Piece.h      # Piece class declaration
│   ├── Game.h       # Game class declaration
│   └── Display.h    # Display class declaration
│
├── src/             # Implementation files (.cpp)
│   ├── main.cpp     # Entry point
│   ├── Board.cpp    # Board implementation
│   ├── Piece.cpp    # Piece implementation
│   ├── Game.cpp     # Game implementation
│   ├── Display.cpp  # Display implementation
│   ├── test_chess.cpp    # Unit tests
│   └── demo_board.cpp    # Demo viewer
│
└── CMakeLists.txt   # Build configuration
```

## 🐛 Reporting Bugs

### Before Reporting

1. Check if the issue already exists in [GitHub Issues](https://github.com/HarvirChima/chess-lab/issues)
2. Verify it's reproducible in the latest version
3. Test with a clean build (`rm -rf build && mkdir build && cd build && cmake .. && make`)

### Creating a Bug Report

Include:
- **Description**: Clear description of the bug
- **Steps to Reproduce**: Step-by-step instructions
- **Expected Behavior**: What should happen
- **Actual Behavior**: What actually happens
- **Environment**: OS, compiler version, CMake version
- **Error Messages**: Copy full error messages or stack traces

Example:
```markdown
**Bug**: Game crashes when selecting empty square

**Steps to Reproduce**:
1. Start the game: `./chess`
2. Move cursor to an empty square (e.g., e4)
3. Press SPACE

**Expected**: Nothing should happen or show a message
**Actual**: Program crashes with segmentation fault

**Environment**: Ubuntu 22.04, GCC 11.3.0, CMake 3.22.1
```

## 💡 Suggesting Features

We welcome feature suggestions! Good features for this project include:

**Beginner-Friendly Features:**
- Improved UI/UX
- Better error messages
- More helpful documentation
- Additional test cases

**Intermediate Features:**
- Move history display
- Undo/redo functionality
- Save/load game state
- Move notation (algebraic notation)
- Timer for timed games

**Advanced Features:**
- Check detection
- Checkmate detection
- Stalemate detection
- Castling support
- En passant captures
- Pawn promotion
- AI opponent

### Feature Request Template

```markdown
**Feature**: [Brief title]

**Description**: [Detailed description of the feature]

**Use Case**: [Why is this useful for learners?]

**Complexity**: [Beginner/Intermediate/Advanced]

**Implementation Ideas**: [Optional: How might this be implemented?]
```

## 🔨 Making Changes

### Workflow

1. **Fork** the repository
2. **Clone** your fork:
   ```bash
   git clone https://github.com/YOUR_USERNAME/chess-lab.git
   ```
3. **Create a branch** for your changes:
   ```bash
   git checkout -b feature/your-feature-name
   ```
4. **Make your changes**
5. **Test thoroughly**:
   ```bash
   cd build
   make
   ./test_chess
   ./chess  # Manual testing
   ```
6. **Commit** with clear messages:
   ```bash
   git commit -m "Add check detection feature"
   ```
7. **Push** to your fork:
   ```bash
   git push origin feature/your-feature-name
   ```
8. **Create a Pull Request**

### Commit Messages

Use clear, descriptive commit messages:

**Good:**
- ✅ "Add function to detect if king is in check"
- ✅ "Fix segfault when selecting empty square"
- ✅ "Improve error message for invalid moves"
- ✅ "Add unit tests for rook movement"

**Avoid:**
- ❌ "Fix bug"
- ❌ "Update code"
- ❌ "Changes"

### Pull Request Guidelines

**Before submitting:**
- [ ] Code builds without errors
- [ ] All tests pass
- [ ] New features include tests
- [ ] Code follows project style
- [ ] Documentation updated if needed
- [ ] Commit messages are clear

**Pull Request Template:**
```markdown
## Description
[Clear description of what this PR does]

## Type of Change
- [ ] Bug fix
- [ ] New feature
- [ ] Documentation update
- [ ] Code refactoring
- [ ] Test addition

## Testing
[Describe how you tested the changes]

## Checklist
- [ ] Code builds successfully
- [ ] All tests pass
- [ ] New tests added (if applicable)
- [ ] Documentation updated (if applicable)
- [ ] Follows code style guidelines
```

## ✅ Testing

### Running Tests

```bash
cd build
./test_chess
```

### Adding Tests

Add new tests to `src/test_chess.cpp`:

```cpp
void testYourNewFeature() {
    // Setup
    Board board;
    
    // Test your feature
    bool result = board.yourNewFunction();
    
    // Verify
    if (result) {
        std::cout << "✓ Your new feature test passed" << std::endl;
    } else {
        std::cout << "✗ Your new feature test failed" << std::endl;
        exit(1);
    }
}

int main() {
    // ... existing tests ...
    
    testYourNewFeature();  // Add your test
    
    // ... rest of main ...
}
```

### Manual Testing

Always test manually:
1. Build and run the game
2. Test your new feature interactively
3. Try edge cases
4. Verify error handling

## 📝 Documentation

### Code Comments

Add comments for:
- Complex algorithms
- Non-obvious logic
- Function purposes (if not clear from name)
- Important assumptions or limitations

Example:
```cpp
/**
 * Checks if a move puts the player's own king in check
 * This prevents illegal moves that would expose the king
 * 
 * @param from Starting position
 * @param to Destination position
 * @return true if move is safe, false if it exposes the king
 */
bool Board::isSafeMove(Position from, Position to) {
    // Implementation
}
```

### Documentation Updates

When adding features, update:
- `README.md` - If user-facing feature
- `GET_STARTED.md` - If changes setup or quick start process
- Code comments - Always
- Test documentation - For test additions

## 🤖 Using GitHub Copilot

If you have GitHub Copilot, here are tips for contributing:

### Good Practices

1. **Write clear comments first**:
   ```cpp
   // Function to check if castling is legal for the given color
   bool Board::canCastle(Color color, CastleType type) {
   ```

2. **Review suggestions carefully** - Don't blindly accept
3. **Test all generated code** - AI can make mistakes
4. **Keep the learning focus** - Code should be readable for beginners

### Example Workflow

```cpp
// 1. Start with a comment describing what you want
// Add function to detect checkmate

// 2. Let Copilot suggest the signature
bool Board::isCheckmate(Color color) {
    
// 3. Add implementation comments
    // First check if king is in check
    
    // Then check if any move can escape check
    
    // Return true only if no legal moves exist
}

// 4. Review, test, and refine the generated code
```

## 🎓 Learning Resources

Contributing is a great way to learn! Here are resources to help:

**C++:**
- [LearnCpp.com](https://www.learncpp.com/)
- [C++ Reference](https://en.cppreference.com/)

**Chess Programming:**
- [Chess Programming Wiki](https://www.chessprogramming.org/)

**Git & GitHub:**
- [GitHub Docs](https://docs.github.com/)
- [Git Handbook](https://guides.github.com/introduction/git-handbook/)

**CMake:**
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

## 🏆 Recognition

Contributors are acknowledged in:
- GitHub contributor list
- Pull request comments
- Release notes (for significant contributions)

## ❓ Questions?

- **General questions**: Open a [GitHub Discussion](https://github.com/HarvirChima/chess-lab/discussions)
- **Bug reports**: Open a [GitHub Issue](https://github.com/HarvirChima/chess-lab/issues)
- **Feature requests**: Open a [GitHub Issue](https://github.com/HarvirChima/chess-lab/issues) with `[Feature Request]` label

## 📜 Code of Conduct

- Be respectful and constructive
- Welcome newcomers and help them learn
- Focus on the code, not the person
- Remember: everyone is here to learn!

## 📄 License

By contributing, you agree that your contributions will be licensed under the same license as the project.

---

**Thank you for contributing to Chess Lab!** 🎉

Every contribution, no matter how small, helps make this a better learning resource for everyone.

**Happy coding!** 🎮♟️
