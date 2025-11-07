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
    
    // Initialize colors with improved color scheme
    if (has_colors()) {
        start_color();
        // Define color pairs for a more aesthetic board
        init_pair(1, COLOR_WHITE, COLOR_BLACK);     // General white text
        init_pair(3, COLOR_YELLOW, COLOR_BLUE);     // Highlighted square
        init_pair(4, COLOR_GREEN, COLOR_BLACK);     // Messages and borders
        init_pair(5, COLOR_WHITE, COLOR_GREEN);     // White pieces on light squares
        init_pair(6, COLOR_WHITE, COLOR_CYAN);      // White pieces on dark squares
        init_pair(7, COLOR_BLACK, COLOR_GREEN);     // Black pieces on light squares
        init_pair(8, COLOR_BLACK, COLOR_CYAN);      // Black pieces on dark squares
    }
    
    // Create game window
    gameWindow = newwin(24, 60, 0, 0);
    
    // Draw initial frame with decorative border
    box(gameWindow, 0, 0);
    if (has_colors()) {
        wattron(gameWindow, COLOR_PAIR(4) | A_BOLD);
    }
    mvwprintw(gameWindow, 0, 2, "[ ♟ Chess Lab - Beautiful Edition ♟ ]");
    if (has_colors()) {
        wattroff(gameWindow, COLOR_PAIR(4) | A_BOLD);
    }
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
    // Draw top border with decorative edge
    if (has_colors()) {
        wattron(gameWindow, COLOR_PAIR(4));
    }
    mvwprintw(gameWindow, startRow, startCol, "    ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗");
    if (has_colors()) {
        wattroff(gameWindow, COLOR_PAIR(4));
    }
    
    // Draw column labels
    mvwprintw(gameWindow, startRow - 1, startCol + 4, " a   b   c   d   e   f   g   h");
    
    // Draw the board with Unicode pieces
    for (int row = 0; row < 8; row++) {
        // Draw row number
        mvwprintw(gameWindow, startRow + 1 + row * 2, startCol, "%d", 8 - row);
        
        // Draw left border
        if (has_colors()) {
            wattron(gameWindow, COLOR_PAIR(4));
        }
        mvwprintw(gameWindow, startRow + 1 + row * 2, startCol + 4, "║");
        if (has_colors()) {
            wattroff(gameWindow, COLOR_PAIR(4));
        }
        
        for (int col = 0; col < 8; col++) {
            int displayRow = startRow + 1 + row * 2;
            int displayCol = startCol + 5 + col * 4;
            
            // Determine square color
            bool isDark = (row + col) % 2 == 1;
            
            // Draw square with piece
            Piece piece = board.getPiece(row, col);
            if (!piece.isEmpty()) {
                // Draw piece with appropriate coloring
                if (has_colors()) {
                    if (isDark) {
                        if (piece.getColor() == PieceColor::WHITE) {
                            wattron(gameWindow, COLOR_PAIR(6) | A_BOLD);
                        } else {
                            wattron(gameWindow, COLOR_PAIR(8));
                        }
                    } else {
                        if (piece.getColor() == PieceColor::WHITE) {
                            wattron(gameWindow, COLOR_PAIR(5) | A_BOLD);
                        } else {
                            wattron(gameWindow, COLOR_PAIR(7));
                        }
                    }
                }
                mvwprintw(gameWindow, displayRow, displayCol, " %s ", piece.getUnicodeSymbol().c_str());
                if (has_colors()) {
                    if (isDark) {
                        if (piece.getColor() == PieceColor::WHITE) {
                            wattroff(gameWindow, COLOR_PAIR(6) | A_BOLD);
                        } else {
                            wattroff(gameWindow, COLOR_PAIR(8));
                        }
                    } else {
                        if (piece.getColor() == PieceColor::WHITE) {
                            wattroff(gameWindow, COLOR_PAIR(5) | A_BOLD);
                        } else {
                            wattroff(gameWindow, COLOR_PAIR(7));
                        }
                    }
                }
            } else {
                // Draw empty square with background color
                if (has_colors()) {
                    wattron(gameWindow, COLOR_PAIR(isDark ? 6 : 5));
                }
                mvwprintw(gameWindow, displayRow, displayCol, "   ");
                if (has_colors()) {
                    wattroff(gameWindow, COLOR_PAIR(isDark ? 6 : 5));
                }
            }
            
            // Draw vertical separator
            if (has_colors()) {
                wattron(gameWindow, COLOR_PAIR(4));
            }
            mvwprintw(gameWindow, displayRow, displayCol + 3, "║");
            if (has_colors()) {
                wattroff(gameWindow, COLOR_PAIR(4));
            }
        }
        
        // Draw row number on the right
        mvwprintw(gameWindow, startRow + 1 + row * 2, startCol + 41, "%d", 8 - row);
        
        // Draw horizontal separator (except after last row)
        if (row < 7) {
            if (has_colors()) {
                wattron(gameWindow, COLOR_PAIR(4));
            }
            mvwprintw(gameWindow, startRow + 2 + row * 2, startCol, "    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣");
            if (has_colors()) {
                wattroff(gameWindow, COLOR_PAIR(4));
            }
        }
    }
    
    // Draw bottom border
    if (has_colors()) {
        wattron(gameWindow, COLOR_PAIR(4));
    }
    mvwprintw(gameWindow, startRow + 17, startCol, "    ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝");
    if (has_colors()) {
        wattroff(gameWindow, COLOR_PAIR(4));
    }
    
    // Draw column labels at bottom
    mvwprintw(gameWindow, startRow + 18, startCol + 4, " a   b   c   d   e   f   g   h");
}

