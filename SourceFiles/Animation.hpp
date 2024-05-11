#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

class Animation;

class AnimationState
{
public:
    std::string stateName;
    int numberOfFrames;
    bool loopable;
public:
    AnimationState(std::string stateName_="idle", int numberOfFrames_ = 1, bool loopable_ = true);
};

class Animation
{
public:
    sf::Texture texture;
    int numberOfFrames;
    int widthOfFrame;
    std::vector<AnimationState> animationStates;

    Animation(std::string pathToTexture="", int numberOfFrames_=1, bool looping_=true, std::vector<AnimationState> animationStates_={});

};
