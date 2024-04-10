#include "TreeH.hpp"

// Prototyping
void printTreeInfo(Tree tree);
Tree getUserTree();
void saveGame(std::stack<Tree> treeStack, Player player);
void loadGame(std::stack<Tree> &treeStack, Player &player);
void viewTrees(std::stack<Tree> treeStack);
void mainMenu(Player player);
Player createPlayer();
void loadSeed(int seedLoadIndicator, Player &player);

int main()
{

    srand(time(0));
    // Displaying the main menu for the user
    mainMenu(createPlayer());

    return (0);
}

// Main Menu
void mainMenu(Player player)
{

    // Declaring variables
    bool toContinue = true;
    int userIn;
    std::stack<Tree> treeStack;

    // Do While loop that displays the menu
    do
    {
        std::cout << "\n*********TREE MENU**********"
                  << "\nWhat would you like to do?\n"
                  << "\n1). FIGHT!"
                  << "\n2). Create a new tree. (100 M)"
                  << "\n3). View Trees."
                  << "\n4). Go to the store."
                  << "\n5). View Inventory."
                  << "\n6). Save game to file."
                  << "\n7). Load game from file."
                  << "\n8). Quit. (Unsaved progress will be lost.)"
                  << "\n*********TREE MENU**********\n";

        // Getting user input for menu selection
        std::cin >> userIn;

        // Switch statement that sends the user where they want to go
        switch (userIn)
        {
            // FIGHT!
        case 1:
            if (!treeStack.empty())
            {
                fightPhase(treeStack, player);
            }
            else
            {
                std::cout << "\nYou have no trees goofy!\n";
            }
            break;
            // Create a new tree.
        case 2:
            if (player.getMoney() > 99)
            {
                player.setMoney(player.getMoney() - 100);
                treeStack.push(getUserTree());
                std::cout << "\n"
                          << !treeStack.empty();
            }
            else
            {
                std::cout << "\nYou don't have enough cash money bro.\n";
            }
            break;
            // View trees.
        case 3:
            if (!treeStack.empty())
            {
                viewTrees(treeStack);
            }
            else
            {
                std::cout << "\nYou have no trees goofy!\n";
            }
            break;
            // Buy Wood Bandages.
        case 4:
            //store(treeStack, player);
            break;
            // View Inventory
        case 5:
            std::cout << "\nWood Bandages: " << player.getWoodBandages() << "\nMoney: " << player.getMoney() << "\nSeed: " << player.getSeed().getName() << "\n";
            break;
            // Save game to file
        case 6:
            saveGame(treeStack, player);
            break;
            // Load save from file
        case 7:  
            loadGame(treeStack, player);
            break;
            // Quit
        case 8:
            toContinue = false;
            break;
        default:
            std::cout << "\nBro that is NOT an option.\n";
            break;
        }
    } while (toContinue);
}

// Printing tree info
void printTreeInfo(Tree tree)
{
    std::cout << tree.getType()
              << "\nLength: " << tree.getLength()
              << "\nBark: " << tree.getBark()
              << "\nDefense: " << tree.getMaxDefense()
              << "\nAccuracy: " << tree.getMaxAccuracy()
              << "\nEvasiveness: " << tree.getMaxEvasiveness()
              << "\n";
}

// Asking user for the tree info
Tree getUserTree()
{

    // Declaring Variables
    int length;
    std::string type;

    // Asking user info about the tree
    std::cout << "\nWhat type of tree is it?\n";
    std::cin >> type;

    // Making sure the user sets an appropriate height for the tree
    do
    {
        std::cout << "\nHow tall is the tree (ft)?\n(Choose a value between 1 and 100 inclusive.)\n";
        std::cin >> length;

    } while ((length > 101) || (length < 0));

    // Creating tree object
    Tree tree(type, length);

    // Returning tree object
    return tree;
}

