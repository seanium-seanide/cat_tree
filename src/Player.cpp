#include "Player.hpp"
#include <SDL2/SDL.h>

Player::Player(
    RenderUtils *renderUtils, 
    std::string fileName, 
    int width, 
    int height
)
: Entity::Entity(renderUtils, fileName, width, height), m_frame(0),
  m_textureRow(0) { 
}

Player::~Player() {
}

void Player::input(SDL_Event *event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_a:
                    moveLeft();
                    break;

                case SDLK_LEFT:
                    moveLeft();
                    break;

                default:
                    break;
            }

        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_a:
                    stopLeft();
                    break;

                case SDLK_LEFT:
                    stopLeft();
                    break;

                default:
                    break;
            }

        default:
            break;
    }
}

void Player::moveLeft() {
    m_xVel = -MOVE_VELOCITY;
    m_textureRow = 1;
}

void Player::stopLeft() {
    m_xVel = 0;
}

void Player::update() {
    m_x += m_xVel;
    m_y += m_yVel;

    m_frame = (SDL_GetTicks() % 8.0)/100;
}

void Player::render() {
    Entity::render();
}

void Player::drawFrame() {

}
