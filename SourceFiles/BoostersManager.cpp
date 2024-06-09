#include "BoostersManager.hpp"


sf::Texture t;
sf::Texture blank;


void BoostersManager::fearlessBastard()
{
    for (const auto& gameObject : gameObjects)
    {
        if (!gameObject)
        {
            std::cerr << "Null pointer found in gameObjects" << std::endl;
            continue;
        }
        if (Player* p = dynamic_cast<Player*>(gameObject.get()))
        {
            p->setMovementSpeed(p->getMovementSpeed()*0.8);
            p->setDamage(p->getDamage()*1.2);
        }
    }
}

void BoostersManager::glassCannon()
{
    for (const auto& gameObject : gameObjects)
    {
        if (!gameObject)
        {
            std::cerr << "Null pointer found in gameObjects" << std::endl;
            continue;
        }
        if (Player* p = dynamic_cast<Player*>(gameObject.get()))
        {
            p->setMaxHP(p->getMaxHp()*0.1);
            p->setDamage(p->getDamage()*3);
        }
    }
}



BoostersManager::BoostersManager(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects_) : gameObjects(gameObjects_)
{
    auto fearlessBastard_ = std::make_unique<Booster>([&]() { fearlessBastard(); }, 1, "Fearless bastard", "A bit less movement\nspeed\nA bit more damage");
    auto glassCannon_ = std::make_unique<Booster>([&]() { glassCannon(); }, 2, "Glass cannon", "MUCH less HP\nTriple damage");
    auto glassCannon2_ = std::make_unique<Booster>([&]() { glassCannon(); }, 2, "Glass cannonnnnnnn", "MUCH less HP\nTriple damage");

    // Ensure texture loading

    if (!t.loadFromFile("../Resourses/Textures/BoosterCards/boosterEmpty.jpg")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!blank.loadFromFile("../Resourses/Textures/BoosterCards/card_blank.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    
    fearlessBastard_->setTexture(t);
    glassCannon_->setTexture(t);
    glassCannon2_->setTexture(t);

    infoBox.setBgTexture(blank);

    boosters.push_back(std::move(fearlessBastard_));
    boosters.push_back(std::move(glassCannon_));
    boosters.push_back(std::move(glassCannon2_));
    

}


std::vector<std::unique_ptr<Booster>> BoostersManager::chooseThreeBasedOnRarity()
{
    std::vector<std::unique_ptr<Booster>> chosenBoosters;
    std::vector<double> cumulativeWeights;
    double totalWeight = 0.0;

    // Calculate cumulative weights
    for (auto& bs : boosters)
    {
        totalWeight += bs->getRarity();
        cumulativeWeights.push_back(totalWeight);
    }

    // Ensure the vector has at least 3 elements
    if (boosters.size() < 3)
    {
        std::cerr << "Not enough elements to choose 3 unique objects." << std::endl;
        return chosenBoosters;
    }

    // Select 3 unique elements
    std::unordered_set<int> selectedIndices;

    while (selectedIndices.size() < 3)
    {
        double r = static_cast<double>(std::rand()) / RAND_MAX * totalWeight;
        auto it = std::lower_bound(cumulativeWeights.begin(), cumulativeWeights.end(), r);
        int index = std::distance(cumulativeWeights.begin(), it);

        if (selectedIndices.find(index) == selectedIndices.end())
        {
            selectedIndices.insert(index);
            chosenBoosters.push_back(std::make_unique<Booster>(*boosters[index]));
        }
    }

    return chosenBoosters;
}


void BoostersManager::handleEvents(sf::Event event)
{
    if (boosterChoosing)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Left)
            {
                currentHighlited--;
                if (currentHighlited == -1)
                    currentHighlited = 2;
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                currentHighlited++;
                if (currentHighlited == 3)
                    currentHighlited = 0;
            }
            if (event.key.code == sf::Keyboard::Enter)
            {
                activateBooster();
            }
        }
    }
}


void BoostersManager::setBoostersToChoose(std::vector<std::unique_ptr<Booster>>& boostersToChoose_)
{
    boostersToChoose.clear();
    for (auto& booster : boostersToChoose_)
    {
        boostersToChoose.push_back(std::move(booster));
    }
}


void BoostersManager::displayBoostersMenu(sf::RenderTarget& target, sf::RenderStates states)
{
    if (boosterChoosing)
    {

        
        if (boostersToChoose.size() < 3)
        {
            std::cout << "Not enough boosters";
            boosterChoosing = false;
            return;
        }
        float xDisplaysment = 0;

        infoBox.setName(boostersToChoose[currentHighlited]->getName());
        infoBox.setDescription(boostersToChoose[currentHighlited]->getDescription());
        //std::cout << boostersToChoose[i]->getName() + ": " + boostersToChoose[i]->getDescription();
        infoBox.positionTexts();
        infoBox.setTextColorFromRarity(boostersToChoose[currentHighlited]->getRarity());
        target.draw(infoBox);



        for (int i = 0; i < 3; i++)
        {
            boostersToChoose[i]->setShown(true);
            boostersToChoose[i]->setPosition(100 + xDisplaysment, 100);
            boostersToChoose[i]->setHighlited(false);
            if (i == currentHighlited)
            {
                boostersToChoose[i]->setHighlited(true);
            }
            else
            {
                boostersToChoose[i]->setHighlited(false);
            }

            if (boostersToChoose[i]->isHighlited())
            {
                boostersToChoose[i]->setScale(highlitedScale);

                infoBox.setName(boostersToChoose[i]->getName());
                infoBox.setDescription(boostersToChoose[i]->getDescription());
                //std::cout << boostersToChoose[i]->getName() + ": " + boostersToChoose[i]->getDescription();
                infoBox.positionTexts();
                infoBox.setTextColorFromRarity(boostersToChoose[i]->getRarity());
                target.draw(infoBox);
            }
            else
            {
                boostersToChoose[i]->setScale(normalScale);
            }
            target.draw(*boostersToChoose[i], states);

            xDisplaysment += boostersToChoose[i]->getGlobalBounds().width + 20;
        }  
    }
}


void BoostersManager::activateBooster()
{
    boostersToChoose[currentHighlited]->ability_();
    boosterChoosing = false;
}
