//
// Created by Tyrese Strafford on 05/04/2024.
//

#ifndef MONKGAME_MONSTERROOM_H
#define MONKGAME_MONSTERROOM_H

#include "Room.h"
#include "Monster.h"
#include "Player.h"

class MonsterRoom : public Room {
private:
    Monster monster;

public:
    MonsterRoom(const std::string& roomDescription, const Monster& roomMonster);
    void enter(Player& player);
    void startFight(Player& player);
};



#endif //MONKGAME_MONSTERROOM_H
