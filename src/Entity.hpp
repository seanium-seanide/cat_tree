#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>

class Entity {
    public:
        Entity(
            RenderUtils *renderUtils, 
            std::string fileName, 
            int width, 
            int height
        );
        ~Entity();

        void setPosition(int x, int y);
        void setVelocity(int x, int y);
        void input();
        void update();
        void render();

    private:
        RenderUtils *m_pRenderUtils;
        SDL_Texture *m_pTexture;
        int m_x;
        int m_y;
        int m_xVelocity;
        int m_yVelocity;
        int m_width;
        int m_height;
};

#endif
