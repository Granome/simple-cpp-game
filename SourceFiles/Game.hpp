#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>

#include "Player.hpp"
#include "EnemyTypes.hpp"
#include "InputManager.hpp"
#include "MovementManager.hpp"
#include "HealthBar.hpp"
#include "XpBar.hpp"
#include "EnemySpawner.hpp"

class Game
{
private:
    std::vector<std::unique_ptr<sf::Drawable>> gameObjects;
    std::vector<std::unique_ptr<sf::Drawable>> uiObjects;

    double totalTime;
    float timeScale=1;
    sf::RenderWindow window;
    sf::Vector2f windowCentre;
    sf::Clock clock;
    InputManager inputManager; // not used yet
    MovementManager movementManager;
    EnemySpawner enemySpawner;
    int currentDifficultyPoints;


    void GameLoop();
    void DrawFrame();
public:
    Game();
    void start();
    void update();
    void checkEnemyAttacks();
    void handleShooting(sf::Time elapsed);
    sf::Vector2f findWindowCentre(sf::RenderWindow& window);
    void checkBulletHits();
    void updateHealthBar();
    void updateXPBar(EnemySpawner enemySpawner);
};