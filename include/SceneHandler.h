#pragma once

#include <iostream>

#include "Particle.h"
#include "SDL.h"

#define PARTICLE_COUNT  1000
#define SPAWN_STEPS     10
#define PARTICLE_RADIUS 10
#define SUB_STEPS       8

class SceneHandler
{
private:

    SDL_Window*   window;
    SDL_Renderer* renderer;

    int width;
    int height;

    bool running = true;

    Particle** particles;

public:

    SceneHandler(int width, int height);
    ~SceneHandler();

    int  Init();
    void Start();
    void Update();

    Particle** GetParticles() { return this->particles; }
    int        GetWidth() { return this->width; }
    int        GetHeight() { return this->height; }
};