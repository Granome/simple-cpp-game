/*
Manages Movement off all objects around the player,
as well as their animations

*/



#pragma once

#include "Player.hpp"
#include "EnemyTypes.hpp"
#include "InputManager.hpp"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>



class MovementManager
{
private:
    InputManager inputManager;
public:
    //Moves and  animates all objects, depending on time scale
    void drawGameObjects(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects, sf::Time elapsed, const float& timeScale);
    
};