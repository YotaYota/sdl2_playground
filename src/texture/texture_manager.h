#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "renderer.h"

#include <SDL2/SDL.h>

#include <map>
#include <memory>
#include <string>


class TextureManager
{
    private:
        std::map<std::string, SDL_Texture*> textures;
        std::shared_ptr<Renderer> const renderer;

    public:
        TextureManager(std::shared_ptr<Renderer> renderer);
        virtual ~TextureManager();

        bool loadFile(std::string id, std::string filename);
        void draw(std::string id,
                  int x, int y,
                  int width, int height,
                  SDL_RendererFlip flip=SDL_FLIP_NONE);

        //TODO: use this in game.cpp
        void drawTexture(
                  SDL_Texture* texture,
                  int x, int y,
                  int width, int height,
                  SDL_RendererFlip flip);

};

#endif /* TEXTURE_MANAGER_H */

