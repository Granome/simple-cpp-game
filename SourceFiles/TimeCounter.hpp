#pragma once

#include "UiElement.hpp"

class TimeCounter : public UiElement
{
private:
    sf::Text counter;
public:
    TimeCounter(sf::Vector2f position, int fontSize)
    {
        counter.setPosition(position);
        counter.setFont(font);
        counter.setFillColor(sf::Color::Yellow);
        counter.setCharacterSize(fontSize);
        counter.setString("0");
    }
    void updateTime(double time)
    {
        std::string strTime;
        if ((int)time/60 < 10)
        {
            strTime += "0";
        }
        strTime += std::to_string((int)time/60) + ":";
        if ((int)time%60 < 10)
        {
            strTime+="0";
        }
        strTime += std::to_string((int)time%60);
        counter.setString(strTime);
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(counter, states);
    }
};