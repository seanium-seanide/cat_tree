#include "Player.hpp"
#include <SDL2/SDL.h>

Player::Player(
    RenderUtils *renderUtils, 
    std::string fileName, 
    int width, 
    int height
)
: Entity::Entity(renderUtils, fileName, width, height) { 
}

Player::~Player() {
}

void Player::input(SDL_Event *event) {
}

void Player::update() {
}

void Player::render() {
    Entity::render();
}
