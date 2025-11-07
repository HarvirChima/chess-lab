cmake_minimum_required(VERSION 3.10)
project(ChessLab VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Find ncurses library for terminal UI
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add source files
add_executable(chess 
    src/main.cpp
    src/Board.cpp
    src/Piece.cpp
    src/Game.cpp
    src/Display.cpp
)

# Link ncurses library
target_link_libraries(chess ${CURSES_LIBRARIES})

# Include directories
target_include_directories(chess PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Add test executable (optional)
add_executable(test_chess 
    src/test_chess.cpp
    src/Board.cpp
    src/Piece.cpp
)
target_include_directories(test_chess PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Add demo board viewer
add_executable(demo_board
    src/demo_board.cpp
    src/Board.cpp
    src/Piece.cpp
)
target_include_directories(demo_board PRIVATE ${CMAKE_SOURCE_DIR}/include)
