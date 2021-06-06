#include "entity_manager.h"

#include "player.h"

#include <iostream>


EntityManager::EntityManager()
    : inputSystem(std::make_unique<InputSystem>())
    , player(std::make_unique<Player>(60, 60, 60, 120))
    , playerMovementSystem(std::make_unique<PlayerMovementSystem>())
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::update(const Uint8* keyState, const double dt)
{
    inputSystem->update(keyState, *(getPlayer()->getInputComponent()));
    playerMovementSystem->update(*(getPlayer()->getInputComponent()),
                                 *(getPlayer()->getRigidBodyComponent()));

    std::cerr << dt << '\n';
}

Player* EntityManager::getPlayer()
{
    return player.get();
}

