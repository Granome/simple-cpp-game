#pragma once

#include "UiElement.hpp"

class GameOverText : public UiElement
{
private:
    sf::RectangleShape background;
    sf::Text gameOverText;
    sf::Text restartGameText;

public:
    GameOverText(sf::Vector2f position);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};