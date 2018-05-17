#include "game.hpp"
#include "scene.hpp"
#include "gameobject.hpp"
#include "components/image.hpp"
#include "components/text.hpp"
#include "components/animation.hpp"
#include "components/animation_controller.hpp"
#include "components/audio.hpp"

#include "gameglobals.hpp"
#include "movesidetoside.hpp"
#include "move.hpp"

using namespace engine;

int main(int, char**)
{
    // Configure game
    Game::instance.set_properties(globals::game_name, globals::window_size);

    // Setup scenes
    Scene menu("Main Menu");

    auto player = GameObject("Player", 2, 0);
    player.set_position(0, 0);
    
    auto bg_music = AudioComponent("music.ogg", true);

    title.add_component(bg_music);

    AnimationControllerComponent animCtrl;

    AnimationComponent boyAnimationStanding("sprites.png", 12, 16, 0.25, true );
    boyAnimationStanding.set_end_frame(0);
    animCtrl.add_animation("standing", boyAnimationStanding);

    AnimationComponent boyAnimationStandingUpside("sprites.png", 12, 16, 0.25, true);
    boyAnimationStandingUpside.set_frame_range(6, 6);
    animCtrl.add_animation("standing_upside", boyAnimationStandingUpside);

    AnimationComponent boyAnimation("sprites.png", 12, 16, 0.25, true);
    boyAnimation.set_end_frame(2);
    animCtrl.add_animation("run_r", boyAnimation);

    AnimationComponent boyAnimation2("sprites.png", 12, 16, 0.25, true);
    boyAnimation2.set_frame_range(3, 5);
    animCtrl.add_animation("run_l", boyAnimation2);

    AnimationComponent boyAnimation3("sprites.png", 12, 16, 0.25, true);
    boyAnimation3.set_frame_range(6, 8);
    animCtrl.add_animation("run_l_upside", boyAnimation3);

    AnimationComponent boyAnimation4("sprites.png", 12, 16, 0.25, true);
    boyAnimation4.set_frame_range(9, 11);
    animCtrl.add_animation("run_r_upside", boyAnimation4);

    player.add_component(move);
    player.add_component(boyAnimationStanding);
    player.add_component(boyAnimationStandingUpside);
    player.add_component(boyAnimation);
    player.add_component(boyAnimation2);
    player.add_component(boyAnimation3);
    player.add_component(boyAnimation4);
    player.add_component(animCtrl);

    menu.add_game_object(player);
    menu.add_game_object(title);

    Game::instance.add_scene(menu);

    // Game loop
    Game::instance.run();

    return 0;
}