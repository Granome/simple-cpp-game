#include "AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite(float fps_, std::string current_state)
    {
        fps = fps_;
        _current_state = current_state;

        this->setTextureRect(sf::IntRect(0, 0, animation.texture.getSize().x / animation.numberOfFrames, animation.texture.getSize().y));
    }


void AnimatedSprite::animate(sf::Time &elapsed)
{
    int numberOfFramesInState = 0;


    int frameOffset = 0; 

    
    for (auto state : animation.animationStates)
    {
        if (state.stateName == _current_state)
        {
            numberOfFramesInState = state.numberOfFrames;
            break;
        }
        else
        {
            frameOffset+=state.numberOfFrames;
        }
    }

    timeSinceLastFrame += elapsed.asSeconds();

    if (timeSinceLastFrame >= 1.0/fps)
    {

        currentFrame++;
        if (currentFrame == numberOfFramesInState)
        {
            for (auto state : animation.animationStates)
            {
                if (state.stateName == _current_state)
                {
                    if(state.loopable)
                    {
                        currentFrame = 0;                            
                    }
                    else
                    {
                        _current_state = "idle";
                    }
                }
            }
        }

        this->setTextureRect(sf::IntRect(currentFrame * animation.widthOfFrame + frameOffset * animation.widthOfFrame, 0, animation.widthOfFrame, animation.texture.getSize().y));
        timeSinceLastFrame = 0;

    }

}

void AnimatedSprite::setAnimation(Animation animation_)
{
    animation = animation_;
    this->setTexture(animation.texture);
    this->setTextureRect(sf::IntRect(0, 0, animation.texture.getSize().x / animation.numberOfFrames,  animation.texture.getSize().y));

}


Animation AnimatedSprite::getAnimation()
{
    return animation;
}


void AnimatedSprite::setFps(float fps_)
{
    fps = fps_;
}

void AnimatedSprite::changeAnimationState(std::string new_state)
{
    if (_current_state != new_state)
    {
        for (auto state : animation.animationStates)
        {
            if (state.loopable) // unloopable animations cant be interrupted
            {
                _current_state = new_state;
                currentFrame = 0;
                timeSinceLastFrame=0.8/fps; //sloght delay after state change, so character does not "shake"
            }
        }
    }
}