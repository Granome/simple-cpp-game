#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Animation.hpp"

class AnimatedSprite : public sf::Sprite
{
    //Moves texture rect to the right on texture file by size of image / number of frames
    //Animation can be loopable of unloopable
    //if animation is unloopable, idle state will be set after it finishes playing
private:
    float fps; // float, so i can slow down animations more smoothly
    float timeSinceLastFrame;
    int currentFrame=0;
    std::string _current_state = "idle";
    Animation animation;

public:
    AnimatedSprite(float fps_ = 1, std::string current_state="idle");


    void animate(sf::Time &elapsed);

    void setAnimation(Animation animation_);

    Animation getAnimation();

    void setFps(float fps_);

    virtual void changeAnimationState(std::string new_state);

};