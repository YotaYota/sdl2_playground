#include "render_system.h"


RenderSystem::RenderSystem()
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::render(SDL_Renderer &renderer, const RigidBodyComponent &rigidBody)
{
    // Background
    SDL_SetRenderDrawColor(&renderer, 150, 111, 214, 200);
    SDL_RenderClear(&renderer);

    // Render Component
    SDL_SetRenderDrawColor(&renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(&renderer, &rigidBody.rect);
    SDL_RenderDrawRect(&renderer, &rigidBody.rect);

    // Present
    SDL_RenderPresent(&renderer);
}

