#include "components/tilemap.hpp"

#include "game.hpp"
#include "log.h"
#include "sdl_log.h"

#include <string>

using namespace engine;

bool TileMapComponent::init(){
    INFO("Init TileMapComponent");
    return true;
}

bool TileMapComponent::shutdown(){
    INFO("Shutdown TileMapComponent");
    return true;
}

void TileMapComponent::add_tile(std::string name, int pos_x, int pos_y){
    tileset t;
    t.x = pos_x;
    t.y = pos_y;

    m_tilemap.insert(std::pair<std::string, tileset>(name, t));
}

tileset TileMapComponent::get_tile(std::string name){
    tileset error;
    auto search = m_tilemap.find(name);
    if(search != m_tilemap.end()){
        return search->second;
    }
    WARN("Tile does not exist!");
    error.x = 0;
    error.y = 0;
    return error;
}

void TileMapComponent::create_tilemap(){
    int cont = 0;
    for(int pos_y = 0; pos_y <= 240; pos_y += 8){
        for(int pos_x = 0; pos_x <= 320; pos_x += 8){
            add_tile(std::to_string(cont), pos_x, pos_y);
            cont++;
        }
    }
}