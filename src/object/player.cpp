#include "player.h"

#include <iostream>


Player::Player()
    : GameObject()
    , input(std::make_unique<Input>())
    , playerKeyState(initKeyStates())
{
}

Player::Player(const int width, const int height, int x, int y)
    : GameObject(width, height, x, y)
    , input(std::make_unique<Input>())
    , playerKeyState(initKeyStates())
{
}

Player::~Player()
{
}

std::map<const SDL_Scancode, bool> Player::initKeyStates()
{
    return std::map<const SDL_Scancode, bool>{
        {SDL_SCANCODE_A, false},
        {SDL_SCANCODE_S, false},
        {SDL_SCANCODE_D, false},
        {SDL_SCANCODE_W, false}
    };
}

void Player::render(SDL_Renderer& renderer)
{
    SDL_SetRenderDrawColor(&renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(&renderer, getRect());
    SDL_RenderDrawRect(&renderer, getRect());
}

void Player::handleEvents(const Uint8* keyState)
{
    std::cout << "keyState: " << keyState << '\n';
    for (std::map<SDL_Scancode, bool>::iterator it=playerKeyState.begin(); it!=playerKeyState.end(); ++it)
    {
        const SDL_Scancode key = it->first;
        playerKeyState[key] = (keyState == nullptr) ? false
                                                    : keyState[it->first] == 1;
    }
}

void Player::update(double dt)
{
    setPosition(dt);
}

void Player::setPosition(double dt)
{
    if (playerKeyState[SDL_SCANCODE_A])
    {
        rect->x--;
        std::cout << dt << '\n';
    }
    if (playerKeyState[SDL_SCANCODE_D])
    {
        rect->x++;
    }
    if (playerKeyState[SDL_SCANCODE_S])
    {
        rect->y++;
    }
    if (playerKeyState[SDL_SCANCODE_W])
    {
        rect->y--;
    }
}

