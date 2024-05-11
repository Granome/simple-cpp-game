#include <Animation.hpp>

Animation::Animation(std::string pathToTexture="", int numberOfFrames_=1, bool looping_=true, std::vector<AnimationState> animationStates_={})
{
    if (pathToTexture != "")
        {
            texture.loadFromFile(pathToTexture);
        }
    numberOfFrames = numberOfFrames_;
    widthOfFrame = texture.getSize().x / (numberOfFrames);
    animationStates = animationStates_;
}

AnimationState::AnimationState(std::string stateName_="idle", int numberOfFrames_ = 1, bool loopable_ = true)
{
    stateName = stateName_;
    numberOfFrames = numberOfFrames_;
    loopable = loopable_;
}