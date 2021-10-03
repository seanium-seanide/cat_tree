#include "main.hpp"
#include <iostream>
#include "Game.hpp"
#include <SDL2/SDL.h>

int main() {
    Game *game = new Game(); 

    while (game->isRunning()) {
        game->input();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}
