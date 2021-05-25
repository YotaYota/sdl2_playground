#include "window.h"

#include <SDL2/SDL_image.h>

#include <iostream>
#include <memory>
#include <string>


Window::Window(const std::string& title,
               const int x,
               const int y,
               const int w,
               const int h,
               const uint32_t window_flags)
    : window(SDL_CreateWindow(title.c_str(), x, y, w, h, window_flags))
{
}

Window::~Window()
{
    if (window)
    {
        SDL_DestroyWindow(window);
    }
}

SDL_Window* Window::raw()
{
    return window;
}

