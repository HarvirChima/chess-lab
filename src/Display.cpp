#include "Display.h"
#include <sstream>
#include <locale.h>

Display::Display() : gameWindow(nullptr), startRow(2), startCol(2), theme(ColorTheme::CLASSIC) {}

Display::~Display() {
    cleanup();
}

void Display::initialize() {
    // Set locale to support UTF-8 Unicode characters
    setlocale(LC_ALL, "");
    
    initscr();              // Initialize ncurses
    cbreak();               // Disable line buffering
    noecho();               // Don't echo input
    keypad(stdscr, TRUE);   // Enable function keys
    curs_set(0);            // Hide cursor
    
    // Initialize colors with the currently selected theme
    if (has_colors()) {
        start_color();
        applyTheme(theme);
    }
    
    // Create game window
    gameWindow = newwin(24, 60, 0, 0);
    
    // Draw initial frame with decorative border
    box(gameWindow, 0, 0);
    if (has_colors()) {
        wattron(gameWindow, COLOR_PAIR(4) | A_BOLD);
    }
    mvwprintw(gameWindow, 0, 2, "[ ♟ Chess Lab - Classic Edition ♟ ]");
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

void Display::applyTheme(ColorTheme t) {
    theme = t;

    // Pick the foreground/background colors for light squares and dark squares.
    short lightBg = COLOR_WHITE;
    short darkBg  = COLOR_BLACK;
    short borderFg = COLOR_WHITE;
    short borderBg = COLOR_BLACK;

    switch (t) {
        case ColorTheme::CLASSIC:
            lightBg = COLOR_WHITE; darkBg = COLOR_BLACK;
            borderFg = COLOR_WHITE; borderBg = COLOR_BLACK;
            break;
        case ColorTheme::FOREST:
            lightBg = COLOR_GREEN; darkBg = COLOR_BLACK;
            borderFg = COLOR_GREEN; borderBg = COLOR_BLACK;
            break;
        case ColorTheme::OCEAN:
            lightBg = COLOR_CYAN; darkBg = COLOR_BLUE;
            borderFg = COLOR_CYAN; borderBg = COLOR_BLACK;
            break;
        case ColorTheme::SUNSET:
            lightBg = COLOR_YELLOW; darkBg = COLOR_RED;
            borderFg = COLOR_YELLOW; borderBg = COLOR_BLACK;
            break;
        case ColorTheme::ROYAL:
            lightBg = COLOR_MAGENTA; darkBg = COLOR_BLACK;
            borderFg = COLOR_MAGENTA; borderBg = COLOR_BLACK;
            break;
    }

    // Pair 1: general text
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    // Pair 3: cursor / selection highlight (inverted)
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    // Pair 4: borders, messages
    init_pair(4, borderFg, borderBg);
    // Pairs 5-8: piece-on-square combinations
    // 5: white piece on light square  -> dark fg on light bg
    init_pair(5, COLOR_BLACK, lightBg);
    // 6: white piece on dark square   -> light fg on dark bg
    init_pair(6, COLOR_WHITE, darkBg);
    // 7: black piece on light square  -> dark fg on light bg
    init_pair(7, COLOR_BLACK, lightBg);
    // 8: black piece on dark square   -> light fg on dark bg
    init_pair(8, COLOR_WHITE, darkBg);
}

void Display::setTheme(ColorTheme t) {
    if (has_colors()) {
        applyTheme(t);
    } else {
        theme = t;
    }
}

ColorTheme Display::selectColorTheme() {
    struct ThemeOption {
        ColorTheme value;
        const char* name;
        const char* description;
    };
    const ThemeOption options[] = {
        { ColorTheme::CLASSIC, "Classic", "Timeless white & black" },
        { ColorTheme::FOREST,  "Forest",  "Cool green & black"     },
        { ColorTheme::OCEAN,   "Ocean",   "Cyan & deep blue"       },
        { ColorTheme::SUNSET,  "Sunset",  "Warm yellow & red"      },
        { ColorTheme::ROYAL,   "Royal",   "Regal magenta & black"  },
    };
    const int numOptions = static_cast<int>(sizeof(options) / sizeof(options[0]));

    int selected = 0;
    while (true) {
        // Clear the inside of the window before drawing the menu.
        werase(gameWindow);
        box(gameWindow, 0, 0);
        if (has_colors()) {
            wattron(gameWindow, COLOR_PAIR(4) | A_BOLD);
        }
        mvwprintw(gameWindow, 0, 2, "[ \u265F Chess Lab - Classic Edition \u265F ]");
        if (has_colors()) {
            wattroff(gameWindow, COLOR_PAIR(4) | A_BOLD);
        }

        mvwprintw(gameWindow, 2, 4, "Choose a board color theme:");
        mvwprintw(gameWindow, 3, 4, "Use UP/DOWN arrows, ENTER to confirm.");

        for (int i = 0; i < numOptions; ++i) {
            int row = 5 + i;
            if (i == selected) {
                if (has_colors()) {
                    wattron(gameWindow, COLOR_PAIR(3) | A_BOLD);
                }
                mvwprintw(gameWindow, row, 6, "> %-10s - %s", options[i].name, options[i].description);
                if (has_colors()) {
                    wattroff(gameWindow, COLOR_PAIR(3) | A_BOLD);
                }
            } else {
                mvwprintw(gameWindow, row, 6, "  %-10s - %s", options[i].name, options[i].description);
            }
        }

        wrefresh(gameWindow);

        int ch = wgetch(gameWindow);
        switch (ch) {
            case KEY_UP:
                selected = (selected - 1 + numOptions) % numOptions;
                break;
            case KEY_DOWN:
                selected = (selected + 1) % numOptions;
                break;
            case '\n':
            case '\r':
            case KEY_ENTER:
            case ' ': {
                ColorTheme chosen = options[selected].value;
                setTheme(chosen);
                werase(gameWindow);
                box(gameWindow, 0, 0);
                if (has_colors()) {
                    wattron(gameWindow, COLOR_PAIR(4) | A_BOLD);
                }
                mvwprintw(gameWindow, 0, 2, "[ \u265F Chess Lab - Classic Edition \u265F ]");
                if (has_colors()) {
                    wattroff(gameWindow, COLOR_PAIR(4) | A_BOLD);
                }
                wrefresh(gameWindow);
                return chosen;
            }
            default:
                break;
        }
    }
}
