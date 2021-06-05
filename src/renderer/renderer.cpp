#include "renderer.h"


Renderer::Renderer(SDL_Window* window, int index, Uint32 flags)
    : renderer(SDL_CreateRenderer(window, index, flags))
{
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
}

SDL_Renderer* Renderer::raw()
{
    return renderer;
}

