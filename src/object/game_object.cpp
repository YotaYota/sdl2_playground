#include "game_object.h"

#include <iostream>


GameObject::GameObject()
    : rect(std::make_unique<SDL_Rect>())
    , position(std::make_unique<Point>(1, 1))
{
    rect->x = 1;
    rect->y = 1;
    rect->w = 80;
    rect->h = 80;

}

GameObject::GameObject(const int width, const int height, int x, int y)
    : rect(std::make_unique<SDL_Rect>())
    , position(std::make_unique<Point>(x, y))
{
    rect->x = x;
    rect->y = y;
    rect->w = width;
    rect->h = height;
}

GameObject::~GameObject()
{
}

SDL_Rect* GameObject::getRect()
{
    return rect.get();
}

