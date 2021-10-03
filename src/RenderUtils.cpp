#include "RenderUtils.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>

using std::cerr;
using std::endl;

RenderUtils::RenderUtils()
: m_pRenderer(nullptr) {
}

RenderUtils::~RenderUtils() {
}

void RenderUtils::init(SDL_Renderer *pRenderer) {
    m_pRenderer = pRenderer;
}

void RenderUtils::render(
    SDL_Texture *pTexture,
    int x,
    int y,
    int width,
    int height
) {
    SDL_Rect sourceRect = {0, 0, width, height};
    SDL_Rect destinationRect = {x, y, width, height};
    SDL_RenderCopy(m_pRenderer, pTexture, &sourceRect, &destinationRect);
}

SDL_Texture *RenderUtils::loadTexture(std::string filename) {
    SDL_Surface *pSurface = IMG_Load(filename.c_str());
    if (pSurface == nullptr) {
        cerr << "Failed to load surface: " << SDL_GetError() << endl;
        exit(1);
    }

    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pSurface);
    if (pTexture == nullptr) {
        cerr << "Failed to load texture: " << SDL_GetError() << endl;
        exit(1);
    }

    SDL_FreeSurface(pSurface);
    
    return pTexture;
}

void RenderUtils::renderFrame(
    SDL_Texture *pTexture,
    int sourceX,
    int sourceY,
    int width,
    int height,
    int destinationX,
    int destinationY
) {
    SDL_Rect sourceRect = {sourceX, sourceY, width, height};
    SDL_Rect destinationRect = {destinationX, destinationY, width, height};
    SDL_RenderCopy(m_pRenderer, pTexture, &sourceRect, &destinationRect);
}
