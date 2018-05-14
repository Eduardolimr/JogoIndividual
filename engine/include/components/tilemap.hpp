#ifndef __ENGINE_COMPONENTS_TILEMAP__
#define __ENGINE_COMPONENTS_TILEMAP__

#include <string>
#include <map>

#include "sdl2include.h"
#include "components/component.hpp"
#include "./image.hpp"

namespace engine{
    class TileMapComponent: public Component{
    public:
        TileMapComponent(std::string path="")
            : Component(), m_path(path) {}

        virtual ~TileMapComponent() {}

        virtual bool init();
        virtual bool shutdown();
        virtual void draw();
        virtual void add_tile(std::string name, int pos_x, int pos_y);
    protected:
        std::string m_path;
        int m_w, m_h;

        std::map<std::string, ImageComponent> m_tilemap;
    };
}

#endif