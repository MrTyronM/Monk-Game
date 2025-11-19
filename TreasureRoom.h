//
// Created by Tyrese Strafford on 08/04/2024.
//

#ifndef MONKGAME_TREASUREROOM_H
#define MONKGAME_TREASUREROOM_H

#include "Room.h"
#include "Player.h"

class TreasureRoom : public Room{
private:
    void giveReward(Player& player);

public:
    TreasureRoom(const std::string& description);
    void enter(Player& player);

};


#endif //MONKGAME_TREASUREROOM_H
