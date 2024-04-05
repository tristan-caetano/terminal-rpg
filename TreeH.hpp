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
    int getMaxAccuracy();
    int getDefense();
    int getMaxEvasiveness();
};

// ***************************************************************************************
// PLAYER CLASS
// ***************************************************************************************
class Player
{

private:
    std::string name;
    int woodBandages, money;

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
    void setWoodBandages(int woodBandages);
    void setMoney(int money);
};

void fightPhase(std::stack<Tree> &treeStack, Player &player);
std::stack<Tree> getEnemies(int numOfEnemies);