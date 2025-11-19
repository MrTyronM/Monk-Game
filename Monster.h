//
// Created by Tyrese Strafford on 05/04/2024.
//

#ifndef MONKGAME_MONSTER_H
#define MONKGAME_MONSTER_H

#include <string>
using namespace std;

class Monster {
private:
    string name;
    int currentHealth;
    int attackPoints;
    int const minHealth{0};

public:
    // Constructor
    Monster(const string& monsterName, int health, int attack);

    // Getters
    const string& getName() const;
    int getCurrentHealth() const;
    int getAttackPoints() const;

    // Actions
    void takeDamage(int damage);
    bool isAlive() const;
    int attack();
};



#endif //MONKGAME_MONSTER_H
