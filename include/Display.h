#ifndef DISPLAY_H
#define DISPLAY_H

#include "Board.h"
#include <ncurses.h>
#include <string>

// Selectable board color themes for the game.
enum class ColorTheme {
    CLASSIC,  // White / black (original)
    FOREST,   // Green / black
    OCEAN,    // Cyan / blue
    SUNSET,   // Yellow / red
    ROYAL     // Magenta / black
};

class Display {
private:
    WINDOW* gameWindow;
    int startRow;
    int startCol;
    ColorTheme theme;

    void applyTheme(ColorTheme t);

public:
    Display();
    ~Display();
    
    void initialize();
    void cleanup();

    // Show an interactive menu allowing the user to choose a board
    // color theme. The chosen theme is applied to the display and
    // returned. Must be called after initialize().
    ColorTheme selectColorTheme();
    void setTheme(ColorTheme t);
    ColorTheme getTheme() const { return theme; }
    
    void drawBoard(const Board& board);
    void drawPiece(int row, int col, const Piece& piece, bool highlight = false);
    void drawMessage(const std::string& message);
    void drawStatus(const std::string& status);
    
    void highlightSquare(int row, int col);
    void clearHighlight(int row, int col);
    
    void refresh();
};

#endif
