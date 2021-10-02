#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>
#include <SDL2/SDL.h>

const std::string WIN_TITLE = "Cat Tree";
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;
const Uint32 WIN_FLAGS = SDL_WINDOW_SHOWN;

// Frame rate
const double FRAME_RATE = 60.0;                     // Frame rate (fps)
const double FRAME_TIME = 1.0 / FRAME_RATE * 1000;  // Frame time (ms)

#endif
