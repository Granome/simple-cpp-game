#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window.hpp>
#include <cmath>

class InputManager
{
private:
public:
    //Returns vector of values from -1 to 1, based on Keyboard input \
    - WASD. First value represents \
    movement on x, second - on y. Result vector is normalised.
    sf::Vector2f getMovementVectorFromWASD();
    

    //Normalizes Vector2f
    sf::Vector2f normalizeVector2(const sf::Vector2f& vector);
};
