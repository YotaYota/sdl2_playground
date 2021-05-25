#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL_video.h>

#include <string>


class Window
{
    private:
        SDL_Window* window;

    public:
        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        Window(const std::string& title,
               const int x,
               const int y,
               const int w,
               const int h,
               const uint32_t window_flags);

        ~Window();

        SDL_Window* raw();
};

#endif /* WINDOW_H */

