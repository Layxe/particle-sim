/// ############################################################################
///
/// @author Alexander Niedermayer
/// @date 2023-08-12
///
/// ############################################################################

#pragma once

// Include files
/// ############################################################################

#include "SDL.h"

// Defines
/// ############################################################################

#define GRAVITY 0.1

// Class
/// ############################################################################

class SceneHandler;
class Vec;

class Particle
{
public:

    /*--------------------------------------------------------------------------------*//**
    \brief Create a new drawable particle
    
    \param[in] x The x position of the particle
    \param[in] y The y position of the particle
    \param[in] radius The radius of the particle
    \param[in] color The color of the particle
    \param[in] xVel The x velocity of the particle
    \param[in] yVel The y velocity of the particle
    
    \return A new particle
    *//*--------------------------------------------------------------------------------*/
    Particle(float x, float y, int radius, SDL_Color color, float xVel, float yVel);
    ~Particle();

    /*--------------------------------------------------------------------------------*//**
    \brief Draw the particle
    
    \param[in] renderer The renderer to draw to
    \param[in] sceneHandler The scene handler
    
    \return None
    *//*--------------------------------------------------------------------------------*/
    void Draw(SDL_Renderer* renderer, SceneHandler* sceneHandler);

    /*--------------------------------------------------------------------------------*//**
    \brief Update the particle, for example move it
    
    \param[in] sceneHandler The scene handler
    
    \return None
    *//*--------------------------------------------------------------------------------*/
    void Update(SceneHandler* sceneHandler);

    /*--------------------------------------------------------------------------------*//**
    \brief Check if the particle collides with another particle
    
    \param[in] particle The particle to check against
    
    \return True if the particles collide, false otherwise
    *//*--------------------------------------------------------------------------------*/
    bool CollidesWith(Particle* particle);

    /*--------------------------------------------------------------------------------*//**
    \brief Resolve the collision between this particle and another particle
    
    \param[in] particle The particle to resolve the collision with
    
    \return None
    *//*--------------------------------------------------------------------------------*/
    void ResolvesCollision(Particle* particle);

private:
    SDL_Color color;
    Vec *pos;
    Vec *vel;
    int radius;
};