# GitHub Copilot Configuration

This directory contains configuration files for GitHub Copilot to enhance your learning experience.

## Files in This Directory

### `copilot-instructions.md`
Custom instructions that tell Copilot about this project's conventions, architecture, and preferences. This helps Copilot give better suggestions that match the project's style.

**What it does:**
- Tells Copilot about the chess game architecture
- Sets code style preferences
- Adds fun chess-themed personality
- Defines testing and documentation standards

**Auto-generated in VS Code**: Run Command Palette → "GitHub Copilot: Generate Instructions"

### `chess-test.prompt.md`
A reusable prompt file for generating comprehensive test cases for chess functionality.

**How to use:**
```
In Copilot Chat:
#file:.github/chess-test.prompt.md

Generate tests for [feature name]
```

### `copilot-chat-participants.json`
Defines custom chat participants (specialized AI assistants) for this project:

- **@chessexpert**: Chess grandmaster and programming expert
- **@testexpert**: Testing and QA specialist
- **@codereview**: Code review expert

**How to use:**
```
In Copilot Chat:
@chessexpert How should I implement castling?
@testexpert Generate tests for bishop movement
@codereview Review the Board::isValidMove function
```

## Creating Your Own Files

### Adding More Prompt Files

Create new `.prompt.md` files for different purposes:

```markdown
---
name: Your Prompt Name
description: What this prompt does
---

# Instructions here

Your prompt content...
```

### Customizing Instructions

Edit `copilot-instructions.md` to:
- Add project-specific guidelines
- Define coding patterns you want to follow
- Set preferences for error messages
- Add domain-specific knowledge

### Adding Chat Participants

Edit `copilot-chat-participants.json` to add specialized assistants:

```json
{
  "id": "uniqueid",
  "name": "Display Name",
  "description": "Short description",
  "systemMessage": "Detailed instructions for the AI..."
}
```

## Learning More

- See [LAB_GUIDE.md](../LAB_GUIDE.md) for complete lab exercises
- Lab 2: Learn about Copilot Instructions
- Lab 4: Learn about Prompt Files
- Lab 5: Learn about Custom Chat Participants

## Best Practices

1. **Keep instructions focused**: Don't overload with too many rules
2. **Be specific**: Clear, specific instructions work better than vague ones
3. **Update regularly**: As your project evolves, update these files
4. **Test your prompts**: Try out prompt files to ensure they work well
5. **Share with team**: Commit these files so everyone gets consistent Copilot behavior

---

**Happy coding with Copilot! 🤖**
