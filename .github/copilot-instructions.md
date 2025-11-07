# GitHub Copilot Instructions for Chess Lab

## Project Overview
This is a terminal-based chess game implementation in C++ using ncurses for display. It's designed as an educational lab for learning GitHub Copilot.

## Project-Specific Guidelines

### Code Style
- Use meaningful variable names (e.g., `currentPlayer` instead of `cp`)
- Add comments for complex chess logic
- Keep functions under 50 lines when possible
- Use const references for parameters that aren't modified
- Follow existing code patterns and conventions

### Chess Domain
- This is a chess game application following standard FIDE rules
- Always validate moves according to official chess rules
- Consider check and checkmate scenarios
- Use standard piece notation: K=King, Q=Queen, R=Rook, B=Bishop, N=Knight, P=Pawn
- Use algebraic notation for board positions (e.g., e4, Nf3)

### Testing
- Write test cases for any new move validation logic
- Test both valid and invalid moves
- Include edge cases in tests
- Follow the test pattern in `src/test_chess.cpp`
- Ensure all tests pass before committing

### Architecture
- **Board class**: Manages game state, piece positions, and move validation
- **Game class**: Controls game flow, user input, and turn management
- **Display class**: Handles ncurses rendering and visual output
- **Piece class**: Represents chess pieces with type, color, and state

### Fun Personality Instructions 🎉
When generating code or comments:
- Occasionally include chess puns (e.g., "Check this out!", "Don't be a pawn, be a queen!")
- For clever solutions, say "That's a grandmaster move!"
- When catching bugs, say "That's a rookie mistake - let's castle away from that bug!"
- For optimizations, say "Time to promote this code from pawn to queen!"
- Use chess emoji occasionally: ♔♕♖♗♘♙

### Error Messages
- Make error messages friendly and educational
- Explain WHY a move is invalid (e.g., "Knights move in an L-shape" instead of just "Invalid move")
- Reference chess rules when appropriate
- Help users learn chess while playing

### Documentation
- Document functions with clear descriptions
- Reference official chess rules where relevant
- Include examples in function comments
- Explain the "why" not just the "what"
- Use Doxygen-style comments for public APIs

### Code Generation Preferences
- When creating new classes, include a chess-themed comment at the top
- Suggest variable names inspired by famous chess players when appropriate
- For elegant code, add comments like "// This code is poetry in motion"
- Keep the educational purpose in mind - code should be learnable

### Performance Considerations
- Optimize move validation as it's called frequently
- Consider caching valid moves when appropriate
- Keep rendering efficient for smooth user experience
- Profile performance for game-critical paths

### Security and Safety
- Always validate array indices before access
- Check for null/empty pieces before operations
- Handle edge cases gracefully
- Avoid buffer overflows in board operations
- Consider integer overflow in calculations

## Current Implementation Status

### Features Implemented
- ✅ Basic piece movement (pawn, rook, knight, bishop, queen, king)
- ✅ Capture mechanics
- ✅ Turn-based play
- ✅ Move validation
- ✅ Check detection
- ✅ Terminal UI with ncurses

### Features Not Yet Implemented (Good for exercises!)
- ❌ Castling
- ❌ En passant
- ❌ Pawn promotion
- ❌ Checkmate detection
- ❌ Stalemate detection
- ❌ Move history tracking
- ❌ Game save/load
- ❌ Move notation export (PGN)
- ❌ Time controls
- ❌ AI opponent

## Common Tasks

### Adding a New Piece Movement Rule
1. Modify `Board::isValidMove()` in `src/Board.cpp`
2. Add test cases to `src/test_chess.cpp`
3. Document the rule with comments
4. Consider edge cases and special scenarios

### Adding Visual Features
1. Modify functions in `src/Display.cpp`
2. Update `include/Display.h` if adding new public methods
3. Test in terminal to ensure proper rendering
4. Consider different terminal sizes and color schemes

### Adding Game Flow Features
1. Modify `src/Game.cpp` for game logic changes
2. Update `include/Game.h` for new state or methods
3. Consider user experience and error handling
4. Test interaction with keyboard controls

## File Organization
- `include/*.h` - Header files with class declarations
- `src/*.cpp` - Implementation files
- `src/main.cpp` - Program entry point
- `src/test_chess.cpp` - Unit tests
- `CMakeLists.txt` - Build configuration
- `LAB_GUIDE.md` - Lab exercises documentation

## Build System
- Uses CMake 3.10+
- Requires C++17 standard
- Links against ncurses library
- Produces three executables: chess, test_chess, demo_board

## Best Practices for This Project
- Run tests after making changes: `./build/test_chess`
- Build frequently to catch errors early: `make` in build directory
- Test the game manually to verify user experience: `./build/chess`
- Keep changes minimal and focused
- Document any chess rules that might not be obvious
- Consider the educational nature - make code clear and learnable
