#ifndef OBJECT_H
#define OBJECT_H

#include "point.h"

#include <SDL2/SDL.h>

#include <memory>


class GameObject
{
    protected:
        std::unique_ptr<SDL_Rect> rect;
        std::unique_ptr<Point> position;

    public:
        GameObject(GameObject&) = delete;
        GameObject& operator=(GameObject&) = delete;

        GameObject();
        GameObject(const int width, const int height, int x, int y);
        virtual ~GameObject();

        virtual void render(SDL_Renderer &renderer) = 0;
        //virtual void update() = 0;
        SDL_Rect* getRect();
};

#endif /* OBJECT_H */

