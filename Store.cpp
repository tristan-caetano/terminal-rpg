#include "TreeH.hpp"

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
                  << "\n2). Health Seed (75 M)"
                  << "\n3). Attack Seed (75 M)"
                  << "\n4). Defense Seed (75 M)"
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

            case 2:
                HealthSeed seed;
                if((player.getSeed().getName() != seed.getName()) && player.getMoney() > 74){
                    player.setSeed(seed);
                    player.setMoney(player.getMoney() - 75);
                } else if(player.getMoney() < 75) {
                    std::cout << "\nYou already have this seed.\n";
                }else{
                    std::cout << "\nYou do NOT have enough money for this.\n";
                }
                break;

                case 3:
                AttackSeed seed;
                if((player.getSeed().getName() != seed.getName()) && player.getMoney() > 74){
                    player.setSeed(seed);
                    player.setMoney(player.getMoney() - 75);
                } else if(player.getMoney() < 75) {
                    std::cout << "\nYou already have this seed.\n";
                }else{
                    std::cout << "\nYou do NOT have enough money for this.\n";
                }
                break;

                case 4:
                DefenseSeed seed;
                if((player.getSeed().getName() != seed.getName()) && player.getMoney() > 74){
                    player.setSeed(seed);
                    player.setMoney(player.getMoney() - 75);
                } else if(player.getMoney() < 75) {
                    std::cout << "\nYou already have this seed.\n";
                }else{
                    std::cout << "\nYou do NOT have enough money for this.\n";
                }
                break;

                default:
                std::cout << "\nBro that is NOT an option.\n";
                break;
        }



    }while(true);
    
}