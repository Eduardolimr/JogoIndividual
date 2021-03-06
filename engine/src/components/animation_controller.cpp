#include "components/animation_controller.hpp"

#include "log.h"

using namespace engine;

bool AnimationControllerComponent::init()
{
    INFO("Init AnimationControllerComponent");
    for(auto id_animation: m_animations_map) {
        if (current_animation != id_animation.first)
            id_animation.second->disable();
        else
            id_animation.second->enable();
    }

    return true;
}

bool AnimationControllerComponent::shutdown()
{
    INFO("Shutdown AnimationControllerComponent");
    return true;
}

void AnimationControllerComponent::update()
{
    if (current_animation == "")
    {
        WARN("No animations to play!");
    }
    else
    {
        auto animation = m_animations_map[current_animation];
        if(next_animation != "" && animation->has_finished())
            change_animations();
    }
}

void AnimationControllerComponent::add_animation(std::string name,
                                                 AnimationComponent & animation)
{
    if (m_animations_map.find(name) != m_animations_map.end())
    {
        WARN("Animation " << name << " already exists!");
        return;
    }

    m_animations_map[name] = &animation;

    if (m_animations_map.size() == 1)
        current_animation = name;
}

void AnimationControllerComponent::play_animation(std::string name,
                                                  bool wait_to_finish)
{
    next_animation = name;
    if (!wait_to_finish) change_animations();
}

void AnimationControllerComponent::change_animations()
{
    auto animation = m_animations_map[current_animation];
    animation->disable();

    current_animation = next_animation;
    next_animation = "";

    animation = m_animations_map[current_animation];
    animation->enable();
    animation->setup();
}

void AnimationControllerComponent::change_to(std::string name){
    if(current_animation != name){
        auto animation = m_animations_map[current_animation];
        animation->disable();

        if(name == "" || m_animations_map[name] == NULL){
            INFO("Invalid animation!");
        }else{

            current_animation = name;

            animation = m_animations_map[current_animation];
            animation->enable();
            animation->setup();
        }
    }
}