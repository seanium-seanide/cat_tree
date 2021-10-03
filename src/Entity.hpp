#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>
#include "RenderUtils.hpp"

class Entity {
    public:
        Entity(
            RenderUtils *renderUtils, 
            std::string fileName, 
            int width, 
            int height
        );
        ~Entity();

        // Accessors
        void setPosition(int x, int y) {
            m_x = x;
            m_y = y;
        };
        void setVelocity(int x, int y) {
            m_xVelocity = x;
            m_yVelocity = y;
        }
        void setFrameWidth(int width) {
            m_frameWidth = width;
        }
        void setFrameHeight(int height) {
            m_frameHeight = height;
        }

        // Game loop
        virtual void input(SDL_Event *event) = 0;
        virtual void update() = 0;
        virtual void render() = 0;

    protected:
        RenderUtils *m_pRenderUtils;
        SDL_Texture *m_pTexture;
        float m_x;
        float m_y;
        float m_xVelocity;
        float m_yVelocity;
        int m_frameWidth;
        int m_frameHeight;
        int m_width;
        int m_height;
        int m_frame;
        int m_textureRow;
};

#endif
