//
// Created by Tyrese Strafford on 08/04/2024.
//

#include "EmptyRoom.h"


EmptyRoom::EmptyRoom(const std::string& description, Player& player)
        : Room(description), player(player) {}


void EmptyRoom::enter(Player& player) {
    std::cout << "You have entered an empty room. It should be safe here. You should pray and regain your health."
              << std::endl;

    char choice;
    if (player.getCurrentHealth() == player.getMaxHealth()) {
        std::cout << "You are already at max health so you can't pray" << std::endl;
    } else {
        while (true) {
            std::cout << "Would you like to pray? (y) for Yes or (n) for No." << std::endl;
            std::cin >> choice;
            if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
                std::cout << "Please enter a valid input. " << std::endl;
                std::cin.clear();
            } else {
                if (choice == 'Y' || choice == 'y') {
                    player.pray();
                    break;
                } else {
                    std::cout << "You don't want to pray. Your health will remain at " << player.getCurrentHealth()
                              << "." << std::endl;
                    break;
                }
            }

            cout << "Press enter to move to the next room: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (cin.get() == '\n') {
                cout << "Moving to the next room..." << endl;
                break;
            }

        }
    }
}


void EmptyRoom::pray(Player& player) {
    player.setCurrentHealth(player.getMaxHealth());
    std::cout << "You have prayer. Your health has been restored." << std::endl;
}

