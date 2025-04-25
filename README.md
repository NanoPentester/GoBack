# goback - A Smart Directory Navigation Tool

## Overview
`goback` is a modern C++ utility that provides intuitive directory navigation, allowing you to quickly move up multiple directory levels with a single command. Unlike the standard `cd ..`, this tool lets you specify exactly how many levels you want to jump up in your filesystem hierarchy.

## Features

- **Multi-level navigation**: Jump up N directories with a single command
- **Smart root detection**: Prevents navigating above the root directory
- **Shell integration**: Works seamlessly in bash, zsh, and other shells

## Installation

### Prerequisites
- C++17 compatible compiler (g++ 8+, clang++ 7+, or MSVC 2019+)
- CMake 3.12+ (recommended)

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/yourusername/GoBack.git
cd GoBack

# Build with CMake
mkdir build && cd build
cmake ..
make

# Install system-wide (optional)
sudo make install
```

### Manual Compilation
```bash
g++ -std=c++17 -o GoBack src/main.cpp
```

## Usage

### Basic Commands
```bash
goback 2      # Move up 2 directory levels
goback        # Defaults to moving up 1 level (same as cd ..)
goabck -p 3   # Print the target path without changing directory
```

### Shell Integration
Add this to your `.bashrc` or `.zshrc` for seamless shell usage:
```bash
# For bash/zsh
goabck() {
    cd "$(goabck -p "$@")"
}

# For fish shell
function goaback
    cd (goback -p $argv)
end
```

## Examples

1. **Quick Navigation**
   ```bash
   # Starting at /home/user/projects/src/modules
   goback 3
   # Now in /home/user/projects
   ```

2. **Script Usage**
   ```bash
   # In a build script
   goback 2 && mkdir build
   ```

3. **Path Inspection**
   ```bash
   # See where you would go without changing directory
   goback -p 2
   # Outputs: /home/user/projects
   ```
