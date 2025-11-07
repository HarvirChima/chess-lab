#include "Game.h"
#include <iostream>

int main() {
    try {
        Game game;
        game.start();
        
        std::cout << "Thanks for playing Chess Lab!" << std::endl;
        std::cout << "This demo is designed for GitHub Copilot workshops." << std::endl;
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
