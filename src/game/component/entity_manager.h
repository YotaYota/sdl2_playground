#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "game_object.h"
#include "input_system.h"
#include "player.h"
#include "player_movement_system.h"
#include "render_system.h"
#include "renderer.h"

#include <memory>
#include <vector>


class EntityManager
{
    private:
        EntityManager(EntityManager&) = delete;
        EntityManager& operator=(EntityManager&) = delete;

        //std::vector<std::unique_ptr<GameObject>> entities;
        std::unique_ptr<InputSystem> inputSystem;
        std::unique_ptr<Player> player;
        std::unique_ptr<PlayerMovementSystem> playerMovementSystem;
        std::unique_ptr<RenderSystem> renderSystem;

    public:
        EntityManager();
        virtual ~EntityManager();

        void update(const Uint8* keyState, const double dt);
        void render(SDL_Renderer &renderer);
        Player* getPlayer();
};

#endif /* ENTITY_MANAGER_H */

