#include "player.h"

#include <iostream>


Player::Player()
    : input(std::make_unique<InputComponent>())
    , position(std::make_unique<RigidBodyComponent>())
{
}

Player::Player(const int width, const int height, int x, int y)
    : input(std::make_unique<InputComponent>())
    , position(std::make_unique<RigidBodyComponent>())
{
    position->rect.x = x;
    position->rect.y = y;
    position->rect.w = width;
    position->rect.h = height;
}

Player::~Player()
{
}

void Player::render(SDL_Renderer& renderer)
{
    SDL_SetRenderDrawColor(&renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(&renderer, &position->rect);
    SDL_RenderDrawRect(&renderer, &position->rect);
}

InputComponent* Player::getInputComponent()
{
    return input.get();
}

RigidBodyComponent* Player::getRigidBodyComponent()
{
    return position.get();
}

