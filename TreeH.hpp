#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <random>
#include <ctime>
#pragma once

class Tree;
class Player;

// ***************************************************************************************
// TREE CLASS
// ***************************************************************************************
class Tree
{

private:
    std::string type;
    int length, maxBark, currBark, attMax, defMax, accMax, evaMax;
    bool veryTall, veryShort;

public:
    Tree(std::string type = "", int length = 0)
    {
        this->type = type;
        this->length = length;
        setStats();
    }

    std::string getType();
    int getLength();
    void setStats();
    int attack();
    int getBark();
    int barkLost(Tree playerTree);
    void gainBark(Player player);
    int getMaxAttack();
    int getMaxDefense();
    int getMaxAccuracy();
    int getMaxEvasiveness();
    bool getIsTiny();
    bool getIsHuge();
    void setStatsManually(std::string type, int length, int currBark, int attMax, int defMax, int accMax, int evaMax, bool veryTall, bool veryShort);
};

// ***************************************************************************************
// PLAYER CLASS
// ***************************************************************************************
class Player
{

private:
    std::string name;
    int woodBandages, money, treesChopped = 0;

public:
    Player(std::string name, int woodBandages, int money)
    {
        this->name = name;
        this->woodBandages = woodBandages;
        this->money = money;
    }

    std::string getName();
    int getWoodBandages();
    int getMoney();
    int getTreesChopped();
    void setName(std::string name);
    void setWoodBandages(int woodBandages);
    void setMoney(int money);
    void setTreesChopped(int treesChopped);
};

void fightPhase(std::stack<Tree> &treeStack, Player &player);
std::stack<Tree> getEnemies(int numOfEnemies);