#include "Board.h"
#include "Piece.h"
#include <iostream>
#include <cassert>

void testPieceCreation() {
    Piece whitePawn(PieceType::PAWN, PieceColor::WHITE);
    assert(whitePawn.getType() == PieceType::PAWN);
    assert(whitePawn.getColor() == PieceColor::WHITE);
    assert(whitePawn.getSymbol() == 'P');
    assert(!whitePawn.isEmpty());
    std::cout << "✓ Piece creation test passed" << std::endl;
}

void testBoardInitialization() {
    Board board;
    
    // Check white pieces
    assert(board.getPiece(7, 0).getType() == PieceType::ROOK);
    assert(board.getPiece(7, 0).getColor() == PieceColor::WHITE);
    assert(board.getPiece(7, 4).getType() == PieceType::KING);
    assert(board.getPiece(6, 0).getType() == PieceType::PAWN);
    
    // Check black pieces
    assert(board.getPiece(0, 0).getType() == PieceType::ROOK);
    assert(board.getPiece(0, 0).getColor() == PieceColor::BLACK);
    assert(board.getPiece(0, 4).getType() == PieceType::KING);
    assert(board.getPiece(1, 0).getType() == PieceType::PAWN);
    
    // Check empty squares
    assert(board.getPiece(3, 3).isEmpty());
    assert(board.getPiece(4, 4).isEmpty());
    
    std::cout << "✓ Board initialization test passed" << std::endl;
}

void testPawnMovement() {
    Board board;
    
    // Test white pawn initial move (2 squares)
    assert(board.movePiece(6, 4, 4, 4) == true);
    assert(board.getPiece(4, 4).getType() == PieceType::PAWN);
    assert(board.getPiece(6, 4).isEmpty());
    
    // Test black pawn initial move (2 squares) - different column
    assert(board.movePiece(1, 3, 3, 3) == true);
    assert(board.getPiece(3, 3).getType() == PieceType::PAWN);
    
    // Test white pawn single move
    assert(board.movePiece(4, 4, 3, 4) == true);
    
    std::cout << "✓ Pawn movement test passed" << std::endl;
}

void testKnightMovement() {
    Board board;
    
    // Test white knight move
    assert(board.movePiece(7, 1, 5, 2) == true);
    assert(board.getPiece(5, 2).getType() == PieceType::KNIGHT);
    assert(board.getPiece(7, 1).isEmpty());
    
    // Test black knight move
    assert(board.movePiece(0, 1, 2, 2) == true);
    assert(board.getPiece(2, 2).getType() == PieceType::KNIGHT);
    
    std::cout << "✓ Knight movement test passed" << std::endl;
}

void testInvalidMoves() {
    Board board;
    
    // Try to move to same position
    assert(board.movePiece(6, 4, 6, 4) == false);
    
    // Try to move rook without clear path
    assert(board.movePiece(7, 0, 5, 0) == false);
    
    // Try to capture own piece
    assert(board.movePiece(7, 0, 6, 0) == false);
    
    std::cout << "✓ Invalid move test passed" << std::endl;
}

void testCapture() {
    Board board;
    
    // Move white pawn forward two squares (e2 to e4)
    board.movePiece(6, 4, 4, 4);
    // Move black pawn forward two squares (d7 to d5)  
    board.movePiece(1, 3, 3, 3);
    
    // Now white pawn at e4 (row 4, col 4) can capture black pawn at d5 (row 3, col 3)
    bool captured = board.movePiece(4, 4, 3, 3);
    assert(captured == true);
    assert(board.getPiece(3, 3).getColor() == PieceColor::WHITE);
    assert(board.getPiece(3, 3).getType() == PieceType::PAWN);
    assert(board.getPiece(4, 4).isEmpty());
    
    std::cout << "✓ Capture test passed" << std::endl;
}

int main() {
    std::cout << "Running Chess Lab Tests..." << std::endl;
    std::cout << "=========================" << std::endl;
    
    try {
        testPieceCreation();
        testBoardInitialization();
        testPawnMovement();
        testKnightMovement();
        testInvalidMoves();
        testCapture();
        
        std::cout << "=========================" << std::endl;
        std::cout << "All tests passed! ✓" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
}
