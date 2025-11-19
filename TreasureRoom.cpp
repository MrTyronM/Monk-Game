//
// Created by Tyrese Strafford on 08/04/2024.
//

#include "TreasureRoom.h"
#include <iostream>

TreasureRoom::TreasureRoom(const std::string &description) : Room(description){}

void TreasureRoom::enter(Player &player) {
    if (player.isAlive()) {
        std::cout << "You have reached the treasure room!" << std::endl;
        std::cout << "Congratulations! You have won the game! " << std::endl;
        giveReward(player);
    } else {
        std::cout << "You are dead so you can't claim the reward" << std::endl;
    }
}

void TreasureRoom::giveReward(Player &player) {
    player.setCurrentHealth(player.getCurrentHealth() + 10);
    std::cout << "You're health has been increased as a reward" << std::endl;
    std::cout << "Your new health is " << player.getCurrentHealth() <<std::endl;
}
