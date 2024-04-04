#include "TreeH.hpp"

// Prototyping
void printTreeInfo(Tree tree);
Tree getUserTree();
void saveTrees(std::stack<Tree> treeStack);
void viewTrees(std::stack<Tree> treeStack);
void mainMenu(Player player);
Player createPlayer();


int main(){

    // Displaying the main menu for the user
    mainMenu(createPlayer());
    
    return(0);
}

// Main Menu
void mainMenu(Player player){

    // Declaring variables
    bool toContinue = true;
    int userIn;
    std::stack<Tree> treeStack;

    // Do While loop that displays the menu
    do{
        std::cout << "\n*********TREE MENU**********"
             << "\nWhat would you like to do?"
             << "\n1). FIGHT!"
             << "\n2). Create a new tree. (100 M)"
             << "\n3). View Trees."
             << "\n4). Save Trees to File"
             << "\n5). Buy Wood Bandages. (50 M)"
             << "\n6). View Inventory."
             << "\n7). Quit. (All progress will be lost.)"
             << "\n*********TREE MENU**********\n";

        // Getting user input for menu selection
        std::cin >> userIn;

        // Switch statement that sends the user where they want to go
        switch (userIn)
        {
        case 1: 
            fightPhase(treeStack, player);
                break;
        case 2:
            if(player.getMoney() > 99){
                player.setMoney(-100);
                treeStack.push(getUserTree());
            }else{
                std::cout << "\nYou don't have enough cash money bro.\n";
            }
            break;
        case 3:
            viewTrees(treeStack);
            break;
        case 4:
            saveTrees(treeStack);
            break;
        case 5:
            if(player.getMoney() > 49){
                player.setMoney(-50);
                player.setWoodBandages(1);
                std::cout << "\nYou bought a wood bandage, you now have " << player.getWoodBandages() << ".\n";
            }else{
                std::cout << "\nYou don't have enough cash money bro.\n";
            }
            break;
        case 6:
            std::cout << "\nWood Bandages: " << player.getWoodBandages() << "\nMoney: " << player.getMoney();
            break;
        case 7:
            toContinue = false;
            break;
        default: std::cout << "\nBro that is NOT an option.\n"; break;
        }
    }while(toContinue);

}

// Printing tree info
void printTreeInfo(Tree tree){
    std::cout << "\nTree Type: " << tree.getType() << "\nTree Length: " << tree.getLength() << "\n";
}

// Asking user for the tree info
Tree getUserTree(){
    
    // Declaring Variables
    int length;
    std::string type;

    // Asking user info about the tree
    std::cout << "\nWhat type of tree is it?\n";
    std::cin >> type;

    // Making sure the user sets an appropriate height for the tree
    do{

        std::cout << "\nHow tall is the tree (ft)?\n(Choose a value between 1 and 100 inclusive.)\n";
        std::cin >> length;


    }while((length > 101) || (length < 0));

    // Creating tree object
    Tree tree(type, length);

    // Returning tree object
    return tree;
}

// Saving all created trees to a file
void saveTrees(std::stack<Tree> treeStack){

    // Declaring variables
    Tree tree;
    std::ofstream file;
    file.open("Trees.tc");

    // Treestack is saved until its empty
    while(!treeStack.empty()){

        // Getting top value, then popping it off the stack
        tree = treeStack.top();
        treeStack.pop();

        // Saving data of popped tree to the file
        file << tree.getType() << "\n";
        file << tree.getLength() << "\n";
    }

    // Closing the file
    file.close();

    // Telling user the file was output to successfully 
    std::cout << "\nFile Tree.tf was created!\n";

}

// Printing a list of all trees input by user
void viewTrees(std::stack<Tree> treeStack){

    // Declaring variables
    int i = 1;
    Tree tree;
    char waste;

    // Treestack is output until its empty
    while(!treeStack.empty()){

        // Getting top value, then popping it off the stack
        tree = treeStack.top();
        treeStack.pop();

        // Printing tree
        std::cout << "\n" << i << ").";
        printTreeInfo(tree);
        i++;
}

    // Waiting for user input to go back to the main menu
    std::cout << "\nEnter [Q] to continue back to the main menu.\n";
    std::cin >> waste;
}

// Creating Player
Player createPlayer(){
    std::string playerName;
    std::cout << "\nWhat is your name?\n";
    std::cin >> playerName;
    Player player(playerName, 3, 100);

    return player;
    
}