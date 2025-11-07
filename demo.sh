#!/bin/bash

# Demo script for Chess Lab
# This script helps you build, test, and run the chess game

set -e  # Exit on error

echo "╔════════════════════════════════════════════════════════════╗"
echo "║     Chess Lab - GitHub Copilot Hands-On Demo Script       ║"
echo "╚════════════════════════════════════════════════════════════╝"
echo ""
echo "This script will guide you through building and running the chess game."
echo ""
echo "🎯 What this lab teaches:"
echo "  ✓ Building C++ projects with CMake"
echo "  ✓ Running unit tests"
echo "  ✓ Using GitHub Copilot for code understanding"
echo "  ✓ Extending code with AI assistance"
echo ""
echo "📋 Features of this chess game:"
echo "  • Complete chess implementation with standard rules"
echo "  • Terminal-based UI using ncurses library"
echo "  • Interactive gameplay with keyboard controls"
echo "  • Color-coded pieces (White: UPPERCASE, Black: lowercase)"
echo ""
echo "🎮 Controls:"
echo "  • Arrow keys (↑↓←→) : Move cursor around board"
echo "  • SPACE bar        : Select piece / Make move"
echo "  • Q key            : Quit game"
echo ""

# Function to print step headers
print_step() {
    echo ""
    echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
    echo "📍 STEP $1: $2"
    echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
}

# Function to wait for user
wait_for_user() {
    echo ""
    read -p "Press ENTER to continue..." dummy
}

# Check if we're in the right directory
if [ ! -f "CMakeLists.txt" ]; then
    echo "❌ Error: CMakeLists.txt not found!"
    echo "   Please run this script from the chess-lab root directory."
    exit 1
fi

print_step "1" "Checking Prerequisites"
echo ""
echo "Checking if required tools are installed..."
echo ""

# Check for required tools
all_good=true

if command -v g++ &> /dev/null; then
    gcc_version=$(g++ --version | head -n1)
    echo "✓ C++ Compiler found: $gcc_version"
else
    echo "✗ C++ Compiler (g++) not found"
    all_good=false
fi

if command -v cmake &> /dev/null; then
    cmake_version=$(cmake --version | head -n1)
    echo "✓ CMake found: $cmake_version"
else
    echo "✗ CMake not found"
    all_good=false
fi

if command -v make &> /dev/null; then
    echo "✓ Make build tool found"
else
    echo "✗ Make not found"
    all_good=false
fi

if [ "$all_good" = false ]; then
    echo ""
    echo "❌ Missing required tools. Please install them first:"
    echo ""
    echo "Ubuntu/Debian:"
    echo "  sudo apt-get install cmake g++ libncurses5-dev libncursesw5-dev"
    echo ""
    echo "macOS:"
    echo "  brew install cmake ncurses"
    echo ""
    exit 1
fi

echo ""
echo "✅ All prerequisites are installed!"
wait_for_user

print_step "2" "Creating Build Directory"
echo ""
echo "Creating a 'build' directory to keep build files separate from source code..."
echo ""

if [ -d "build" ]; then
    echo "ℹ️  Build directory already exists. Cleaning it..."
    rm -rf build/*
else
    mkdir build
fi

echo "✓ Build directory ready: $(pwd)/build"
wait_for_user

print_step "3" "Configuring with CMake"
echo ""
echo "Running CMake to configure the build system..."
echo "This checks your system and prepares the Makefiles."
echo ""
echo "Command: cmake .."
echo ""

cd build
if cmake ..; then
    echo ""
    echo "✓ CMake configuration successful!"
else
    echo ""
    echo "❌ CMake configuration failed. Check the error messages above."
    exit 1
fi

wait_for_user

print_step "4" "Building the Project"
echo ""
echo "Compiling the C++ source code into executable programs..."
echo "This creates three programs: chess, test_chess, and demo_board"
echo ""
echo "Command: make"
echo ""

if make; then
    echo ""
    echo "✓ Build successful! Three executables created:"
    echo "  • chess       - The main chess game"
    echo "  • test_chess  - Unit tests"
    echo "  • demo_board  - Board visualization demo"
else
    echo ""
    echo "❌ Build failed. Check the error messages above."
    exit 1
fi

wait_for_user

print_step "5" "Running Unit Tests"
echo ""
echo "Let's verify everything works by running the test suite..."
echo ""
echo "Command: ./test_chess"
echo ""

if ./test_chess; then
    echo ""
    echo "✓ All tests passed! The chess game is working correctly."
else
    echo ""
    echo "❌ Some tests failed. The game may not work as expected."
    exit 1
fi

wait_for_user

print_step "6" "Viewing the Demo Board"
echo ""
echo "Let's see what the chess board looks like..."
echo ""
echo "Command: ./demo_board"
echo ""

./demo_board

wait_for_user

print_step "7" "Ready to Play!"
echo ""
echo "🎉 Congratulations! You've successfully built the Chess Lab project!"
echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  WHAT YOU CAN DO NOW:"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""
echo "1️⃣  Play the chess game:"
echo "   cd build && ./chess"
echo ""
echo "2️⃣  Explore the code:"
echo "   • Open files in src/ and include/ directories"
echo "   • Read through main.cpp to understand program flow"
echo "   • Check out Board.cpp to see move validation logic"
echo ""
echo "3️⃣  Use GitHub Copilot (if installed):"
echo "   • Open the project in VS Code: code ."
echo "   • Try adding comments to functions"
echo "   • Ask Copilot to explain complex code"
echo "   • Try adding new features!"
echo ""
echo "4️⃣  Try some lab exercises:"
echo "   • Add a move counter"
echo "   • Implement check detection"
echo "   • Add castling support"
echo "   • Create an AI opponent"
echo ""
echo "5️⃣  Read the documentation:"
echo "   • GET_STARTED.md - Quick start guide (start here!)"
echo "   • LAB_GUIDE.md - Complete Copilot lab exercises"
echo "   • README.md - Project overview"
echo "   • REFERENCE.md - Quick reference card"
echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""
read -p "Would you like to start the game now? (y/n) " -n 1 -r
echo ""

if [[ $REPLY =~ ^[Yy]$ ]]; then
    echo ""
    echo "Starting chess game in 3 seconds..."
    echo "Remember: Arrow keys to move, SPACE to select/move, Q to quit"
    echo ""
    sleep 3
    ./chess
else
    echo ""
    echo "No problem! You can start the game anytime by running:"
    echo "  cd build && ./chess"
    echo ""
    echo "Happy coding! 🎮♟️"
fi

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  Thank you for trying Chess Lab!"
echo "  Star us on GitHub if you found this helpful! ⭐"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""
