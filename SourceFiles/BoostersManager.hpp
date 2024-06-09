#pragma once
#include "Player.hpp"
#include "Booster.hpp"

#include <algorithm>
#include <unordered_set>
#include <memory>
#include <vector>

class BoostersManager
{
private:
    std::vector<std::unique_ptr<sf::Drawable>>& gameObjects;
    std::vector<std::unique_ptr<Booster>> boosters;
    std::vector<std::unique_ptr<Booster>> boostersToChoose;
    bool boosterChoosing = false;
    int currentHighlited = 0;

    sf::Vector2f highlitedScale = sf::Vector2f(1.2, 1.2);
    sf::Vector2f normalScale = sf::Vector2f(1, 1);

    InfoBox infoBox = sf::Vector2f(550, 100);


public:
    BoostersManager(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects_);

    bool isChoosingBooster() { return boosterChoosing; }

    void fearlessBastard();
    void glassCannon();
    std::vector<std::unique_ptr<Booster>> chooseThreeBasedOnRarity();
    void handleEvents(sf::Event e);
    void highlightBooster(Booster& booster);
    void displayBoostersMenu(sf::RenderTarget& target, sf::RenderStates states);
    void setBoostersToChoose(std::vector<std::unique_ptr<Booster>>& boostersToChoose_);
    void setBoosterChoosing(bool boosterChoosing_ = true) { boosterChoosing = boosterChoosing_; }
    void activateBooster();
};