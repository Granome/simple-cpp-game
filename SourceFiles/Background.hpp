#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Background : public  sf::Sprite
{
private:
    sf::Texture texture;
    float texturePosX;
    float texturePosY;
public:
    Background();
    void updateTexturePositions(float x, float y);
    void fillTheWindow(sf::Vector2u windowSize);
};