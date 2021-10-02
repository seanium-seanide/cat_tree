#include "Game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include <iostream>
#include "main.hpp"

using std::cerr;
using std::endl;

Game::Game()
: m_pWindow(nullptr), m_pRenderer(nullptr), m_running(false), m_lastFrameTime(0) {
}

Game::~Game() {
}

void Game::init() {
    // Initialise SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        // Explain cerr (flush output buffer)
        cerr << "Failed to initialize SDL: " << SDL_GetError() << endl;
        exit(1);
    }
    
    // Create a window
    m_pWindow = SDL_CreateWindow(
        WIN_TITLE.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIN_WIDTH,
        WIN_HEIGHT,
        WIN_FLAGS
    );
    if (m_pWindow == nullptr) {
        cerr << "Failed to open window: " << SDL_GetError() << endl;
        exit(1);
    }
    
    // Create a renderer
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (m_pRenderer == nullptr) {
        cerr << "Failed to create renderer: " << SDL_GetError() << endl;
        exit(1);
    }
    
    // Start the game
    m_running = true;
}

void Game::clean() {
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::input() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                m_running = false;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        m_running = false;
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void Game::update() {
    double elapsedTime;
    double waitTime;
    double deltaTime;

    // Clamp frame rate
    elapsedTime = SDL_GetTicks() - m_lastFrameTime;
    waitTime = (elapsedTime < FRAME_TIME) ? FRAME_TIME - elapsedTime : 0;
    SDL_Delay(waitTime);
    
    // Get time elapsed since end of last frame
    deltaTime = SDL_GetTicks() - m_lastFrameTime;
    
    // Update game entities
    
    // Timing
    m_lastFrameTime = SDL_GetTicks();
}

void Game::render() {
    // Draw colour is cornflowerblue
    SDL_SetRenderDrawColor(m_pRenderer, 0x64, 0x95, 0xED, 0xFF);

    // Clear the display to cornflowerblue
    SDL_RenderClear(m_pRenderer);
    
    // Flip the back buffer
    SDL_RenderPresent(m_pRenderer);
}
