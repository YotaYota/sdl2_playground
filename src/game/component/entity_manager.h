#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "game_object.h"
#include "input_system.h"
#include "player.h"
#include "player_movement_system.h"

#include <memory>
#include <vector>


class EntityManager
{
    private:
        //std::vector<std::unique_ptr<GameObject>> entities;
        std::unique_ptr<InputSystem> inputSystem;
        std::unique_ptr<Player> player;
        std::unique_ptr<PlayerMovementSystem> playerMovementSystem;

    public:
        EntityManager();
        virtual ~EntityManager();

        void update(const Uint8* keyState, const double dt);
        Player* getPlayer();
};

#endif /* ENTITY_MANAGER_H */

