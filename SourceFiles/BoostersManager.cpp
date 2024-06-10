#include "BoostersManager.hpp"


sf::Texture t;
sf::Texture blank;
sf::Texture fearless_bastard_t;
sf::Texture glass_cannon_t;
sf::Texture hit_the_gym_t;
sf::Texture limpy_sniper_t;
sf::Texture my_daddies_rapiers_t;
sf::Texture my_teeth_are_sharp_t;
sf::Texture one_of_the_edema_ruh_t;
sf::Texture requiescat_in_pace_t;
sf::Texture son_of_a_gun_t;
sf::Texture tra_ta_ta_t;
sf::Texture try_catch_me_t;
sf::Texture shotgun_t;


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
            p->setMovementSpeed(p->getMovementSpeed()*0.6);
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
            p->setMovementSpeed(p->getMovementSpeed()*1.4);
        }
    }
}

void BoostersManager::hitTheGym()
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
            p->setDamage(p->getDamage()*1.4);
            p->setMovementSpeed(p->getMovementSpeed()*1.2);
        }
    }
}

void BoostersManager::limpySniper()
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
            p->setDamage(p->getDamage()*2);
            p->setMovementSpeed(p->getMovementSpeed()*0.85);
            p->setBulletRange(p->getBulletRange()*2.5);
            p->setBulletVelocity(p->getBulletVelocity()*3);
        }
    }
}

void BoostersManager::myDaddiesRapiers()
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
            p->setBulletPenetration(true);
        }
    }
}

void BoostersManager::myTeethAreSharp()
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
            p->setDamage(p->getDamage()*1.35);
            p->setBulletRange(p->getBulletRange()*0.3);
            p->setMovementSpeed(p->getMovementSpeed()*1.1);
            p->setBulletVelocity(p->getBulletVelocity()*1.4);
        }
    }
}

void BoostersManager::oneOfTheEdemaRuh()
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
            p->setCriticalHitChance(p->getCriticalHitChance()+0.3);
            p->setCriticalDamageCoefficient(p->getCriticalDamageCoefficient()*1.5);
            p->setBulletRange(p->getBulletRange()*0.4);
            p->setMovementSpeed(p->getMovementSpeed()*1.1);

        }
    }
}

void BoostersManager::requiescatInPace()
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
            p->setCriticalHitChance(p->getCriticalHitChance()+0.3);
            p->setCriticalDamageCoefficient(p->getCriticalDamageCoefficient()*2);
            p->setBulletRange(p->getBulletRange()*2);

        }
    }
}

void BoostersManager::sonOfAGun()
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
            p->setCriticalDamageCoefficient(p->getCriticalDamageCoefficient()+0.2);
            p->setBulletVelocity(p->getBulletVelocity()*1.4);
            p->setDamage(p->getDamage()*1.4);
        }
    }
}

void BoostersManager::traTaTa()
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
            p->setCriticalHitChance(0);
            p->setBulletVelocity(p->getBulletVelocity()*1.4);
            p->setDamage(p->getDamage()*0.1);
            p->setMovementSpeed(p->getMovementSpeed()*1.1);
            p->setAttackSpeed(p->getAttackSpeed()*10);
        }
    }
}

void BoostersManager::tryToCatchMeSlowpoke()
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
            p->setCriticalHitChance(p->getCriticalHitChance()+0.2);
            p->setMaxHP(p->getMaxHp()*0.5);
            p->setMovementSpeed(p->getMovementSpeed()*1.2);
        }
    }
}

void BoostersManager::weHaveAShotgunAtHome()
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
            p->setMovementSpeed(p->getMovementSpeed()*0.9);
            p->setBullets({-15, -10, -5, 0, 5, 10, 15});
            p->setBulletRange(p->getBulletRange()*0.35);
            p->setAttackSpeed(p->getAttackSpeed()*1.3);
            p->setBulletVelocity(p->getBulletVelocity()*1.4);
            p->setDamage(p->getDamage()*0.18);
        }
    }
}


