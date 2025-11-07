#include "Display.h"
#include <sstream>

Display::Display() : gameWindow(nullptr), startRow(2), startCol(2) {}

Display::~Display() {
    cleanup();
}

void Display::initialize() {
    initscr();              // Initialize ncurses
    cbreak();               // Disable line buffering
    noecho();               // Don't echo input
    keypad(stdscr, TRUE);   // Enable function keys
    curs_set(0);            // Hide cursor
    
    // Initialize colors
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);   // White pieces
        init_pair(2, COLOR_RED, COLOR_BLACK);     // Black pieces
        init_pair(3, COLOR_YELLOW, COLOR_BLUE);   // Highlighted square
        init_pair(4, COLOR_GREEN, COLOR_BLACK);   // Messages
    }
    
    // Create game window
    gameWindow = newwin(24, 60, 0, 0);
    
    // Draw initial frame
    box(gameWindow, 0, 0);
    mvwprintw(gameWindow, 0, 2, "[ Chess Lab - GitHub Copilot Demo ]");
    wrefresh(gameWindow);
}

void Display::cleanup() {
    if (gameWindow) {
        delwin(gameWindow);
        gameWindow = nullptr;
    }
    endwin();
}

void Display::drawBoard(const Board& board) {
    // Draw column labels
    mvwprintw(gameWindow, startRow, startCol + 2, "  a   b   c   d   e   f   g   h");
    
    // Draw the board
    for (int row = 0; row < 8; row++) {
        // Draw row number
        mvwprintw(gameWindow, startRow + 1 + row * 2, startCol, "%d", 8 - row);
        
        for (int col = 0; col < 8; col++) {
            int displayRow = startRow + 1 + row * 2;
            int displayCol = startCol + 2 + col * 4;
            
            // Draw square background
            bool isDark = (row + col) % 2 == 1;
            if (isDark) {
                mvwprintw(gameWindow, displayRow, displayCol, "####");
            } else {
                mvwprintw(gameWindow, displayRow, displayCol, "    ");
            }
            
            // Draw piece
            Piece piece = board.getPiece(row, col);
            if (!piece.isEmpty()) {
                drawPiece(row, col, piece, false);
            }
        }
        
        // Draw row number on the right
        mvwprintw(gameWindow, startRow + 1 + row * 2, startCol + 35, "%d", 8 - row);
    }
    
    // Draw column labels at bottom
    mvwprintw(gameWindow, startRow + 17, startCol + 2, "  a   b   c   d   e   f   g   h");
}

void Display::drawPiece(int row, int col, const Piece& piece, bool highlight) {
    int displayRow = startRow + 1 + row * 2;
    int displayCol = startCol + 3 + col * 4;
    
    if (has_colors()) {
        if (highlight) {
            wattron(gameWindow, COLOR_PAIR(3) | A_BOLD);
        } else if (piece.getColor() == PieceColor::WHITE) {
            wattron(gameWindow, COLOR_PAIR(1) | A_BOLD);
        } else {
            wattron(gameWindow, COLOR_PAIR(2) | A_BOLD);
        }
    }
    
    mvwprintw(gameWindow, displayRow, displayCol, "%c", piece.getSymbol());
    
    if (has_colors()) {
        if (highlight) {
            wattroff(gameWindow, COLOR_PAIR(3) | A_BOLD);
        } else if (piece.getColor() == PieceColor::WHITE) {
            wattroff(gameWindow, COLOR_PAIR(1) | A_BOLD);
        } else {
            wattroff(gameWindow, COLOR_PAIR(2) | A_BOLD);
        }
    }
}

void Display::highlightSquare(int row, int col) {
    int displayRow = startRow + 1 + row * 2;
    int displayCol = startCol + 2 + col * 4;
    
    if (has_colors()) {
        wattron(gameWindow, COLOR_PAIR(3));
    }
    mvwprintw(gameWindow, displayRow, displayCol, "[  ]");
    if (has_colors()) {
        wattroff(gameWindow, COLOR_PAIR(3));
    }
}

void Display::clearHighlight(int row, int col) {
    int displayRow = startRow + 1 + row * 2;
    int displayCol = startCol + 2 + col * 4;
    
    bool isDark = (row + col) % 2 == 1;
    if (isDark) {
        mvwprintw(gameWindow, displayRow, displayCol, "####");
    } else {
        mvwprintw(gameWindow, displayRow, displayCol, "    ");
    }
}

void Display::drawMessage(const std::string& message) {
    if (has_colors()) {
        wattron(gameWindow, COLOR_PAIR(4));
    }
    mvwprintw(gameWindow, startRow + 19, startCol, "%-50s", message.c_str());
    if (has_colors()) {
        wattroff(gameWindow, COLOR_PAIR(4));
    }
}

void Display::drawStatus(const std::string& status) {
    mvwprintw(gameWindow, startRow + 20, startCol, "%-50s", status.c_str());
}

void Display::refresh() {
    wrefresh(gameWindow);
}
