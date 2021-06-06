#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "renderer.h"
#include "rigid_body_component.h"

#include <memory>


class RenderSystem
{
    private:
        RenderSystem(RenderSystem&) = delete;
        RenderSystem operator=(RenderSystem&) = delete;

    public:
        RenderSystem();
        virtual ~RenderSystem();

        void render(SDL_Renderer &renderer, const RigidBodyComponent &rigidBody);
};

#endif /* RENDER_SYSTEM_H */

