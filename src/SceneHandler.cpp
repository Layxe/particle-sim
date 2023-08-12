#include "SceneHandler.h"

#include <iostream>

using namespace std;

SceneHandler::SceneHandler(int width, int height)
{
    this->width  = width;
    this->height = height;
}

SceneHandler::~SceneHandler()
{
    for (int i = 0; i < PARTICLE_COUNT; i++)
    {
        delete this->particles[i];
    }

    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

int SceneHandler::Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    /* Create a window */
    this->window = SDL_CreateWindow(
        "Hello Platformer!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, 0
    );
    if (!this->window)
    {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    /* Create a renderer */
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    this->renderer      = SDL_CreateRenderer(this->window, -1, render_flags);
    if (!this->renderer)
    {
        std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(this->window);
        SDL_Quit();
        return 1;
    }

    this->Start();

    return 0;
}

void SceneHandler::Start()
{
    // int framesPerSecond = 0;

    const uint32_t particle_memory = sizeof(Particle) * PARTICLE_COUNT;

    this->particles = (Particle**) malloc(particle_memory);
    memset(this->particles, 0, sizeof(Particle*) * PARTICLE_COUNT);

    // for (int i = 0; i < PARTICLE_COUNT; i++)
    // {
    //     this->particles[i] = (Particle*) 0;
    // }

    SDL_Event event;

    this->particles[0] = new Particle(200, 300, PARTICLE_RADIUS, {255, 255, 255, 255}, 5, 0);
    this->particles[1] = new Particle(600, 300, PARTICLE_RADIUS, {255, 0, 255, 255}, -5, 0);

    while (this->running)
    {
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                this->running = false;
            }

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    this->running = false;
                }
            }
        }

        SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
        SDL_RenderClear(this->renderer);

        this->Update();

        SDL_RenderPresent(this->renderer);
        SDL_Delay(1000 / 60);
    }
}

void SceneHandler::Update()
{
    // static int counter = 0;

    // if (counter % SPAWN_STEPS == 0 && counter < PARTICLE_COUNT * SPAWN_STEPS)
    // {
    //     this->particles[counter] =
    //         new Particle(20, 20, PARTICLE_RADIUS, {255, 255, 255, 255}, (float) ((counter / SPAWN_STEPS) % 10), 0);
    // }

    // counter++;

    for (int j = 0; j < SUB_STEPS; j++)
    {
        for (int i = 0; i < PARTICLE_COUNT; i++)
        {
            if (this->particles[i] != 0)
            {
                this->particles[i]->Update(this);
            }
        }
    }

    for (int i = 0; i < PARTICLE_COUNT; i++)
    {
        if (this->particles[i] != 0)
        {
            this->particles[i]->Draw(this->renderer, this);
        }
    }
}