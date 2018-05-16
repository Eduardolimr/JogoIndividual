#ifndef __GAME_CODE_MOVE__
#define __GAME_CODE_MOVE__

#include "log.h"

#include "game.hpp"
#include "components/code.hpp"

class Move : public engine::CodeComponent
{
  public:
    Move() : engine::CodeComponent() {}
    double gravity = 2;
    bool is_moving = true;
    int relative_x = engine::Game::instance.window_size().first;
    int relative_y = engine::Game::instance.window_size().second;
    bool toggle = false;
    bool upside_down = false;

    void update()
    {
        auto dy = gravity;

        if(engine::Game::instance.input_manager().is_button_down("w")){
            if (!is_moving)
            {
                toggle = true;
                upside_down = !upside_down;
            }
            is_moving = true;
        }

        if(toggle && upside_down){
            dy *= -1;
        }

        dy = m_game_object->y + dy;

        if (dy >= relative_y || dy < 0)
        {
            toggle = false;
            is_moving = false;
        }

        if (is_moving)
        {
            m_game_object->y = dy;
        }
        INFO(m_game_object->y);

        auto dx = 0;

        if (engine::Game::instance.input_manager().is_button_down("a")){
            dx = -2;
        }

        if (engine::Game::instance.input_manager().is_button_down("d")){
            dx = 2;
        }
        
        dx = m_game_object->x + dx;
        if (dx >= relative_x || dx < 0){
            dx = 0;
        }
        m_game_object->x = dx;
    }
};

#endif
