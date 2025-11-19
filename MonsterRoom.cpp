//
// Created by Tyrese Strafford on 05/04/2024.
//

#include "MonsterRoom.h"
#include <iostream>


MonsterRoom::MonsterRoom(const std::string& roomDescription, const Monster& roomMonster)
        : Room(roomDescription), monster(roomMonster) {}

void MonsterRoom::enter(Player& player) {
    std::cout << "You have entered the room: " << getDescription() << endl;
    std::cout << "You encounter a " << monster.getName() << "!"<< endl;
    std::cout << "Prepare to fight: " << endl;
    startFight(player);

}

void MonsterRoom::startFight(Player &player) {
    std::cout << "Let the battle begin!" << std::endl;

    while (player.isAlive() && monster.isAlive()) {
        std::cout << player.getPlayerName() <<  " current HP: " << player.getCurrentHealth() << std::endl;

        std::cout << monster.getName() << " current HP: " << monster.getCurrentHealth() << std::endl;
        std::cout << "Its your go!" << endl;
        int choice {0};
        while (true) {
            std::cout << "Please enter either (1) to attack or (2) to Defend: " << endl;
            if (std::cin >> choice) {
                if (choice == 1 || choice == 2) {
                    break;
                } else {
                    std::cout << "Invalid input! ";
                }
            } else { //This will stop anything other numeric data to be inputted
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Characters are not excepted. ";
            }
        }

        if (player.getCurrentHealth() == player.getMaxHealth() && choice == 2) {
            cout << "You are already at max health so you can't defend. You musk attack the " << monster.getName() << " instead" << endl;
            int damage = player.attack();
            if (rand() % 2 == 0){
                monster.takeDamage(damage);
                std::cout << "You attacked the " << monster.getName() << " for " << damage << " damage! " << std::endl;
            } else {
                std::cout << "Your attack missed!" << std::endl;
            }
        } else if (choice == 1) {
            int damage = player.attack();
            if (rand() % 2 == 0){
                monster.takeDamage(damage);
                std::cout << "You attacked the " << monster.getName() << " for " << damage << " damage! " << std::endl;
            } else {
                std::cout << "Your attack missed!" << std::endl;
            }
        } else if (choice == 2 && player.getCurrentHealth() <= player.getMaxHealth()) {
            if (rand() % 2 == 0) {
                player.defend();
                std::cout << "You defended and recovered 1 health! " << std::endl;
            } else {
                std:cout << "Your defence failed!" << endl;
            }
        }

        int damage = monster.attack();
        if(rand() % 2 == 0) {
            player.takeDamage(damage);
            std::cout << "The " << monster.getName() << " attacked you for "<< damage << std::endl;
        } else {
            std::cout << "The " << monster.getName() <<"'s attack missed!" << std::endl;
        }

        std::cout << "\n";

        if (!monster.isAlive()) {
            std::cout << "You have defeated the " << monster.getName() << "!" << std::endl;
            cout << "Press enter to move to the next room: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (cin.get() == '\n') {
                cout << "Moving to the next room..." << endl;
                break;
            }
            return;
        }

        if (!player.isAlive()) {
            std::cout << "HAHA. The " << monster.getName() << " defeated " << player.getPlayerName() <<
                      ". Now you lie there forever!" <<endl;
        }


    }
}
