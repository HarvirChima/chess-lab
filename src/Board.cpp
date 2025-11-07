#include "Board.h"
#include <cmath>

Board::Board() {
    initialize();
}

void Board::initialize() {
    // Clear the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = Piece();
        }
    }
    
    // Set up black pieces (top of board)
    board[0][0] = Piece(PieceType::ROOK, PieceColor::BLACK);
    board[0][1] = Piece(PieceType::KNIGHT, PieceColor::BLACK);
    board[0][2] = Piece(PieceType::BISHOP, PieceColor::BLACK);
    board[0][3] = Piece(PieceType::QUEEN, PieceColor::BLACK);
    board[0][4] = Piece(PieceType::KING, PieceColor::BLACK);
    board[0][5] = Piece(PieceType::BISHOP, PieceColor::BLACK);
    board[0][6] = Piece(PieceType::KNIGHT, PieceColor::BLACK);
    board[0][7] = Piece(PieceType::ROOK, PieceColor::BLACK);
    
    for (int i = 0; i < 8; i++) {
        board[1][i] = Piece(PieceType::PAWN, PieceColor::BLACK);
    }
    
    // Set up white pieces (bottom of board)
    board[7][0] = Piece(PieceType::ROOK, PieceColor::WHITE);
    board[7][1] = Piece(PieceType::KNIGHT, PieceColor::WHITE);
    board[7][2] = Piece(PieceType::BISHOP, PieceColor::WHITE);
    board[7][3] = Piece(PieceType::QUEEN, PieceColor::WHITE);
    board[7][4] = Piece(PieceType::KING, PieceColor::WHITE);
    board[7][5] = Piece(PieceType::BISHOP, PieceColor::WHITE);
    board[7][6] = Piece(PieceType::KNIGHT, PieceColor::WHITE);
    board[7][7] = Piece(PieceType::ROOK, PieceColor::WHITE);
    
    for (int i = 0; i < 8; i++) {
        board[6][i] = Piece(PieceType::PAWN, PieceColor::WHITE);
    }
}

Piece Board::getPiece(int row, int col) const {
    if (!isValidPosition(row, col)) {
        return Piece();
    }
    return board[row][col];
}

void Board::setPiece(int row, int col, const Piece& piece) {
    if (isValidPosition(row, col)) {
        board[row][col] = piece;
    }
}

bool Board::isValidPosition(int row, int col) const {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

bool Board::isPathClear(int fromRow, int fromCol, int toRow, int toCol) const {
    int rowDir = (toRow > fromRow) ? 1 : (toRow < fromRow) ? -1 : 0;
    int colDir = (toCol > fromCol) ? 1 : (toCol < fromCol) ? -1 : 0;
    
    int currentRow = fromRow + rowDir;
    int currentCol = fromCol + colDir;
    
    while (currentRow != toRow || currentCol != toCol) {
        if (!board[currentRow][currentCol].isEmpty()) {
            return false;
        }
        currentRow += rowDir;
        currentCol += colDir;
    }
    
    return true;
}

bool Board::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
    if (!isValidPosition(fromRow, fromCol) || !isValidPosition(toRow, toCol)) {
        return false;
    }
    
    if (fromRow == toRow && fromCol == toCol) {
        return false;
    }
    
    Piece piece = board[fromRow][fromCol];
    if (piece.isEmpty()) {
        return false;
    }
    
    Piece targetPiece = board[toRow][toCol];
    if (!targetPiece.isEmpty() && targetPiece.getColor() == piece.getColor()) {
        return false;
    }
    
    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;
    int absRowDiff = std::abs(rowDiff);
    int absColDiff = std::abs(colDiff);
    
    switch (piece.getType()) {
        case PieceType::PAWN: {
            int direction = (piece.getColor() == PieceColor::WHITE) ? -1 : 1;
            
            // Forward move
            if (colDiff == 0 && rowDiff == direction && targetPiece.isEmpty()) {
                return true;
            }
            
            // Initial two square move
            if (colDiff == 0 && rowDiff == 2 * direction && !piece.getHasMoved() && targetPiece.isEmpty()) {
                int middleRow = fromRow + direction;
                if (board[middleRow][fromCol].isEmpty()) {
                    return true;
                }
            }
            
            // Capture
            if (absColDiff == 1 && rowDiff == direction && !targetPiece.isEmpty()) {
                return true;
            }
            
            return false;
        }
        
        case PieceType::ROOK:
            if (rowDiff == 0 || colDiff == 0) {
                return isPathClear(fromRow, fromCol, toRow, toCol);
            }
            return false;
        
        case PieceType::KNIGHT:
            return (absRowDiff == 2 && absColDiff == 1) || (absRowDiff == 1 && absColDiff == 2);
        
        case PieceType::BISHOP:
            if (absRowDiff == absColDiff) {
                return isPathClear(fromRow, fromCol, toRow, toCol);
            }
            return false;
        
        case PieceType::QUEEN:
            if (rowDiff == 0 || colDiff == 0 || absRowDiff == absColDiff) {
                return isPathClear(fromRow, fromCol, toRow, toCol);
            }
            return false;
        
        case PieceType::KING:
            return absRowDiff <= 1 && absColDiff <= 1;
        
        default:
            return false;
    }
}

bool Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    if (!isValidMove(fromRow, fromCol, toRow, toCol)) {
        return false;
    }
    
    Piece piece = board[fromRow][fromCol];
    piece.setHasMoved(true);
    
    board[toRow][toCol] = piece;
    board[fromRow][fromCol] = Piece();
    
    return true;
}

bool Board::isKingInCheck(PieceColor color) const {
    // Find the king
    int kingRow = -1, kingCol = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece piece = board[i][j];
            if (piece.getType() == PieceType::KING && piece.getColor() == color) {
                kingRow = i;
                kingCol = j;
                break;
            }
        }
        if (kingRow != -1) break;
    }
    
    if (kingRow == -1) return false;
    
    // Check if any opponent piece can attack the king
    PieceColor opponentColor = (color == PieceColor::WHITE) ? PieceColor::BLACK : PieceColor::WHITE;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece piece = board[i][j];
            if (!piece.isEmpty() && piece.getColor() == opponentColor) {
                if (isValidMove(i, j, kingRow, kingCol)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

std::vector<std::pair<int, int>> Board::getValidMoves(int row, int col) const {
    std::vector<std::pair<int, int>> moves;
    
    if (!isValidPosition(row, col)) {
        return moves;
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (isValidMove(row, col, i, j)) {
                moves.push_back({i, j});
            }
        }
    }
    
    return moves;
}
