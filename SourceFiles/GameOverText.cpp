#include "GameOverText.hpp"

GameOverText::GameOverText(sf::Vector2f position)
{
    background = sf::RectangleShape(sf::Vector2f(600, 300));
    background.setFillColor(sf::Color(133, 43, 37, 150));
    gameOverText = sf::Text("GAME OVER", font, 60);
    restartGameText = sf::Text("PRESS ENTER TO RESTART", font, 40);

    float x = position.x;
    float y = position.y;
    background.setPosition(x, y);

    float gameOverTextX = x + (background.getGlobalBounds().width - gameOverText.getGlobalBounds().width)/2;
    float gameOverTextY = y + (background.getGlobalBounds().height - gameOverText.getGlobalBounds().height)/2 - 60;

    gameOverText.setPosition(gameOverTextX , gameOverTextY);

    float restartGameTextX = x + (background.getGlobalBounds().width - restartGameText.getGlobalBounds().width)/2;
    float restartGameTextY = y + gameOverTextY + 10;
    restartGameText.setPosition(restartGameTextX, restartGameTextY);
}

void GameOverText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(background, states);
    target.draw(gameOverText, states);
    target.draw(restartGameText, states);
}