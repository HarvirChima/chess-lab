# Chess Test Generator Prompt

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

Based on the current codebase, generate test cases for the specified feature.

Include:
- At least 3 test scenarios
- Both valid and invalid cases
- Edge cases
- Clear, descriptive test names
- Comments explaining what each test verifies