// Saving all created trees to a file
void saveGame(std::stack<Tree> treeStack, Player player)
{

    // Declaring variables
    std::fstream file;
    file.open("Trees.tc", std::ios::out);

    // Saving Player
    file << player.getName() << "\n";
    file << player.getTreesChopped() << "\n";
    file << player.getMoney() << "\n";
    file << player.getWoodBandages() << "\n";
    file << player.getSeed().getLoadIndicator() << "\n";

    // Treestack is saved until its empty
    while (!treeStack.empty())
    {
        // Getting top value, then popping it off the stack
        Tree tree = treeStack.top();
        treeStack.pop();

        // Saving data of popped tree to the file
        file << tree.getType() << "\n";
        file << tree.getLength() << "\n";
        file << tree.getBark() << "\n";
        file << tree.getMaxAttack() << "\n";
        file << tree.getMaxDefense() << "\n";
        file << tree.getMaxAccuracy() << "\n";
        file << tree.getMaxEvasiveness() << "\n";
        file << tree.getIsTiny() << "\n";
        file << tree.getIsHuge() << "\n";
    }

    // Closing the file
    file.close();

    // Telling user the file was output to successfully
    std::cout << "\nFile Tree.tc was created!\n";
}

// Saving all created trees to a file
void loadGame(std::stack<Tree> &treeStack, Player &player)
{

    // Declaring variables
    std::fstream file;
    file.open("Trees.tc", std::ios::in);
    std::string nameStr = "INIT", tempStr;
    int tempInt[6];
    bool tempBool[2];
    
    // Saving Player
    std::getline(file, tempStr);
    player.setName(tempStr);

    std::getline(file, tempStr);
    player.setTreesChopped(stoi(tempStr));

    std::getline(file, tempStr);
    player.setMoney(stoi(tempStr));

    std::getline(file, tempStr);
    player.setWoodBandages(stoi(tempStr));

    std::getline(file, tempStr);
    loadSeed(stoi(tempStr), player);
    player.getSeed().cringe();

    Tree tree("TEMP", 99);

    tempStr = "1";

    // Treestack is saved until its empty
    while (nameStr != "")
    {


        // Saving data of popped tree to the file
        std::getline(file, nameStr);
        if(nameStr != ""){

            std::getline(file, tempStr);
            tempInt[0] = stoi(tempStr);
            std::getline(file, tempStr);
            tempInt[1] = stoi(tempStr);
            std::getline(file, tempStr);
            tempInt[2] = stoi(tempStr);
            std::getline(file, tempStr);
            tempInt[3] = stoi(tempStr);
            std::getline(file, tempStr);
            tempInt[4] = stoi(tempStr);
            std::getline(file, tempStr);
            tempInt[5] = stoi(tempStr);
            std::getline(file, tempStr);
            tempBool[0] = stoi(tempStr);
            std::getline(file, tempStr);
            tempBool[1] = stoi(tempStr);

            tree.setStatsManually(nameStr, tempInt[0], tempInt[1], tempInt[2], tempInt[3], tempInt[4], tempInt[5], tempBool[0], tempBool[1]);
            treeStack.push(tree);
        }

        
    }

    // Letting user know that the file loaded correctly
    std::cout << "\nFile loaded successfully\n";

    // Closing the file
    file.close();
}

// Printing a list of all trees input by user
void viewTrees(std::stack<Tree> treeStack)
{
    // Declaring variables
    int i = 1;
    char waste;

    // Treestack is output until its empty
    while (!treeStack.empty())
    {
        
        // Printing tree
        std::cout << "\n"
                  << i << "). ";
        printTreeInfo(treeStack.top());
        i++;
        treeStack.pop();
    }

    // Waiting for user input to go back to the main menu
    std::cout << "\nEnter [Q] to continue back to the main menu.\n";
    std::cin >> waste;
}

// Creating Player
Player createPlayer()
{
    std::string playerName;
    std::cout << "\nWhat is your name?\n";
    std::cin >> playerName;
    Player player(playerName, 3, 1000);

    return player;
}

// Loading the correct seed
void loadSeed(int seedLoadIndicator, Player &player)
{
    Seed seed;
    HealthSeed hSeed;
    AttackSeed aSeed;
    DefenseSeed dSeed;
    hSeed.cringe();
    std::cout << seedLoadIndicator;
    switch(seedLoadIndicator){
        case 1: player.setSeed(hSeed); return;
        case 2: player.setSeed(aSeed); return;
        case 3: player.setSeed(dSeed); return;
        default: player.setSeed(seed); std::cout << "BROBRONONO"; return;
    }
}