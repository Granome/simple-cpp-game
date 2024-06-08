#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio/Music.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>


#include "Player.hpp"
#include "EnemyTypes.hpp"
#include "InputManager.hpp"
#include "MovementManager.hpp"
#include "HealthBar.hpp"
#include "XpBar.hpp"
#include "GameOverText.hpp"
#include "EnemySpawner.hpp"
#include "Console.hpp"

class Game
{
private:
    std::vector<std::unique_ptr<sf::Drawable>> gameObjects;
    std::vector<std::unique_ptr<sf::Drawable>> uiObjects;

    double totalTime = 0;
    double inGameTime = 0;
    float timeScale=1;
    float timeSlowerDomain=1; // x of exponential function

    bool timeSlowing = false; //slows time if true

    bool gameIsOver = false;

    sf::RenderWindow window;
    sf::Music music;
    sf::Vector2f windowCentre;
    sf::Clock clock;
    InputManager inputManager;
    MovementManager movementManager;
    EnemySpawner enemySpawner;
    Console console = Console(0, 400, 800, 200, gameObjects);



    void GameLoop();
    void DrawFrame();
public:
    Game();
    void start();
    void update();
    void gameOver();
    void checkEnemyAttacks();
    void checkPlayerDeath();
    void handleShooting(sf::Time elapsed);
    sf::Vector2f findWindowCentre(sf::RenderWindow& window);
    void checkBulletHits();
    void updateHealthBar();
    void updateXPBar(EnemySpawner enemySpawner);

    void exponentialTimeSlower(sf::Time elapsed, bool slowing);

    void setTimeSlowing(bool isSlowing);

    void resetAllParameters();

};