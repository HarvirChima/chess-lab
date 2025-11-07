#!/usr/bin/env bash

# Lab Verification Script
# This script verifies that the lab is set up correctly

echo "🧪 Chess Lab Verification Script"
echo "=================================="
echo ""

# Check if all required files exist
echo "📁 Checking lab files..."

required_files=(
    "GET_STARTED.md"
    "LAB_GUIDE.md"
    "INSTRUCTOR_GUIDE.md"
    ".github/copilot-instructions.md"
    ".github/chess-test.prompt.md"
    ".github/copilot-chat-participants.json"
    ".vscode/settings.json"
)

all_files_exist=true
for file in "${required_files[@]}"; do
    if [ -f "$file" ]; then
        echo "  ✅ $file"
    else
        echo "  ❌ $file (MISSING)"
        all_files_exist=false
    fi
done

echo ""

# Check if build directory exists
echo "🔨 Checking build..."
if [ -d "build" ]; then
    echo "  ✅ Build directory exists"
    
    if [ -f "build/chess" ] && [ -f "build/test_chess" ]; then
        echo "  ✅ Executables built"
        
        # Run tests
        echo ""
        echo "🧪 Running tests..."
        cd build
        if ./test_chess; then
            echo "  ✅ All tests pass"
        else
            echo "  ❌ Some tests failed"
        fi
        cd ..
    else
        echo "  ⚠️  Executables not built. Run 'cd build && make'"
    fi
else
    echo "  ⚠️  Build directory doesn't exist. Run 'mkdir build && cd build && cmake .. && make'"
fi

echo ""

# Verify the intentional bug exists
echo "🐛 Verifying Lab 3 bugs are present..."
if grep -q "absRowDiff == 1" src/Board.cpp; then
    echo "  ✅ Bug 1: Pawn backward movement bug is present (good for lab!)"
else
    echo "  ❌ Bug 1 may have been fixed"
fi

if grep -q "Invalid move! Try again." src/Game.cpp; then
    echo "  ✅ Bug 2: Generic error message present (good for lab!)"
else
    echo "  ❌ Bug 2 may have been fixed"
fi

echo ""
echo "=================================="

if [ "$all_files_exist" = true ]; then
    echo "✅ Lab setup complete! Ready to start learning."
    echo ""
    echo "📖 Next steps:"
    echo "   1. Open VS Code in this directory"
    echo "   2. Open GET_STARTED.md to choose your path"
    echo "   3. Follow either Path A (Labs) or Path B (Play)"
    exit 0
else
    echo "❌ Some files are missing. Please check the setup."
    exit 1
fi
