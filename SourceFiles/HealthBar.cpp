#include "HealthBar.hpp"


HealthBar::HealthBar(float x, float y, float width, float height) 
{
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color::Red);
    background.setPosition(x, y);

    healthBar.setSize(sf::Vector2f(width, height));
    healthBar.setFillColor(sf::Color::Green);
    healthBar.setPosition(x, y);


    healthText.setFont(font);
    int fontSize = height-2;
    healthText.setCharacterSize(fontSize); // Adjust size as needed
    healthText.setFillColor(sf::Color::Black);
    healthText.setPosition(x+10, y-2); // Position to the left of the bar

    setPosition(x, y); // Set the position of the sprite
}

void HealthBar::update(float currentHealth, float maxHealth) 
{
    if (currentHealth < 0)
    {
        currentHealth = 0;
    }
    float healthPercentage = currentHealth / maxHealth;
    healthBar.setSize(sf::Vector2f(background.getSize().x * healthPercentage, background.getSize().y));

    healthText.setString(std::to_string(static_cast<int>(currentHealth)) + "/" + std::to_string(static_cast<int>(maxHealth)));
}

void HealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    target.draw(background, states);
    target.draw(healthBar, states);
    target.draw(healthText, states);
}

