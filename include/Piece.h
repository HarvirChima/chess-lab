#ifndef PIECE_H
#define PIECE_H

#include <string>

enum class PieceType {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    NONE
};

enum class PieceColor {
    WHITE,
    BLACK,
    NONE
};

class Piece {
private:
    PieceType type;
    PieceColor color;
    bool hasMoved;

public:
    Piece();
    Piece(PieceType type, PieceColor color);
    
    PieceType getType() const;
    PieceColor getColor() const;
    bool getHasMoved() const;
    void setHasMoved(bool moved);
    
    char getSymbol() const;
    std::string getName() const;
    
    bool isEmpty() const;
};

#endif
