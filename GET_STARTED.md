# Get Started with Chess Lab 🚀

This guide will get you up and running in **5 minutes**!

## 🎯 Choose Your Path

**What do you want to do?**

### 🎓 I want to learn GitHub Copilot
→ Follow [**Path A: Learning Labs**](#path-a-learning-labs) below

### ♟️ I just want to play chess
→ Follow [**Path B: Play the Game**](#path-b-play-the-game) below

---

## Path A: Learning Labs

Perfect for learning GitHub Copilot through hands-on exercises!

### Prerequisites Check

Run these commands to verify you have what you need:

```bash
g++ --version    # C++ compiler (need 7.0+)
cmake --version  # Build tool (need 3.10+)
git --version    # Version control
code --version   # VS Code (optional but recommended)
```

**Missing something?** Jump to [Installation Guide](#installation-guide) below.

### Quick Setup

```bash
# 1. Get the code
# Download ZIP from https://github.com/HarvirChima/chess-lab
# OR clone with git:
git clone https://github.com/HarvirChima/chess-lab.git
cd chess-lab

# 2. Open in VS Code
code .

# 3. Build the project
mkdir build && cd build
cmake ..
make

# 4. Verify it works
./test_chess
```

### Start Learning!

Once setup is complete, **open [LAB_GUIDE.md](LAB_GUIDE.md)** and start with Lab 1!

**Lab Overview** (2.5 hours total):
1. **Lab 1 (15 min)**: Ask Mode - Query code naturally
2. **Lab 2 (20 min)**: Copilot Instructions - Customize AI behavior  
3. **Lab 3 (25 min)**: Agent Mode - Fix bugs autonomously
4. **Lab 4 (20 min)**: Prompt Files - Create reusable prompts
5. **Lab 5 (25 min)**: Custom Chat - Build specialized AI assistants
6. **Lab 6 (30 min)**: Advanced - Master best practices

---

## Path B: Play the Game

Just want to play chess? Here's the fastest way!

### Prerequisites Check

```bash
g++ --version    # C++ compiler (need 7.0+)
cmake --version  # Build tool (need 3.10+)
```

**Missing something?** Jump to [Installation Guide](#installation-guide) below.

### Quick Setup

```bash
# Get the code
git clone https://github.com/HarvirChima/chess-lab.git
cd chess-lab

# Build and play
mkdir build && cd build
cmake .. && make
./chess
```

### Game Controls

| Key | Action |
|-----|--------|
| ↑ ↓ ← → | Move cursor around board |
| SPACE | Select piece, then move it |
| Q | Quit game |

**Your First Move:**
1. Use arrows to move to `e2` (white pawn, 2nd row from bottom)
2. Press SPACE to select
3. Move to `e4` (4th row, same column)
4. Press SPACE to move
5. You just made the classic "King's Pawn Opening"! ♔

---

## Installation Guide

This section explains how to install everything you need, step by step. Don't worry if you're new to this - we'll explain everything!

### What You Need to Install

Before you can run the chess game, you need these tools:

1. **C++ Compiler** - Translates the code into a program your computer can run
2. **CMake** - Helps organize and build C++ projects
3. **ncurses Library** - Creates the chess board display in your terminal
4. **Git** - Downloads code from GitHub

### macOS 🍎

#### What is Homebrew?
Homebrew is a **package manager** for macOS. Think of it like an app store for developer tools - it makes installing and updating software easy. Instead of downloading installers from websites, you just type one command.

#### Step 1: Install Homebrew (if you don't have it)

1. **Open Terminal** (press `Cmd + Space`, type "Terminal", press Enter)

2. **Check if Homebrew is already installed:**
   ```bash
   brew --version
   ```
   
   - If you see a version number, Homebrew is installed! Skip to Step 2.
   - If you see "command not found", continue below to install it.

3. **Install Homebrew by running this command:**
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```
   
   **What this does:** Downloads and runs the Homebrew installer script
   
   - You'll be asked to press Enter to continue
   - You may need to enter your Mac password (the one you use to log in)
   - The installation takes 2-5 minutes

4. **Follow any additional instructions** that appear after installation (like adding Homebrew to your PATH)

#### Step 2: Install Required Packages

Now that you have Homebrew, installing the tools is easy:

```bash
brew install ncurses cmake git
```

**What this does:** 
- Downloads and installs all three packages
- Takes about 2-3 minutes
- You'll see progress messages as each package installs

**If you see errors:** Make sure Homebrew installed correctly in Step 1. Try running `brew doctor` to check for issues.

---

### Windows 🪟

#### What is WSL2?
WSL2 (Windows Subsystem for Linux) lets you run Linux on Windows. Think of it like a mini Linux computer inside your Windows computer. We use it because the chess game works best on Linux/Unix systems.

#### Why not use Windows directly?
You could, but it's more complicated. WSL2 is the easiest and most reliable way to run this project on Windows.

#### Step 1: Install WSL2

1. **Open PowerShell as Administrator:**
   - Press `Windows key`
   - Type "PowerShell"
   - Right-click "Windows PowerShell"
   - Click "Run as administrator"
   - Click "Yes" when asked for permission

2. **Install WSL2 with one command:**
   ```powershell
   wsl --install
   ```
   
   **What this does:**
   - Downloads and installs WSL2
   - Installs Ubuntu Linux (a popular Linux version)
   - Takes 5-10 minutes depending on your internet speed
   
   **What you'll see:**
   - Progress messages about downloading Ubuntu
   - Messages about installing Virtual Machine Platform

3. **Restart your computer** when prompted
   - This is required for WSL2 to work
   - Your computer will restart automatically

#### Step 2: Set Up Ubuntu

After restarting:

1. **Open Ubuntu from the Start menu:**
   - Press `Windows key`
   - Type "Ubuntu"
   - Click on "Ubuntu" (you'll see the orange Ubuntu icon)

2. **First-time setup (only happens once):**
   - Wait a minute while Ubuntu finishes installing
   - You'll be asked to create a username (can be anything, like your name)
   - You'll be asked to create a password (you'll need to remember this!)
   - **Important:** When typing your password, you won't see any characters appear - this is normal for security! Just type it and press Enter.

3. **You now have a Linux terminal!** It looks like a black window with text.

#### Step 3: Install Required Packages

Now you're in Ubuntu Linux. We need to install the development tools.

**What is apt-get?**
`apt-get` is Ubuntu's **package manager** - like an app store for Linux programs. It downloads and installs software for you.

**Run these commands in your Ubuntu terminal:**

```bash
# Update the package list (like refreshing an app store)
sudo apt-get update
```

**What this does:**
- Downloads the latest list of available packages
- Takes 10-30 seconds
- You might see lots of text scrolling by - that's normal!

```bash
# Install all the tools we need
sudo apt-get install -y libncurses5-dev libncursesw5-dev cmake g++ git
```

**What this does:**
- Installs the C++ compiler (`g++`)
- Installs CMake (build tool)
- Installs ncurses (for the chess board display)
- Installs Git (to download code)
- The `-y` means "yes to all" so you don't have to confirm each package
- Takes 2-5 minutes

**What is `sudo`?**
`sudo` means "super user do" - it gives you administrator permissions to install software. You'll need to enter the password you created in Step 2.

**You're all set!** From now on, you'll use the Ubuntu terminal for all commands in this guide.

---

### Linux 🐧

Good news - you're already running Linux! You just need to install the development tools.

#### What is a Package Manager?
Linux uses **package managers** to install software. Think of it like an app store. Different Linux versions use different package managers:
- **Ubuntu/Debian** uses `apt-get`
- **Fedora/RHEL** uses `dnf`
- **Arch** uses `pacman`

#### For Ubuntu/Debian (including Ubuntu, Mint, Pop!_OS)

**Open your terminal** (usually `Ctrl + Alt + T`)

```bash
# Update package list (like refreshing an app store)
sudo apt-get update

# Install required tools
sudo apt-get install -y libncurses5-dev libncursesw5-dev cmake g++ git
```

**What `sudo` means:**
`sudo` gives you administrator permissions. You'll need to enter your password.

**What gets installed:**
- `g++` - C++ compiler
- `cmake` - Build system
- `libncurses5-dev` / `libncursesw5-dev` - Terminal graphics library
- `git` - Version control

Takes 2-5 minutes to install.

#### For Fedora/RHEL/CentOS

```bash
# Install required tools
sudo dnf install ncurses-devel cmake gcc-c++ git
```

**What `dnf` is:**
`dnf` is Fedora's package manager (similar to `apt-get` on Ubuntu)

#### For Arch Linux

```bash
# Install required tools
sudo pacman -S ncurses cmake gcc git
```

---

### ✅ Verify Everything is Installed

After installation on **any operating system**, verify everything worked:

```bash
# Check C++ compiler
g++ --version
```
**Expected:** Should show version 7.0 or higher (e.g., "g++ (GCC) 11.3.0")

```bash
# Check CMake
cmake --version
```
**Expected:** Should show version 3.10 or higher (e.g., "cmake version 3.22.1")

```bash
# Check Git
git --version
```
**Expected:** Should show any version (e.g., "git version 2.34.1")

**If any command shows "command not found":** That tool didn't install correctly. Go back to the installation section for your operating system and try again.

---

## Troubleshooting

### Build Issues

**"cmake: command not found"**
```bash
# Install CMake for your OS (see Installation Guide above)
```

**"ncurses.h: No such file or directory"**
```bash
# Ubuntu/Debian
sudo apt-get install libncurses5-dev libncursesw5-dev

# macOS
brew install ncurses
```

**"make: command not found"**
```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# macOS
xcode-select --install
```

### Game Issues

**Weird characters or display problems**
- Try a different terminal program
- Make sure terminal is at least 80x24 characters
- Increase font size

**Permission denied when running ./chess**
```bash
# Make sure you're in the build directory
cd build
./chess
```

### Copilot Issues (Lab Path)

**Copilot not providing suggestions**
1. Check VS Code status bar - ensure Copilot icon shows checkmark
2. Press Ctrl+Shift+P → "Reload Window"
3. Sign in to GitHub in VS Code
4. Verify subscription at github.com/settings/copilot

---

## What's Next?

### For Learners (Lab Path)
✅ Setup complete? **Open [LAB_GUIDE.md](LAB_GUIDE.md)** to start Lab 1!

### For Players (Game Path)
- Want to understand the code? See [README.md](README.md)
- Want to contribute? See [CONTRIBUTING.md](CONTRIBUTING.md)
- Want quick reference? See [REFERENCE.md](REFERENCE.md)

### For Instructors
Teaching this lab? See [INSTRUCTOR_GUIDE.md](INSTRUCTOR_GUIDE.md)

---

## Quick Reference

### Essential Commands

```bash
# After building (run from build/ directory):
./chess          # Play the chess game
./test_chess     # Run unit tests
./demo_board     # View demo board

# To rebuild after code changes:
make

# Clean rebuild:
rm -rf * && cmake .. && make
```

### Project Structure

```
chess-lab/
├── GET_STARTED.md         ← YOU ARE HERE
├── README.md              ← Project overview
├── LAB_GUIDE.md           ← Complete lab exercises
├── REFERENCE.md           ← Quick reference card
├── CONTRIBUTING.md        ← How to contribute
└── INSTRUCTOR_GUIDE.md    ← For instructors
```

---

**Need more help?** 
- 📖 Full details: [README.md](README.md)
- 🎓 Lab exercises: [LAB_GUIDE.md](LAB_GUIDE.md)
- 📋 Quick reference: [REFERENCE.md](REFERENCE.md)
- 🐛 Report issues: [GitHub Issues](https://github.com/HarvirChima/chess-lab/issues)

**Enjoying the lab?** ⭐ Star the project on GitHub!
