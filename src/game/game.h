#ifndef GAME_H
#define GAME_H

#include "entity_manager.h"
#include "input.h"
#include "renderer.h"
#include "window.h"

#include <memory>
#include <SDL2/SDL.h>


class Game
{
    private:
        std::unique_ptr<EntityManager> entityManager;
        std::shared_ptr<Renderer> renderer;
        std::unique_ptr<Window> window;

        void initPlayer();

    public:
        Game(const Game&) = delete;
        Game operator=(const Game&) = delete;

        Game();
        ~Game();

        bool init();
        void update(const Uint8* keyState, const double dt);
        void render();
};

#endif /* ifndef GAME_H */

