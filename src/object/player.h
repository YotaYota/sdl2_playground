#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"
#include "input.h"

#include <SDL2/SDL.h>

#include <memory>
#include <map>

class Player : public GameObject
{
    private:
        Player(GameObject&) = delete;
        Player& operator=(GameObject&) = delete;

        std::unique_ptr<Input> input;
        std::map<const SDL_Scancode, bool> playerKeyState;

        std::map<const SDL_Scancode, bool> initKeyStates();
        void setKeyStates(const Input& input);
        void setPosition(const double dt);

    public:
        Player();
        Player(const int width, const int height, int x, int y);
        ~Player();

        void render(SDL_Renderer& renderer);
        void handleEvents(const Uint8* keyState);
        void update(const double dt);
};

#endif /* PLAYER_H */

