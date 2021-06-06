#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"
#include "input_component.h"
#include "rigid_body_component.h"

#include <SDL2/SDL.h>

#include <memory>
#include <map>

class Player : public GameObject
{
    private:
        Player(GameObject&) = delete;
        Player& operator=(GameObject&) = delete;

        std::unique_ptr<InputComponent> input;
        std::unique_ptr<RigidBodyComponent> position;

    public:
        Player();
        Player(const int width, const int height, int x, int y);
        ~Player();

        void render(SDL_Renderer& renderer);
        InputComponent* getInputComponent();
        RigidBodyComponent* getRigidBodyComponent();
};

#endif /* PLAYER_H */