void Display::drawPiece(int row, int col, const Piece& piece, bool highlight) {
    int displayRow = startRow + 1 + row * 2;
    int displayCol = startCol + 6 + col * 4;
    
    bool isDark = (row + col) % 2 == 1;
    
    if (has_colors()) {
        if (highlight) {
            wattron(gameWindow, COLOR_PAIR(3) | A_BOLD);
        } else if (isDark) {
            if (piece.getColor() == PieceColor::WHITE) {
                wattron(gameWindow, COLOR_PAIR(6) | A_BOLD);
            } else {
                wattron(gameWindow, COLOR_PAIR(8));
            }
        } else {
            if (piece.getColor() == PieceColor::WHITE) {
                wattron(gameWindow, COLOR_PAIR(5) | A_BOLD);
            } else {
                wattron(gameWindow, COLOR_PAIR(7));
            }
        }
    }
    
    mvwprintw(gameWindow, displayRow, displayCol, "%s", piece.getUnicodeSymbol().c_str());
    
    if (has_colors()) {
        if (highlight) {
            wattroff(gameWindow, COLOR_PAIR(3) | A_BOLD);
        } else if (isDark) {
            if (piece.getColor() == PieceColor::WHITE) {
                wattroff(gameWindow, COLOR_PAIR(6) | A_BOLD);
            } else {
                wattroff(gameWindow, COLOR_PAIR(8));
            }
        } else {
            if (piece.getColor() == PieceColor::WHITE) {
                wattroff(gameWindow, COLOR_PAIR(5) | A_BOLD);
            } else {
                wattroff(gameWindow, COLOR_PAIR(7));
            }
        }
    }
}

void Display::highlightSquare(int row, int col) {
    int displayRow = startRow + 1 + row * 2;
    int displayCol = startCol + 5 + col * 4;
    
    if (has_colors()) {
        wattron(gameWindow, COLOR_PAIR(3) | A_BOLD);
    }
    mvwprintw(gameWindow, displayRow, displayCol, ">");
    mvwprintw(gameWindow, displayRow, displayCol + 2, "<");
    if (has_colors()) {
        wattroff(gameWindow, COLOR_PAIR(3) | A_BOLD);
    }
}

void Display::clearHighlight(int row, int col) {
    int displayRow = startRow + 1 + row * 2;
    int displayCol = startCol + 5 + col * 4;
    
    mvwprintw(gameWindow, displayRow, displayCol, " ");
    mvwprintw(gameWindow, displayRow, displayCol + 2, " ");
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
