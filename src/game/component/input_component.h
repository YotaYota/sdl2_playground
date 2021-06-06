#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include <SDL2/SDL_keycode.h>

#include <map>


struct InputComponent
{
    public:
        std::map<const SDL_Scancode, bool> inputState {
            {SDL_SCANCODE_A, false},
            {SDL_SCANCODE_S, false},
            {SDL_SCANCODE_D, false},
            {SDL_SCANCODE_W, false}
        };
};

#endif /* ifndef  */

