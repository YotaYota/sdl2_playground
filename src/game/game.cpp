#include "game.h"
#include "game_constants.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>

#include <iostream>
#include <memory>
#include <string>


Game::Game()
    : entityManager(std::make_unique<EntityManager>())
    , renderer(nullptr)
    , window(nullptr)
{
    if (!init())
    {
        throw -1;
    }

}

Game::~Game()
{
    std::cerr << "Game destructor" << '\n';
    IMG_Quit();
    SDL_Quit();
}

bool Game::init()
{

    if(SDL_Init(SDL_INIT_VIDEO) != 0
       && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
    {
        std::cerr << "Failed to initialize SDL: "
                  << SDL_GetError() << '\n';
        return false;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = std::make_unique<Window>(
                GameConstants::TITLE,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                GameConstants::WINDOW_WIDTH,
                GameConstants::WINDOW_HEIGHT,
                GameConstants::SDL_WINDOW_FLAGS
        );
    }

    if (!window)
    {
        std::cerr << "Failed to initialize window: "
                  << SDL_GetError() << '\n';

        return false;
    }

    renderer = std::make_shared<Renderer>(window.get()->raw(), -1, 0);
    if (!renderer)
    {
        std::cerr << "Failed to initialize renderer: "
                  << SDL_GetError() << '\n';

        return false;
    }

    return true;
}

void Game::update(const Uint8* keyState, const double dt)
{
    entityManager->update(keyState, dt);
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer.get()->raw(), 150, 111, 214, 200);
    SDL_RenderClear(renderer.get()->raw());
    entityManager->getPlayer()->render(*renderer.get()->raw());

    SDL_RenderPresent(renderer.get()->raw());
}

