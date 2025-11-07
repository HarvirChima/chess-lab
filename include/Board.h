#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>
#include <string>

class Board {
private:
    Piece board[8][8];
    
public:
    Board();
    
    void initialize();
    Piece getPiece(int row, int col) const;
    void setPiece(int row, int col, const Piece& piece);
    
    bool isValidPosition(int row, int col) const;
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const;
    bool movePiece(int fromRow, int fromCol, int toRow, int toCol);
    
    bool isPathClear(int fromRow, int fromCol, int toRow, int toCol) const;
    bool isKingInCheck(PieceColor color) const;
    
    std::vector<std::pair<int, int>> getValidMoves(int row, int col) const;
};

#endif
