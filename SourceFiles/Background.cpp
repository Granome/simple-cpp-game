#include "Background.hpp"

Background::Background()
{
    texture.loadFromFile("..\\Resourses\\Textures\\ground.jpg");
    texture.setRepeated(true);
    setTexture(texture);
}


void Background::updateTexturePositions(float x, float y)
//moves texture coordinates by x, y
{
    texturePosX -= x;
    texturePosY -= y;
    sf::IntRect textureRect = getTextureRect();
    textureRect.left = texturePosX;
    textureRect.top = texturePosY;   
    setTextureRect(textureRect);
}

void Background::fillTheWindow(sf::Vector2u windowSize)
{
    setTextureRect(sf::IntRect(texturePosX, texturePosY, windowSize.x, windowSize.y));
}