# GitHub Copilot Configuration

This directory contains configuration files for GitHub Copilot to enhance your learning experience.

> **Note**: This project uses the latest VS Code custom chat mode format (`.chatmode.md` files). If you see a `copilot-chat-modes.json` file, it's deprecated and should be replaced with individual `.chatmode.md` files. See [VS Code Custom Chat Modes documentation](https://code.visualstudio.com/docs/copilot/customization/custom-chat-modes) for details.

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

### Custom Chat Mode Files (`.chatmode.md`)
Defines custom chat modes (specialized AI assistants) for this project. Each mode is a separate `.chatmode.md` file:

- **chessexpert.chatmode.md**: Chess grandmaster and programming expert
- **testexpert.chatmode.md**: Testing and QA specialist
- **codereview.chatmode.md**: Code review expert

**How to use:**
```
In Copilot Chat:
@chessexpert How should I implement castling?
@testexpert Generate tests for bishop movement
@codereview Review the Board::isValidMove function
```

**File Format:**
Each `.chatmode.md` file uses YAML frontmatter for configuration and Markdown for instructions:
```markdown
---
title: Mode Name
description: What this mode does
tools: ['codebase', 'search']
---

# Instructions for the AI assistant...
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

### Adding Chat Modes

Create a new `.chatmode.md` file in the `.github` directory:

```markdown
---
title: Your Mode Name
description: Short description of what this mode does
tools: ['codebase', 'search']
authors:
  - your-name
version: 1.0.0
---

# Your Mode Instructions

Detailed instructions for how the AI should behave in this mode...

## Guidelines
- Specific behaviors
- Focus areas
- Communication style
```

**Available Tools:**
- `codebase`: Access to project files and code
- `search`: Search within the project
- `websearch`: Search the web (if enabled)

## Learning More

- See [LAB_GUIDE.md](../LAB_GUIDE.md) for complete lab exercises
- Lab 2: Learn about Copilot Instructions
- Lab 4: Learn about Prompt Files
- Lab 5: Learn about Custom Chat Modes

## Best Practices

1. **Keep instructions focused**: Don't overload with too many rules
2. **Be specific**: Clear, specific instructions work better than vague ones
3. **Update regularly**: As your project evolves, update these files
4. **Test your prompts**: Try out prompt files to ensure they work well
5. **Share with team**: Commit these files so everyone gets consistent Copilot behavior
6. **Use modern format**: Use `.chatmode.md` files instead of deprecated JSON format

## References

- [VS Code Custom Chat Modes Documentation](https://code.visualstudio.com/docs/copilot/customization/custom-chat-modes)
- [Copilot Customization Overview](https://code.visualstudio.com/docs/copilot/customization/overview)
- [Prompt Engineering Guide](https://platform.openai.com/docs/guides/prompt-engineering)

---

**Happy coding with Copilot! 🤖**
