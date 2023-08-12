/// ############################################################################
///
/// @author Alexander Niedermayer
/// @date 2023-08-12
///
/// ############################################################################

// Include files
/// ############################################################################

#include "SceneHandler.h"
#include "Vec.h"

#include "Particle.h"

// Defines
/// ############################################################################

#define BOUNCE_FACTOR 0.5f

// Constructor
/// ############################################################################

Particle::Particle(float x, float y, int radius, SDL_Color color, float xVel, float yVel)
{
    this->color  = color;
    this->pos    = new Vec(x, y);
    this->vel    = new Vec(xVel, yVel);
    this->radius = radius;
}

Particle::~Particle()
{
    delete this->pos;
    delete this->vel;
}

// Functions and Procedures
/// ############################################################################

void Particle::Update(SceneHandler* sceneHandler)
{
    Vec& m_Pos = *this->pos;
    Vec& m_Vel = *this->vel;

    // Cancel velocity if it's too small
    if (abs(m_Vel.GetX()) <= 0.1 / (float) SUB_STEPS)
    {
        m_Vel.SetX(0);
    }

    if (abs(m_Vel.GetY()) <= 0.1 / (float) SUB_STEPS)
    {
        m_Vel.SetY(0);
    }

    // Update position in sub-steps
    m_Pos += m_Vel / (float) SUB_STEPS;
    m_Vel += Vec(0, (float) GRAVITY / (float) SUB_STEPS);

    int x = (int) m_Pos.GetX();
    int y = (int) m_Pos.GetY();
    int r = this->radius;

    int screenWidth = sceneHandler->GetWidth();
    int screenHeight = sceneHandler->GetHeight();

    // Bounce off walls
    if (x + r >= screenWidth || x - r <= 0)
    {
        m_Vel *= Vec(-0.1f, 1);
        
        if (x + r >= screenWidth)
        {
            m_Pos.SetX((float) (screenWidth - r));
        }
        else if (x - r <= 0)
        {
            m_Pos.SetX((float) r+1);
        }

    }

    if (y + r >= screenHeight || y - r <= 0)
    {
        m_Vel *= Vec(1, -0.5f);

        if (y + r >= screenHeight)
        {
            m_Pos.SetY((float) (screenHeight - r));
        }
        else if (y - r <= 0)
        {
            m_Pos.SetY((float) r+1);
        }
    }

    Particle** particles = sceneHandler->GetParticles();

    // Check for collisions with other particles
    for (int i = 0; i < PARTICLE_COUNT; i++)
    {
        if (particles[i] != this && particles[i] != nullptr)
        {
            if (this->CollidesWith(particles[i]))
            {
                this->ResolvesCollision(particles[i]);
            }
        }
    }

}

void Particle::Draw(SDL_Renderer* renderer, SceneHandler* sceneHandler)
{
    SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, this->color.a);

    // Draw circle
    for (int i = 0; i < this->radius; i++)
    {
        for (int j = 0; j < this->radius; j++)
        {
            if (i * i + j * j <= this->radius * this->radius)
            {
                int cx = (int) (this->pos->GetX() + i);
                int cy = (int) (this->pos->GetY() + j);
                int nx = (int) (this->pos->GetX() - i);
                int ny = (int) (this->pos->GetY() - j);

                SDL_RenderDrawPoint(renderer, cx, cy);
                SDL_RenderDrawPoint(renderer, nx, cy);
                SDL_RenderDrawPoint(renderer, cx, ny);
                SDL_RenderDrawPoint(renderer, nx, ny);
            }
        }
    }
}

bool Particle::CollidesWith(Particle* particle)
{
    float dist = (*this->pos - *particle->pos).Length();
    return dist <= this->radius + particle->radius;
}

void Particle::ResolvesCollision(Particle* particle)
{
    Vec& m_Pos = *this->pos;
    Vec& m_Vel = *this->vel;

    Vec& p_Pos = *particle->pos;
    Vec& p_Vel = *particle->vel;

    float d = (m_Pos - p_Pos).Length(); 
    Vec normal = (m_Pos - p_Pos) / d;

    m_Vel.SetX(m_Vel.GetX() + normal.GetX() / 8);
    m_Vel.SetY(m_Vel.GetY() + normal.GetY() / 8);

    p_Vel.SetX(p_Vel.GetX() - normal.GetX() / 8);
    p_Vel.SetY(p_Vel.GetY() - normal.GetY() / 8);

}