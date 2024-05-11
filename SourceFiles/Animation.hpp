#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <map>

class Animation
{
public:
    sf::Texture texture;
    int numberOfFrames;
    int widthOfFrame;
    std::map<std::string, int> statesMap;
    bool looping;

    Animation(sf::Texture texture_, int numberOfFrames_, int widthOfFrame_, bool looping_, std::map<std::string, int> statesMap_){}

};