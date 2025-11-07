#include "Piece.h"

Piece::Piece() : type(PieceType::NONE), color(PieceColor::NONE), hasMoved(false) {}

Piece::Piece(PieceType type, PieceColor color) 
    : type(type), color(color), hasMoved(false) {}

PieceType Piece::getType() const {
    return type;
}

PieceColor Piece::getColor() const {
    return color;
}

bool Piece::getHasMoved() const {
    return hasMoved;
}

void Piece::setHasMoved(bool moved) {
    hasMoved = moved;
}

char Piece::getSymbol() const {
    if (isEmpty()) return ' ';
    
    char symbol;
    switch (type) {
        case PieceType::PAWN:   symbol = 'P'; break;
        case PieceType::ROOK:   symbol = 'R'; break;
        case PieceType::KNIGHT: symbol = 'N'; break;
        case PieceType::BISHOP: symbol = 'B'; break;
        case PieceType::QUEEN:  symbol = 'Q'; break;
        case PieceType::KING:   symbol = 'K'; break;
        default:                symbol = ' '; break;
    }
    
    // Lowercase for black pieces
    if (color == PieceColor::BLACK) {
        symbol = tolower(symbol);
    }
    
    return symbol;
}

std::string Piece::getUnicodeSymbol() const {
    if (isEmpty()) return " ";
    
    if (color == PieceColor::WHITE) {
        switch (type) {
            case PieceType::KING:   return "♔";
            case PieceType::QUEEN:  return "♕";
            case PieceType::ROOK:   return "♖";
            case PieceType::BISHOP: return "♗";
            case PieceType::KNIGHT: return "♘";
            case PieceType::PAWN:   return "♙";
            default:                return " ";
        }
    } else {
        switch (type) {
            case PieceType::KING:   return "♚";
            case PieceType::QUEEN:  return "♛";
            case PieceType::ROOK:   return "♜";
            case PieceType::BISHOP: return "♝";
            case PieceType::KNIGHT: return "♞";
            case PieceType::PAWN:   return "♟";
            default:                return " ";
        }
    }
}

std::string Piece::getName() const {
    if (isEmpty()) return "Empty";
    
    std::string colorName = (color == PieceColor::WHITE) ? "White" : "Black";
    std::string typeName;
    
    switch (type) {
        case PieceType::PAWN:   typeName = "Pawn"; break;
        case PieceType::ROOK:   typeName = "Rook"; break;
        case PieceType::KNIGHT: typeName = "Knight"; break;
        case PieceType::BISHOP: typeName = "Bishop"; break;
        case PieceType::QUEEN:  typeName = "Queen"; break;
        case PieceType::KING:   typeName = "King"; break;
        default:                typeName = "Unknown"; break;
    }
    
    return colorName + " " + typeName;
}

bool Piece::isEmpty() const {
    return type == PieceType::NONE;
}
