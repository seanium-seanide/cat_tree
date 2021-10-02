#include <iostream>
#include "Game.hpp"

int main() {
    Game *game = new Game(); 

    game->init();

    while (game->isRunning()) {
        game->input();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}
