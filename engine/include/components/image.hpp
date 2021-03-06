#ifndef __ENGINE_COMPONENTS_IMAGE__
#define __ENGINE_COMPONENTS_IMAGE__

#include <string>
#include "sdl2include.h"
#include "components/component.hpp"

namespace engine {

    class ImageComponent : public Component {
    public:
        ImageComponent(std::string path="")
            : Component(), m_path(path) {}

        virtual ~ImageComponent() {}

        virtual bool init();
        virtual bool shutdown();
        virtual void draw();
        virtual void change_pos_canvas(int pos_x, int pos_y);
        virtual void change_pos_image(int pos_x, int pos_y);
        virtual void resize_rect(int size_w, int size_h);
    protected:
        std::string m_path;
        int         m_w, m_h;

        SDL_Texture * m_texture;
        SDL_Rect      m_canvas_rect;  // Position and size on canvas
        SDL_Rect      m_image_rect;   // Position and size inside the image

        void update_canvas_rect();
    };
}

#endif