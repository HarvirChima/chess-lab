#ifndef DISPLAY_H
#define DISPLAY_H

#include "Board.h"
#include <ncurses.h>
#include <string>

class Display {
private:
    WINDOW* gameWindow;
    int startRow;
    int startCol;
    
public:
    Display();
    ~Display();
    
    void initialize();
    void cleanup();
    
    void drawBoard(const Board& board);
    void drawPiece(int row, int col, const Piece& piece, bool highlight = false);
    void drawMessage(const std::string& message);
    void drawStatus(const std::string& status);
    
    void highlightSquare(int row, int col);
    void clearHighlight(int row, int col);
    
    void refresh();
};

#endif
