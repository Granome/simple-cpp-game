#include "XpBar.hpp"

XpBar::XpBar(float x, float y, float width, float height) 
{
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color::Yellow);
    background.setPosition(x, y);

    xpBar.setSize(sf::Vector2f(width, height));
    xpBar.setFillColor(sf::Color::Blue);
    xpBar.setPosition(x, y);

    setPosition(x, y); // Set the position of the sprite

    xpText.setFont(font);
    int fontSize = height-2;
    xpText.setCharacterSize(fontSize); // Adjust size as needed
    xpText.setFillColor(sf::Color::Black);
    xpText.setPosition(x+10, y-2); // Position to the left of the bar
    
    lvlText.setFont(font);
    fontSize = height;
    lvlText.setCharacterSize(fontSize); // Adjust size as needed
    lvlText.setFillColor(sf::Color::Yellow);
    lvlText.setPosition(x+10+width, y-2);
}

void XpBar::update(float currentXP, float xpForNextLevel, int currentLVL) 
{
    if (currentXP > xpForNextLevel)
    {
        currentXP = xpForNextLevel;
    }
    float XpPercentage = currentXP / xpForNextLevel;
    xpBar.setSize(sf::Vector2f(background.getSize().x * XpPercentage, background.getSize().y));

    xpText.setString(std::to_string(static_cast<int>(currentXP)) + "/" + std::to_string(static_cast<int>(xpForNextLevel)));
    lvlText.setString("LVL: " + std::to_string(static_cast<int>(currentLVL)));
}

void XpBar::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    target.draw(background, states);
    target.draw(xpBar, states);
    target.draw(xpText, states);
    target.draw(lvlText, states);
}