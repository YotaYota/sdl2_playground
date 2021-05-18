#include "game.h"
#include "input.h"
#include "timer.h"

#include <SDL2/SDL.h>

#include <iostream>
#include <memory>


int doGameLoop()
{
    const auto game = std::make_unique<Game>();
    const auto timer = std::make_unique<Timer>();
    const auto input = std::make_unique<Input>();

    if (!game->init())
    {
        return -1;
    }

    while(!input->isQuit())
    {
        input->pollEvents();
        game->handleEvents(input->getKeyState());
        game->update(timer->getDeltaTime());
        game->render();
        timer->tick();
    }

    return 0;
}

int main(int, const char**)
{
    return doGameLoop();
}

