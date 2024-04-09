#include <cstdlib>
#include "TreeH.hpp"

// ***************************************************************************************
// TREE CLASS PROPERTIES
// ***************************************************************************************

// Returning tree type
std::string Tree::getType() { return type; }

// Get tree length
int Tree::getLength() { return length; }

// Get health
int Tree::getBark() { return currBark; }

// Get max attack
int Tree::getMaxAttack(){ return attMax; }

// Get defense
int Tree::getMaxDefense() { return defMax; }

// Get max accuracy
int Tree::getMaxAccuracy() { return accMax; }

// Get max evasiveness
int Tree::getMaxEvasiveness() { return evaMax; }

// Get if tree is big or small
bool Tree::getIsTiny(){ return veryShort; }
bool Tree::getIsHuge(){ return veryTall; }


// Setter for everything
void Tree::setStatsManually(std::string type, int length, int currBark, int attMax, int defMax, int accMax, int evaMax, bool veryTall, bool veryShort){
    this->type = type;
    this->length = length;
    this->currBark = currBark;
    this->attMax = attMax;
    this->defMax = defMax;
    this->accMax = accMax;
    this->evaMax = evaMax;
    this->veryTall = veryTall;
    this->veryShort = veryShort;
}

// Calculating damage inflicted
int Tree::attack()
{
    srand(time(0));
    return (rand() % (attMax + 1));
}

// Calculating how much damage is taken
int Tree::barkLost(Tree playerTree)
{

    // Declaring variables
    srand(time(0));
    int defRoll = rand() % (defMax + 1);
    int damageBlocked;
    int isHit = (rand() % (playerTree.getMaxAccuracy() + 1)) - (rand() % (evaMax + 1));
    int barkLost = 0;

    // Determining damage taken
    if (isHit > 0)
    {
        barkLost = (playerTree.attack() * 10) / defRoll;
        currBark -= barkLost;
    }

    return barkLost;
}

// Initializing the stats of the tree based on the length
void Tree::setStats()
{

    srand(time(NULL));

    // Determining tree height extremes for additional attributes
    if (length >= 90)
    {
        veryTall = true;
    }
    else if (length <= 10)
    {
        veryShort = true;
    }
    else
    {
        veryTall = false;
        veryShort = false;
    }

    // Taller tree: High attack and defense
    // Shorter tree: High evasiveness and accuracy

    // Calculating max attack, defense, accuracy, and evasiveness
    maxBark = length * 10;
    attMax = length * 10;
    defMax = length;

    accMax = 101 - (rand() % length);

    srand(time(0));
    evaMax = 101 - (rand() % length);

    srand(time(0));
    currBark = rand() % (maxBark + 1);
}

// Healing tree
void Tree::gainBark(Player player)
{
    if (player.getWoodBandages() > 0)
    {
        currBark += 50;
        if (currBark > maxBark)
        {
            currBark = maxBark;
        }
        player.setWoodBandages(-1);
    }
    else
    {
        std::cout << "Bro you do NOT have any bandages left.\n";
    }
}

// Set health manually
void Tree::setBark(int currBark){ this->currBark = currBark; }

// ***************************************************************************************
// PLAYER CLASS PROPERTIES
// ***************************************************************************************

// Returning player name
std::string Player::getName() { return name; }

// Returning healing items
int Player::getWoodBandages() { return woodBandages; };

// Returning money
int Player::getMoney() { return money; };

// Returning Trees Chopped
int Player::getTreesChopped(){ return treesChopped; }

// Getting the current seed
Seed Player::getSeed(){ return seed; }

// Set player name manually from save
void Player::setName(std::string name){ this->name = name; }

// Adding healing items
void Player::setWoodBandages(int woodBandages) { this->woodBandages = woodBandages; }

// Adding money
void Player::setMoney(int money) { this->money = money; }

// Setting trees chopped
void Player::setTreesChopped(int treesChopped){ this->treesChopped = treesChopped;}

// Setting the seed for the player
void Player::setSeed(Seed seed){ this->seed = seed; }

// ***************************************************************************************
// SEED CLASS PROPERTIES
// ***************************************************************************************

Tree HealthSeed::seedSkill(Tree tree){
        
        tree.setBark(tree.getBark() * 2);
        used = true;
        return tree;
    }