#include "TreeH.hpp"

// Prototyping
void store(std::stack<Tree> &treeStack, Player &player);

// Main store function
void store(std::stack<Tree> &treeStack, Player &player){

    // Declaring variables
    int userIn;

     // Do While loop that displays the store
    do
    {
        std::cout << "\n*********STORE**********"
                  << "\nWhat would you like to do?\n"
                  << "\n1). Wood Bandages (50 M)"
                  << "\n2). Create a new tree. (100 M)"
                  << "\n3). View Trees."
                  << "\n4). Buy Wood Bandages. (50 M)"
                  << "\n5). View Inventory."
                  << "\n6). Save game to file."
                  << "\n7). Load game from file."
                  << "\n8). Quit. (Unsaved progress will be lost.)"
                  << "\n*********STORE**********\n";

        std::cin >> userIn;

        switch(userIn){

            case 1: 
                if (player.getMoney() > 49)
                {
                    player.setMoney(player.getMoney() - 50);
                    player.setWoodBandages(player.getWoodBandages() -1);
                    std::cout << "\nYou bought a wood bandage, you now have " << player.getWoodBandages() << ".\n";
                }
                else
                {
                    std::cout << "\nYou don't have enough cash money bro.\n";
                }
                break;
        }



    }while(true);
    
}