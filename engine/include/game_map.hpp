#ifndef __ENGINE_MAP__
#define __ENGINE_MAP__

#include <string>
#include "log.h"

#include "game.hpp"
#include "components/tilemap.hpp"
#include "components/code.hpp"

class GameMap: public engine::CodeComponent{
public:
    GameMap() : engine::CodeComponent() {}
    int tile_size = 32;

    bool init(){
        auto tilemap = m_game_object->get_component<engine::TileMapComponent>();
        return true;
    }
};

#endif