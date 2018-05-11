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

    auto title = GameObject("Title", 1, 0);
    title.set_position(10, 10);

    auto title_text = TextComponent("test.txt", "font.ttf", 30,
                                    Color(0x00, 0x00, 0x00));

    auto bg_music = AudioComponent("music.ogg", true);

    title.add_component(title_text);
    title.add_component(bg_music);

    Move move;
    title.add_component(move);

    menu.add_game_object(title);

    Game::instance.add_scene(menu);

    // Game loop
    Game::instance.run();

    return 0;
}