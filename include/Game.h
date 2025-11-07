#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Display.h"
#include <string>

class Game {
private:
    Board board;
    Display display;
    PieceColor currentPlayer;
    bool gameRunning;
    
    int selectedRow;
    int selectedCol;
    bool pieceSelected;
    
public:
    Game();
    
    void start();
    void processInput();
    void update();
    void render();
    
    void selectSquare(int row, int col);
    void moveSelectedPiece(int toRow, int toCol);
    void switchPlayer();
    
    bool isGameOver() const;
    std::string getCurrentPlayerName() const;
};

#endif
