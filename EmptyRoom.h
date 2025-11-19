//
// Created by Tyrese Strafford on 08/04/2024.
//

#ifndef MONKGAME_EMPTYROOM_H
#define MONKGAME_EMPTYROOM_H

#include "Room.h"
#include "Player.h"
#include <iostream>

class EmptyRoom : public Room {
private:
    Player& player;

public:
    EmptyRoom(const std::string& description, Player& player);

    // Overriding the virtual function from the base class
    void enter(Player& player);
    void pray(Player& player);
};



#endif //MONKGAME_EMPTYROOM_H
