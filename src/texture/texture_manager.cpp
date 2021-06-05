#include "texture_manager.h"

#include <SDL2/SDL_image.h>

#include <iostream>


TextureManager::TextureManager(std::shared_ptr<Renderer> renderer)
    : textures({})
    , renderer(renderer)
{
}

TextureManager::~TextureManager()
{}

bool TextureManager::loadFile(std::string id, std::string filename)
{
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if (!surface)
    {
        std::cerr << "Failed to load texture " << filename.c_str()
                  << '\n' << SDL_GetError() << '\n';

        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(
        renderer.get()->raw(), surface);
    if (!texture)
    {
        std::cerr << "Failed to create texture for surface\n"
                  << SDL_GetError() << '\n';

        return false;
    }

    textures[id] = texture;

    return true;
}

void TextureManager::draw(std::string id,
          int x, int y,
          int width, int height,
          SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect dstRect = {x, y, width, height};
    SDL_RenderCopyEx(renderer.get()->raw(),
                     textures[id],
                     &srcRect,
                     &dstRect,
                     0,
                     nullptr,
                     flip
    );
}

void TextureManager::drawTexture(
        SDL_Texture* texture,
          int x, int y,
          int width, int height,
          SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect dstRect = {x, y, width, height};
    SDL_RenderCopyEx(renderer.get()->raw(),
                     texture,
                     &srcRect,
                     &dstRect,
                     0,
                     nullptr,
                     flip);
}

