#include "components/tilemap.hpp"

#include "game.hpp"
#include "log.h"
#include "sdl_log.h"

using namespace engine;

bool TileMapComponent::init(){
    INFO("Init TileMapComponent");

    if(m_path == ""){
        WARN("Invalid path for tilemap!");
        return false;
    }
    return true;
}

bool TileMapComponent::shutdown(){
    INFO("Shutdown TileMapComponent");

    for(auto id: m_tilemap){
        auto obj = id.second;
        if (obj.shutdown() == false){
            WARN("Could not shutdown tileset " << id.first);
            return false;
        }
    }
    return true;
}

void TileMapComponent::add_tile(std::string name, int pos_x, int pos_y){
    auto tile = ImageComponent(m_path);
    tile.change_pos(pos_x, pos_y);

    m_tilemap.insert( std::pair<std::string, ImageComponent>(name, tile) );
}

void TileMapComponent::draw(){
    for(auto id: m_tilemap){
        auto tileset = id.second;
        tileset.draw();
    }
}
