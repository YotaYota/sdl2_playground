#ifndef PREFIX_INPUT_H
#define PREFIX_INPUT_H

#include <SDL2/SDL.h>

class Input
{
    private:
        Input(Input&) = delete;
        Input operator=(Input&) = delete;

        const Uint8* keyState;
        bool quit;

        void setKeyState();
        void setQuit(bool quit);

    public:
        Input();
        ~Input();

        void pollEvents();
        bool isKeyDown(const SDL_Scancode key) const;
        bool isQuit() const;
        const Uint8* getKeyState();
};

#endif /* PREFIX_INPUT_H */

