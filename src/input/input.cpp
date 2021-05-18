#include "input.h"

#include <iostream>


Input::Input()
    : keyState(nullptr)
    , quit(false)
{
}

Input::~Input()
{
    std::cerr << "Input destructor" << '\n';
}

void Input::pollEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                setKeyState();
                break;
            case SDL_QUIT:
                std::cerr << "SDL_QUIT" << '\n';
                setQuit(true);
        }
    }
}

void Input::setKeyState()
{
    keyState = SDL_GetKeyboardState(nullptr);
}

bool Input::isKeyDown(const SDL_Scancode key) const
{
    return (keyState != nullptr)
        ? keyState[key] == 1
        : false;
}

const Uint8* Input::getKeyState()
{
    return keyState;
}

void Input::setQuit(bool quit)
{
    this->quit = quit;
}

bool Input::isQuit() const
{
    return quit;
}

