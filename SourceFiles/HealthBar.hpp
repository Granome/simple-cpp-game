#pragma once
#include "UiElement.hpp"
#include <string>

class HealthBar : public UiElement
{

private:
    sf::RectangleShape background;
    sf::RectangleShape healthBar;
    sf::Text healthText;

public:
    HealthBar(float x, float y, float width, float height);
    

    void update(float currentHealth, float maxHealth);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