BoostersManager::BoostersManager(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects_) : gameObjects(gameObjects_)
{
    auto fearlessBastard_ = std::make_unique<Booster>([&]() { fearlessBastard(); }, 5, "Fearless bastard", "A bit less movement\nspeed\nA bit more damage");
    auto hit_the_gym_ = std::make_unique<Booster>([&]() { hitTheGym(); }, 5, "Hit the gym", "A bit more damage\nA bit more movement\nspeed");
    auto glassCannon_ = std::make_unique<Booster>([&]() { glassCannon(); }, 4, "Glass cannon", "MUCH less HP\nTriple damage\nMuch more speed");
    auto limpy_sniper = std::make_unique<Booster>([&]() { limpySniper(); }, 4, "Limpy sniper", "Much more damage\nMuch less movement\nspeed\nMuch bigger bullet range\nBullets are much faster");
    auto try_catch_me = std::make_unique<Booster>([&]() { tryToCatchMeSlowpoke(); }, 4, "Can't catch me!", "Bigger critical chance\nMUCH more movement\nspeed\nTwice less HP");
    auto my_teeth_are_sharp = std::make_unique<Booster>([&]() { myTeethAreSharp(); }, 2, "My teeth are SHARK", "A bit more damage\nMuch smaller bullet range\nA bit more speed\nA bit faster bullets");
    auto son_of_a_gun = std::make_unique<Booster>([&]() { sonOfAGun(); }, 2, "Son of a gun", "A bit more damage\nBigger critical damage\nMuch faster bullets");
    auto one_of_the_edema_ruh = std::make_unique<Booster>([&]() { oneOfTheEdemaRuh(); }, 2, "The Edema Ruh", "Bigger critical chance\nBigger critical damage\nA bit mere speed\nSmaller bullet range");
    auto shotgun = std::make_unique<Booster>([&]() { weHaveAShotgunAtHome(); }, 2, "SHOT!gun", "Shotgun shooting patern\nLess movement speed\nFaster bullets\nMuch shorter bullet range\nA bit faster attask speed");
    auto my_daddies_rapiers = std::make_unique<Booster>([&]() { myDaddiesRapiers(); }, 1, "My dadies rapiers", "Bullets pierce\nthrough enemies");
    auto requiescat_in_pace = std::make_unique<Booster>([&]() { requiescatInPace(); }, 1, "Requiescat in pace", "Double critical damage\nMuch more critical chance\nDouble bullet range");
    auto tra_ta_ta = std::make_unique<Booster>([&]() { traTaTa(); }, 1, "Trra-ta-ta-ta-ta!!!", "MUCH faster shooting\nA bit more movement\nspeed\nA bit faster bullets\nCritical chanse = 0\nMUCH smaller damage");

    // Ensure texture loading

    if (!t.loadFromFile("../Resourses/Textures/BoosterCards/boosterEmpty.jpg")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!blank.loadFromFile("../Resourses/Textures/BoosterCards/card_blank.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!glass_cannon_t.loadFromFile("../Resourses/Textures/BoosterCards/glass_cannon.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!fearless_bastard_t.loadFromFile("../Resourses/Textures/BoosterCards/fearless_bastard.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!hit_the_gym_t.loadFromFile("../Resourses/Textures/BoosterCards/hit_the_gym.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!limpy_sniper_t.loadFromFile("../Resourses/Textures/BoosterCards/limpy_sniper.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!my_daddies_rapiers_t.loadFromFile("../Resourses/Textures/BoosterCards/my_daddies_rapiers.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!my_teeth_are_sharp_t.loadFromFile("../Resourses/Textures/BoosterCards/my_teeth_are_sharp.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!one_of_the_edema_ruh_t.loadFromFile("../Resourses/Textures/BoosterCards/one_of_the_edema_ruh.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!requiescat_in_pace_t.loadFromFile("../Resourses/Textures/BoosterCards/requiescat_in_pace.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!son_of_a_gun_t.loadFromFile("../Resourses/Textures/BoosterCards/son_of_a_gun.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!tra_ta_ta_t.loadFromFile("../Resourses/Textures/BoosterCards/tra_ta_ta.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    if (!try_catch_me_t.loadFromFile("../Resourses/Textures/BoosterCards/try_to_catch_me_slowpoke.png")) {
    std::cerr << "Failed to load texture" << std::endl;
    }    
    if (!shotgun_t.loadFromFile("../Resourses/Textures/BoosterCards/we_have_a_shotgun_at_home.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    }

    
    fearlessBastard_->setTexture(fearless_bastard_t);
    glassCannon_->setTexture(glass_cannon_t);
    hit_the_gym_->setTexture(hit_the_gym_t);
    limpy_sniper->setTexture(limpy_sniper_t);
    my_daddies_rapiers->setTexture(my_daddies_rapiers_t);
    my_teeth_are_sharp->setTexture(my_teeth_are_sharp_t);
    one_of_the_edema_ruh->setTexture(one_of_the_edema_ruh_t);
    requiescat_in_pace->setTexture(requiescat_in_pace_t);
    son_of_a_gun->setTexture(son_of_a_gun_t);
    tra_ta_ta->setTexture(tra_ta_ta_t);
    try_catch_me->setTexture(try_catch_me_t);
    shotgun->setTexture(shotgun_t);

    infoBox.setBgTexture(blank);


    boosters.push_back(std::move(fearlessBastard_));
    boosters.push_back(std::move(glassCannon_));
    boosters.push_back(std::move(hit_the_gym_));
    boosters.push_back(std::move(limpy_sniper));
    boosters.push_back(std::move(my_daddies_rapiers));
    boosters.push_back(std::move(my_teeth_are_sharp));
    boosters.push_back(std::move(one_of_the_edema_ruh));
    boosters.push_back(std::move(requiescat_in_pace));
    boosters.push_back(std::move(son_of_a_gun));
    boosters.push_back(std::move(tra_ta_ta));
    boosters.push_back(std::move(try_catch_me));
    boosters.push_back(std::move(shotgun));
    

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
