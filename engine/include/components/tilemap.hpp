#ifndef __ENGINE_COMPONENTS_TILEMAP__
#define __ENGINE_COMPONENTS_TILEMAP__

#include <string>
#include <map>

#include "sdl2include.h"
#include "components/component.hpp"
#include "./image.hpp"

typedef struct tileset{
    int x;
    int y;
}tileset;

namespace engine{
    class TileMapComponent: public Component{
    public:
        TileMapComponent(std::string path="")
            : Component(), m_path(path) {}

        virtual ~TileMapComponent() {}

        virtual bool init();
        virtual bool shutdown();
        virtual void add_tile(std::string name, int pos_x, int pox_y);
        tileset get_tile(std::string name);
    protected:
        std::string m_path;
        int m_w, m_h;

        std::map<std::string, tileset> m_tilemap;
        void create_tilemap();
    };
}

#endif