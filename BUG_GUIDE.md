# Chess Lab - Bug Demonstrations

This document demonstrates the intentional bugs in the chess game that students will fix in Lab 3.

## Bug 1: Pawns Can Move Backwards

### Expected Behavior
In chess, pawns can only move forward:
- White pawns move toward row 0 (up the board)
- Black pawns move toward row 7 (down the board)
- Pawns should NEVER be able to move backwards

### Current Buggy Behavior
The pawn movement validation has a bug that allows pawns to move one square in ANY direction, including backwards!

### How to Reproduce
1. Start the chess game: `./build/chess`
2. Move a white pawn forward (e.g., e2 to e4)
3. On your next turn, try to move that same pawn backwards (e.g., e4 to e5)
4. **BUG**: The game allows this illegal move!

### The Bug in Code
Location: `src/Board.cpp` line ~110

```cpp
// Current BUGGY code:
if (colDiff == 0 && absRowDiff == 1 && targetPiece.isEmpty()) {
    return true;  // BUG: Uses absRowDiff, allowing backward movement!
}
```

### The Fix
The code should check that the pawn moves in the correct direction:

```cpp
// Fixed code:
if (colDiff == 0 && rowDiff == direction && targetPiece.isEmpty()) {
    return true;  // Correct: Checks actual direction, not just distance
}
```

### Lab Exercise
In Lab 3, you'll use GitHub Copilot Agent Mode to fix this bug. The Agent will:
1. Analyze the pawn movement code
2. Identify the incorrect validation
3. Fix the bug to enforce directional movement
4. Add test cases to prevent regression

---

## Bug 2: Unhelpful Error Messages

### Expected Behavior
When a player attempts an invalid move, the game should explain WHY the move is invalid:
- "Pawns can only move forward"
- "Knights move in an L-shape"
- "That path is blocked"
- "You cannot move into check"

### Current Buggy Behavior
The game just says "Invalid move! Try again." without any explanation.

### How to Reproduce
1. Start the chess game: `./build/chess`
2. Try to make any invalid move (e.g., move a pawn diagonally without capturing)
3. **BUG**: You just see "Invalid move! Try again." with no explanation

### The Bug in Code
Location: `src/Game.cpp` line ~120

```cpp
// Current UNHELPFUL code:
} else {
    display.drawMessage("Invalid move! Try again.");
}
```

### The Fix
The code should provide specific feedback based on the type of error:

```cpp
} else {
    // Provide helpful error message
    std::string errorMsg = getInvalidMoveReason(selectedRow, selectedCol, toRow, toCol);
    display.drawMessage(errorMsg);
}
```

### Lab Exercise
In Lab 3, you'll use GitHub Copilot Agent Mode to:
1. Add logic to determine WHY a move is invalid
2. Create helpful, educational error messages
3. Consider different error scenarios
4. Make the game more user-friendly for learners

---

## Missing Feature: Move History

### Expected Behavior (Not Implemented)
Chess games typically track all moves made during the game:
- Display recent moves (e.g., "1. e4 e5 2. Nf3 Nc6")
- Allow players to review the game
- Enable game replay
- Support PGN export

### Current State
The game has no move history tracking at all!

### Lab Exercise
In Lab 3, you'll use GitHub Copilot Agent Mode to:
1. Add a data structure to store move history
2. Record each move with proper notation
3. Display recent moves to the player
4. Consider using standard algebraic notation

---

## Testing the Bugs

### Test Script for Bug 1 (Pawn Backwards)

Create a test in `src/test_chess.cpp`:

```cpp
void testPawnCannotMoveBackwards() {
    Board board;
    board.initialize();
    
    // Move white pawn forward (legal)
    assert(board.movePiece(6, 4, 4, 4)); // e2 to e4
    
    // Try to move it backwards (should be illegal!)
    assert(!board.movePiece(4, 4, 5, 4)); // e4 to e3 - SHOULD FAIL
    
    // The current bug makes this test fail!
    std::cout << "✓ Pawn backwards movement test passed" << std::endl;
}
```

### Why These Bugs Are Perfect for Learning

1. **Bug 1** teaches:
   - Understanding chess rules in code
   - Debugging logical errors
   - Writing better validation logic
   - The importance of directional vs. absolute checks

2. **Bug 2** teaches:
   - User experience considerations
   - Error handling best practices
   - Making code more maintainable
   - Educational software design

3. **Missing Feature** teaches:
   - Adding new functionality with Copilot
   - Data structure selection
   - Integration with existing code
   - Feature planning and implementation

---

## Additional Challenges (Optional)

Once you've fixed these bugs, try adding:

### Challenge 1: Prevent Moving Into Check
Currently, the game doesn't prevent players from moving their king into check or leaving their king in check.

### Challenge 2: Implement Castling
Castling is a special move in chess that's not yet implemented. Requirements:
- King hasn't moved
- Rook hasn't moved
- No pieces between king and rook
- King not in check
- King doesn't pass through check

### Challenge 3: Pawn Promotion
When a pawn reaches the opposite end, it should be promoted to Queen, Rook, Bishop, or Knight.

### Challenge 4: En Passant
This special pawn capture move is complex but interesting to implement!

---

**Ready to fix these bugs?** Go to [LAB_GUIDE.md](LAB_GUIDE.md) Lab 3!
