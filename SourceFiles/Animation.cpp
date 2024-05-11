#include "Animation.hpp"

Animation::Animation(std::string pathToTexture, int numberOfFrames_, bool looping_, std::vector<AnimationState> animationStates_)
{
    if (pathToTexture != "")
        {
            texture.loadFromFile(pathToTexture);
        }
    numberOfFrames = numberOfFrames_;
    widthOfFrame = texture.getSize().x / (numberOfFrames);
    animationStates = animationStates_;
}

AnimationState::AnimationState(std::string stateName_, int numberOfFrames_, bool loopable_)
{
    stateName = stateName_;
    numberOfFrames = numberOfFrames_;
    loopable = loopable_;
}