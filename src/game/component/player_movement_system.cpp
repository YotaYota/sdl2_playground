#include "player_movement_system.h"

#include <SDL2/SDL_keycode.h>


PlayerMovementSystem::PlayerMovementSystem()
{
}

PlayerMovementSystem::~PlayerMovementSystem()
{
}

void PlayerMovementSystem::update(InputComponent &input, RigidBodyComponent &postion)
{
    if (input.inputState[SDL_SCANCODE_A])
    {
        postion.rect.x--;
    }
    if (input.inputState[SDL_SCANCODE_D])
    {
        postion.rect.x++;
    }
    if (input.inputState[SDL_SCANCODE_S])
    {
        postion.rect.y++;
    }
    if (input.inputState[SDL_SCANCODE_W])
    {
        postion.rect.y--;
    }
}

