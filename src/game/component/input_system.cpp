#include "input_system.h"

#include <SDL2/SDL_keycode.h>

#include <map>


InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

void InputSystem::update(const Uint8* &keyState, InputComponent &inputComponent)
{
    for (std::map<SDL_Scancode, bool>::iterator it=inputComponent.inputState.begin();
         it!=inputComponent.inputState.end(); ++it)
    {
        const SDL_Scancode key = it->first;
        inputComponent.inputState[key] = (keyState == nullptr)
            ? false
            : keyState[it->first] == 1;
    }
}

