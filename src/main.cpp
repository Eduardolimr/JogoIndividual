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

    auto title = GameObject("Title", 1, 0);
    title.set_position(250, 250);

    auto title_text = TextComponent("UnB - FGA", "font.ttf", 30,
                                    Color(0x00, 0x00, 0x00));

    auto bg_music = AudioComponent("music.ogg", true);

    title.add_component(title_text);
    title.add_component(bg_music);

    Move move;
    MoveSideToSide movesidetoside;
    title.add_component(movesidetoside);

    AnimationControllerComponent animCtrl;

    AnimationComponent boyAnimationStanding("boy.png", 3, 2, 0.5, true );
    boyAnimationStanding.set_end_frame(0);
    animCtrl.add_animation("standing", boyAnimationStanding);

    AnimationComponent boyAnimationStandingUpside("boy_upsidedown.png", 3, 2 , 0.5, true);
    boyAnimationStandingUpside.set_end_frame(0);
    animCtrl.add_animation("standing_upside", boyAnimationStandingUpside);

    AnimationComponent boyAnimation("boy.png", 3, 2, 0.5, true);
    boyAnimation.set_end_frame(2);
    animCtrl.add_animation("run_r", boyAnimation);

    AnimationComponent boyAnimation2("boy.png", 3, 2, 0.5, true);
    boyAnimation2.set_frame_range(3, 5);
    animCtrl.add_animation("run_l", boyAnimation2);

    AnimationComponent boyAnimation3("boy_upsidedown.png", 3, 2, 0.5, true);
    boyAnimation3.set_end_frame(2);
    animCtrl.add_animation("run_l_upside", boyAnimation3);

    AnimationComponent boyAnimation4("boy_upsidedown.png", 3, 2, 0.5, true);
    boyAnimation4.set_frame_range(3, 5);
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