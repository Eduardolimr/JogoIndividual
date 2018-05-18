#ifndef __ENGINE_MAP__
#define __ENGINE_MAP__

#include <string>
#include "log.h"

#include "game.hpp"
#include "components/tilemap.hpp"
#include "components/code.hpp"

class GameMap: public engine::Component{
public:
    GameMap() : engine::Component() {}
    
    std::map<std::string, engine::ImageComponent> m_tile;


    virtual ~GameMap() {}

    virtual bool shutdown() { return Component::shutdown(); };
    virtual void update() { Component::update(); } ;
    virtual void draw() { Component::draw(); };

    bool init(){
        auto tilemap = m_game_object->get_component<engine::TileMapComponent>();
        tilemap->create_tilemap();
        auto tile = tilemap->get_tile("20");
        engine::ImageComponent image = engine::ImageComponent("tiles.png");
        image.change_pos_image(tile.x, tile.y);;
        image.change_pos_canvas(50, 50);
        image.resize_rect(8, 8);
        m_tile.insert(std::pair<std::string, engine::ImageComponent>("tile 1", image));
        m_game_object->add_component(m_tile["tile 1"]);
        m_game_object->draw();
        INFO("Adding tile");
        return Component::init();
    }
};

#endif