#include "game.h"
#include "game_constants.h"

#include <SDL2/SDL_image.h>

#include <iostream>
#include <memory>
#include <string>


Game::Game()
    : window(nullptr)
    , renderer(nullptr)
    , player(nullptr)
{

}

Game::~Game()
{
    std::cerr << "Game destructor" << '\n';
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
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
        window = SDL_CreateWindow(GameConstants::TITLE,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  GameConstants::WINDOW_WIDTH,
                                  GameConstants::WINDOW_HEIGHT,
                                  GameConstants::SDL_WINDOW_FLAGS);
    }

    if (window == nullptr)
    {
        std::cerr << " Failed to initialize window: "
                  << SDL_GetError() << '\n';
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr)
    {
        std::cerr << " Failed to initialize renderer: "
                  << SDL_GetError() << '\n';
        return false;
    }

    initPlayer();

    return true;
}

void Game::initPlayer()
{
    player = std::make_unique<Player>(60, 60, 60, 120);
}

void Game::handleEvents(const Uint8* keyState)
{
    player->handleEvents(keyState);
}

void Game::update(const double dt)
{
    player->update(dt);
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 150, 111, 214, 200);
    SDL_RenderClear(renderer);
    player->render(*renderer);

    SDL_RenderPresent(renderer);
}

