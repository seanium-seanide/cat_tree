#ifndef SPRITE_HPP
#define SPRITE_HPP

class Entity {
    public:
        Entity();
        ~Entity();

        void input();
        void update();
        void render();

    private:
        SDL_Texture *m_pTexture;
        int m_x;
        int m_y;
        int m_xVel;
        int m_yVel;
};

#endif
