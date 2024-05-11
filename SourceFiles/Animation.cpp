#include <Animation.hpp>

Animation::Animation(sf::Texture texture_, int numberOfFrames_, int widthOfFrame_, bool looping_, std::map<std::string, int> statesMap_)
{
    texture = texture_;
    numberOfFrames = numberOfFrames_;
    widthOfFrame = widthOfFrame_;
    looping = looping_;
    statesMap = statesMap_;
}