#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"
#include "input_component.h"
#include "rigid_body_component.h"

#include <memory>
#include <map>

class Player : public GameObject
{
    private:
        Player(Player&) = delete;
        Player& operator=(Player&) = delete;

        std::unique_ptr<InputComponent> input;
        std::unique_ptr<RigidBodyComponent> position;

    public:
        Player();
        Player(const int width, const int height, int x, int y);
        ~Player();

        InputComponent* getInputComponent();
        RigidBodyComponent* getRigidBodyComponent();
};

#endif /* PLAYER_H */

