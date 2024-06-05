#pragma once
#include "UiElement.hpp"

class XpBar : public UiElement
{

private:
    sf::RectangleShape background;
    sf::RectangleShape xpBar;
    sf::Text xpText;
    sf::Text lvlText;

public:
    XpBar(float x, float y, float width, float height);
    

    void update(float currentXP, float xpForNextLevel, int currentLVL);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
