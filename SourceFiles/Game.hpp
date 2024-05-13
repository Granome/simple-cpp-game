#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>

#include "Player.hpp"
#include "EnemyTypes.hpp"
#include "InputManager.hpp"
#include "MovementManager.hpp"

class Game
{
private:
    std::vector<std::unique_ptr<sf::Drawable>> gameObjects;
    int currentDifficulty;
    double totalTime;
    float timeScale=1;
    sf::RenderWindow window;
    sf::Clock clock;
    InputManager inputManager; // not used yet
    MovementManager movementManager;


    void GameLoop();
    void DrawFrame();
public:
    Game();
    void start();
    void update();
};