#include "timer.h"
#include "time_constants.h"

#include <SDL2/SDL.h>


Timer::Timer()
    : deltaTime(0.0)
    , lastTime(0.0)
{
}

void Timer::tick()
{
    deltaTime = (SDL_GetTicks() - lastTime) * timeConstants::TARGET_FPS / 1000.0f;

    if (deltaTime > timeConstants::TARGET_DELTA_TIME) {
        deltaTime = timeConstants::TARGET_DELTA_TIME;
    }

    lastTime = SDL_GetTicks();
}

double Timer::getDeltaTime() const
{
    return deltaTime;
}

