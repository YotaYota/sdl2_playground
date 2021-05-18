#ifndef GAME_H
#define GAME_H

#include "input.h"
#include "player.h"

#include <memory>
#include <SDL2/SDL.h>


class Game
{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        std::unique_ptr<Player> player;

        void initPlayer();

    public:
        Game(const Game&) = delete;
        Game operator=(const Game&) = delete;

        Game();
        ~Game();

        bool init();
        void handleEvents(const Uint8* keyState);
        void update(const double dt);
        void render();
};

#endif /* ifndef GAME_H */

