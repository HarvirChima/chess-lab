#include "Board.h"
#include "Piece.h"
#include <iostream>
#include <iomanip>

void printBoard(const Board& board) {
    std::cout << "\nChess Board - Beautiful Edition:\n" << std::endl;
    std::cout << "    ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗\n";
    std::cout << "      a   b   c   d   e   f   g   h\n";
    
    for (int row = 0; row < 8; row++) {
        std::cout << " " << (8 - row) << "  ║";
        
        for (int col = 0; col < 8; col++) {
            Piece piece = board.getPiece(row, col);
            if (piece.isEmpty()) {
                bool isDark = (row + col) % 2 == 1;
                std::cout << (isDark ? " ░ " : "   ");
            } else {
                std::cout << " " << piece.getUnicodeSymbol() << " ";
            }
            std::cout << "║";
        }
        
        std::cout << " " << (8 - row) << "\n";
        
        if (row < 7) {
            std::cout << "    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n";
        }
    }
    
    std::cout << "    ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝\n";
    std::cout << "      a   b   c   d   e   f   g   h\n";
    std::cout << "\nLegend:\n";
    std::cout << "  White pieces: ♔ ♕ ♖ ♗ ♘ ♙ (King, Queen, Rook, Bishop, Knight, Pawn)\n";
    std::cout << "  Black pieces: ♚ ♛ ♜ ♝ ♞ ♟ (King, Queen, Rook, Bishop, Knight, Pawn)\n";
    std::cout << "  Dark squares: ░\n";
}

int main() {
    Board board;
    printBoard(board);
    
    std::cout << "\n\nExample moves:\n";
    std::cout << "1. e2-e4 (White pawn opens with King's pawn)\n";
    board.movePiece(6, 4, 4, 4);
    
    std::cout << "2. e7-e5 (Black responds with King's pawn)\n";
    board.movePiece(1, 4, 3, 4);
    
    std::cout << "3. Nf3 (White develops knight)\n";
    board.movePiece(7, 6, 5, 5);
    
    printBoard(board);
    
    return 0;
}
