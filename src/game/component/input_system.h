#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

#include "input_component.h"

#include <memory>


class InputSystem
{
    private:
        InputSystem(InputSystem&) = delete;
        InputSystem operator=(InputSystem&) = delete;

    public:
        InputSystem();
        virtual ~InputSystem();

        void update(const Uint8* &keyState, InputComponent &inputComponent);
};

#endif /* INPUT_SYSTEM_H */

