#include <Animation.hpp>

Animation::Animation(std::string pathToTexture="", int numberOfFrames_=1, bool looping_=true, std::map<std::string, int> statesMap_={})
{
    if (pathToTexture != "")
        {
            texture.loadFromFile(pathToTexture);
        }
    numberOfFrames = numberOfFrames_;
    widthOfFrame = texture.getSize().x / (numberOfFrames);
    looping = looping_;
    statesMap = statesMap_;
}