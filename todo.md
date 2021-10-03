Scott pilgrim sheet dimensions:

sheet: 864 \* 280
4 \* x -> each clip is 108\*140

Todo
====

* Make a rendering function for animated sprite sheets []

    - Render a clip from a sheet []
    - Update frame []


* Get input for player movement []

    - Implement left
    - Implement right
    - Implement up
    - Implement down

* Rendering p

* Direction sensitive movement []

struct rect {
    int x,
    int y,
    int width,
    int height,
};

class Player {
    Texture t;
    float x;
    float y;
    float width;
    float height;
    float frameWidth;
    float frameHeight;
    float xvel;
    float yvel;
    int frame;      // count from zero
    int row;        // count from zero

    // Accessors
    void setFrame(int frame);
    void setPos(float x, float y);
    void setVel(float xVel, float yVel);
    
    // Methods
    drawFrame() {
        // Draw the texture onto the framebuffer
    }      
};
