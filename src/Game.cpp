#include "Game.h"
#include <sstream>

Game::Game() 
    : currentPlayer(PieceColor::WHITE), 
      gameRunning(false),
      selectedRow(-1),
      selectedCol(-1),
      pieceSelected(false) {}

void Game::start() {
    board.initialize();
    display.initialize();
    gameRunning = true;
    
    display.drawBoard(board);
    display.drawStatus("Use arrow keys to move, SPACE to select/move, Q to quit");
    display.drawMessage("White's turn");
    display.refresh();
    
    // Game loop
    int cursorRow = 6;  // Start at white pawn row
    int cursorCol = 4;  // Start at middle column
    
    while (gameRunning) {
        // Draw current cursor position
        display.drawBoard(board);
        
        if (pieceSelected) {
            display.highlightSquare(selectedRow, selectedCol);
            Piece selectedPiece = board.getPiece(selectedRow, selectedCol);
            std::ostringstream oss;
            oss << "Selected: " << selectedPiece.getName() 
                << " at " << (char)('a' + selectedCol) << (8 - selectedRow);
            display.drawMessage(oss.str());
        } else {
            display.drawMessage(getCurrentPlayerName() + "'s turn - Select a piece");
        }
        
        // Highlight cursor
        display.highlightSquare(cursorRow, cursorCol);
        display.refresh();
        
        // Get input
        int ch = getch();
        
        // Clear cursor highlight
        display.clearHighlight(cursorRow, cursorCol);
        
        switch (ch) {
            case KEY_UP:
                if (cursorRow > 0) cursorRow--;
                break;
            case KEY_DOWN:
                if (cursorRow < 7) cursorRow++;
                break;
            case KEY_LEFT:
                if (cursorCol > 0) cursorCol--;
                break;
            case KEY_RIGHT:
                if (cursorCol < 7) cursorCol++;
                break;
            case ' ':  // Space key
                if (!pieceSelected) {
                    selectSquare(cursorRow, cursorCol);
                } else {
                    moveSelectedPiece(cursorRow, cursorCol);
                }
                break;
            case 'q':
            case 'Q':
                gameRunning = false;
                break;
        }
    }
    
    display.cleanup();
}

void Game::selectSquare(int row, int col) {
    Piece piece = board.getPiece(row, col);
    
    if (piece.isEmpty()) {
        display.drawMessage("No piece at this position");
        return;
    }
    
    if (piece.getColor() != currentPlayer) {
        display.drawMessage("That's not your piece!");
        return;
    }
    
    selectedRow = row;
    selectedCol = col;
    pieceSelected = true;
}

void Game::moveSelectedPiece(int toRow, int toCol) {
    if (!pieceSelected) {
        return;
    }
    
    // Check if clicking the same square (deselect)
    if (toRow == selectedRow && toCol == selectedCol) {
        pieceSelected = false;
        display.drawMessage(getCurrentPlayerName() + "'s turn - Select a piece");
        return;
    }
    
    // Try to move
    if (board.movePiece(selectedRow, selectedCol, toRow, toCol)) {
        pieceSelected = false;
        switchPlayer();
        
        std::ostringstream oss;
        oss << "Moved from " << (char)('a' + selectedCol) << (8 - selectedRow)
            << " to " << (char)('a' + toCol) << (8 - toRow);
        display.drawMessage(oss.str());
    } else {
        display.drawMessage("Invalid move! Try again.");
    }
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == PieceColor::WHITE) ? PieceColor::BLACK : PieceColor::WHITE;
}

std::string Game::getCurrentPlayerName() const {
    return (currentPlayer == PieceColor::WHITE) ? "White" : "Black";
}

bool Game::isGameOver() const {
    return !gameRunning;
}

void Game::processInput() {
    // Implemented in the main game loop
}

void Game::update() {
    // Future: Add game logic updates here
}

void Game::render() {
    display.drawBoard(board);
    display.refresh();
}
