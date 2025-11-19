//
// Created by Tyrese Strafford on 05/04/2024.
//

#ifndef MONKGAME_PLAYER_H
#define MONKGAME_PLAYER_H

#include <string>
#include <vector>
#include "Monster.h"

class Player {
private:
    string playerName;
    string description;
    int const maxHealth {15};
    int const minHealth {0} ;
    int currentHealth;
    int attackPoints;

public:

    Player(const std::string& playerName, const std::string& description);


    // Getters
    const string& getPlayerName() const;
    const string& getDescription() const;
    int getMaxHealth() const;
    int getMinHealth() const;
    int getCurrentHealth() const;
    int getAttackPoints() const;

    // Setters
    void setName(const string& newName);
    void setDescription(const string& newDescription);
    void setCurrentHealth(int currentHealth);
    void setAttackPoints(int attackPoints);

    void attack(Monster* monster);
    void defend();
    void pray();
    bool isAlive() const;
    void takeDamage(int damage);
    int attack();

};

#endif //MONKGAME_PLAYER_H
