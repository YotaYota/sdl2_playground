#ifndef PLAYER_MOVEMENT_SYSTEM_H
#define PLAYER_MOVEMENT_SYSTEM_H

#include "input_component.h"
#include "rigid_body_component.h"


class PlayerMovementSystem
{
    private:
        PlayerMovementSystem(PlayerMovementSystem&) = delete;
        PlayerMovementSystem operator=(PlayerMovementSystem&) = delete;

    public:
        PlayerMovementSystem();
        virtual ~PlayerMovementSystem();

        void update(InputComponent &input, RigidBodyComponent &postion);
};

#endif /* PLAYER_MOVEMENT_SYSTEM_H */

