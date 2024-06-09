#pragma once

#include <SFML/Graphics.hpp>

class FontStorer
{
public:
    sf::Font font;
    FontStorer()
    {
        font.loadFromFile("../Resourses/Textures/PixelifySans-Medium.ttf");
    }
};

extern FontStorer font_;

class UiElement : public sf::Sprite
{
protected:
    sf::Font font = font_.font;

public:
    virtual ~UiElement() {}
};

