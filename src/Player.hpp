#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include <SDL2/SDL.h>

class Player : public Entity {
    public:
        Player(
            RenderUtils *renderUtils, 
            std::string fileName, 
            int width, 
            int height
        );
        Player();
        ~Player();

        void input(SDL_Event *event);
        void update();
        void render();

    private:
};

#endif
