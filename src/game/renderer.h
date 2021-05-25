#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>


class Renderer
{
    private:
        SDL_Renderer* renderer;

    public:
        Renderer(const Renderer&) = delete;
        Renderer& operator=(const Renderer&) = delete;

        Renderer(SDL_Window* window, int index, Uint32 flags);
        virtual ~Renderer();

        SDL_Renderer* raw();
};

#endif /* RENDERER_H */

