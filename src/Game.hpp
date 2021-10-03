#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include "RenderUtils.hpp"
#include "Player.hpp"

class Game {
    public:
        Game();
        ~Game();

        SDL_Renderer *getRenderer() { return m_pRenderer; };
        bool isRunning() { return m_running; };

        void init();
        void clean();
        void input();
        void update();
        void render();

    private:
        bool m_running;
        SDL_Window *m_pWindow;
        SDL_Renderer *m_pRenderer;

        // Timing
        double m_lastFrameTime;

        // Temporary texture
        SDL_Texture *m_pCat;

        // Utilities
        RenderUtils m_renderUtils;

        // Entities
        Player *m_pCatEntity;
};

#endif
