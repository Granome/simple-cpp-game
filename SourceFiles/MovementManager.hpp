/*
Manages Movement off all objects around the player,
as well as their animations

*/



#pragma once

#include "Player.hpp"
#include "EnemyTypes.hpp"
#include "Bullet.hpp"
#include "InputManager.hpp"
#include "Background.hpp"
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
    //Moves enemies towards the player
    void moveEnemies(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects, sf::Time elapsed, const float& timeScale, sf::Vector2f playerPos);
    //Moves sf::IntRect for background texture. Moves background texture 
    void moveBackground(Background bg, sf::Time elapsed, const float& timeScale, sf::Vector2f movementVector);
    //Moves player (all objects using player movement vector)
    void movePlayer(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects, sf::Time elapsed, const float& timeScale);
    //Moves bullets
    void moveBullets(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects, sf::Time elapsed, const float& timeScale);
    
};
