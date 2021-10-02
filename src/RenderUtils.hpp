#ifndef RENDERUTILS_HPP
#define RENDERUTILS_HPP

#include <SDL2/SDL.h>
#include <string>

class RenderUtils {
    public:
        RenderUtils();
        ~RenderUtils();

        void init(SDL_Renderer *pRenderer);

        SDL_Texture *loadTexture(std::string filename);

        void render(
            SDL_Texture *pTexture,
            int x,
            int y,
            int width,
            int height
        );

    private:
        SDL_Renderer *m_pRenderer;
};

#endif
