#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>

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
};

#endif