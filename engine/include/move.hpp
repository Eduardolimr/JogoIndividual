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
    bool toggle = false;
    bool upside_down = false;

    int relative_x = engine::Game::instance.window_size().first - 32;
    int relative_y = engine::Game::instance.window_size().second - 32;

    void update()
    {
        auto dy = gravity;
        auto animCtrl = m_game_object->get_component<engine::AnimationControllerComponent>();
        if(engine::Game::instance.input_manager().is_button_down("w")){
            if (!is_moving)
            {
                toggle = true;
                upside_down = !upside_down;
            }
            is_moving = true;

            if(!upside_down){
                animCtrl->change_to("standing");
            }
            else{
                animCtrl->change_to("standing_upside");
            }
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



        auto dx = 0;
        
        if (engine::Game::instance.input_manager().is_button_down("a")){
            dx = -4;
            if(!upside_down){
                animCtrl->change_to("run_l");
            }
            else{
                animCtrl->change_to("run_l_upside");
            }
        }

        if (engine::Game::instance.input_manager().is_button_down("d")){
            dx = 4;
            if(!upside_down){
                animCtrl->change_to("run_r");
            }
            else{
                animCtrl->change_to("run_r_upside");
            }
        }
        
        dx = m_game_object->x + dx;
        if (dx >= relative_x || dx < 0){
            dx = 0;
            if(!upside_down){
                animCtrl->change_to("standing");
            }
            else{
                animCtrl->change_to("standing_upside");
            }
        }
        
        m_game_object->x = dx; 
        if (is_moving){
            m_game_object->y = dy;
        }
    }
};

#endif
