#include "Entity.hpp"
#include <string>
#include "RenderUtils.hpp"
#include <SDL2/SDL.h>

Entity::Entity(
    RenderUtils *renderUtils, 
    std::string fileName, 
    int width, 
    int height
)
: m_pRenderUtils(renderUtils), 
  m_x(0), m_y(0), 
  m_xVelocity(0), m_yVelocity(0), 
  m_width(width), m_height(height) {
    m_pTexture = renderUtils->loadTexture(fileName);
}

Entity::~Entity() {
    SDL_DestroyTexture(m_pTexture);
}

void Entity::input(SDL_Event *event) {
}

void Entity::update() {
}

void Entity::render() {
    m_pRenderUtils->render(m_pTexture, m_x, m_y, m_width, m_height);
}
