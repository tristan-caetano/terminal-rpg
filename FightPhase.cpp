#include "TreeH.hpp"

void fightPhase(std::stack<Tree> &treeStack, Player &player);
std::stack<Tree> getEnemies(int numOfEnemies);

void fightPhase(std::stack<Tree> &treeStack, Player &player)
{

    std::stack<Tree> enemyStack = getEnemies(treeStack.size());
    int userIn;
    int currAtt;
    bool fight = true;

    // Initializing players
    Tree playerCurrTree = treeStack.top();
    treeStack.pop();
    Tree enemyCurTree = enemyStack.top();
    enemyStack.pop();

    // Keeping track of enemy health to calulate money awarded
    int enemyTotalHealth = enemyCurTree.getBark();

    // Do while for the actual fight
    do
    {

        // Fight menu
        std::cout << "\n********************FIGHT MENU********************";
        std::cout << "\n"
                  << (player.getName()) << "'s Tree: " << playerCurrTree.getType() << "\nPlayer Bark: " << playerCurrTree.getBark();
        std::cout << "\nEnemy Tree: " << enemyCurTree.getType() << "\nEnemy Bark: " << enemyCurTree.getBark();
        std::cout << "\n\n1). Standard Chop\n2). Regain Bark\n";
        std::cout << "********************FIGHT MENU********************\n";
        std::cin >> userIn;
        switch (userIn)
        {
        case 1:
            std::cout << "\nWoah, you chopped and " << enemyCurTree.getType() << " lost " << enemyCurTree.barkLost(playerCurrTree) << " bark.";
            std::cout << "\nYikes, " << enemyCurTree.getType() << " chopped your " << playerCurrTree.getType() << ", and it lost " << playerCurrTree.barkLost(enemyCurTree) << " bark.\n";
            break;
        case 2:
            player.setWoodBandages(-1);
            playerCurrTree.gainBark(player);
            std::cout << "\nYou gave your " << playerCurrTree.getType() << " a wood bandage.\nIt now has " << playerCurrTree.getBark() << " bark.";
            break;
        default:
            std::cout << "\nBro that is NOT an option.\n";
            break;
        }

        // PLAYER IF STATEMENT
        // If the current player tree dies and the player still has trees left, get the next one
        if (!treeStack.empty() && playerCurrTree.getBark() < 1)
        {
            std::cout << playerCurrTree.getType() << " has been cut down!\n";
            playerCurrTree = treeStack.top();
            treeStack.pop();
            std::cout << "Sending out " << playerCurrTree.getType() << "!\n";
        }
        // If the current player tree dies, and the player doesn't have another tree, they lose
        else if (treeStack.empty() && playerCurrTree.getBark() < 1)
        {
            std::cout << "You are out of trees! You got kronglesnopped bruh :(\n)";
            fight = false;
        }

        // ENEMY IF STATEMENT
        // If the current enemy tree dies and the enemy still has trees left, get the next one
        if (!enemyStack.empty() && enemyCurTree.getBark() < 1)
        {
            std::cout << "You chopped " << enemyCurTree.getType() << "!\n";
            enemyCurTree = enemyStack.top();
            enemyStack.pop();
            std::cout << "Uh oh, they're sending out " << enemyCurTree.getType() << "!\n";
            enemyTotalHealth += enemyCurTree.getBark();
        }
        // If the current enemy tree dies, and the enemy doesn't have another tree, they lose
        else if (enemyStack.empty() && enemyCurTree.getBark() < 1)
        {
            std::cout << "\nYou chopped all the enemy trees! It's epic time. B)\n";
            std::cout << "You got " << enemyTotalHealth << " money! Very cool.\n";
            player.setMoney(enemyTotalHealth);
            treeStack.push(playerCurrTree);
            fight = false;
        }

        // The fight continues until either the enemy stack and player stack is empty
    } while (fight);
}

// Creating enemies
std::stack<Tree> getEnemies(int numOfEnemies)
{
    // Declaring variables
    std::stack<Tree> enemyStack;
    std::string enemyNames[7] = {"Oak", "Birch", "Evergreen", "Pine", "Redwood", "Willow", "Yew"};
    int i;
    int rando = rand() % 7;

    // For loop creating enemies based on how many trees the player has
    for (i = 0; i < numOfEnemies; i++)
    {
        // Creating tree object
        srand(time(NULL));
        Tree tree(enemyNames[rand() % 7], rand() % 101);

        if(!enemyStack.empty()){

            while((tree.getType()) == (enemyStack.top().getType())){

                srand(time(NULL));
                Tree tree(enemyNames[rand() % 7], rand() % 101);

            }
        }

        enemyStack.push(tree);

        
    }

    return enemyStack;
}