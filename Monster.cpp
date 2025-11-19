//
// Created by Tyrese Strafford on 05/04/2024.
//

#include "Monster.h"
#include <iostream>

Monster::Monster(const std::string& monsterName, int health, int attack)
        : name(monsterName), currentHealth(health), attackPoints(attack) {}

const std::string& Monster::getName() const {
    return name;
}


int Monster::getCurrentHealth() const {
    return currentHealth;
}

int Monster::getAttackPoints() const {
    return attackPoints;
}

void Monster::takeDamage(int damage) {
    currentHealth -= damage;
}

bool Monster::isAlive() const {
    return currentHealth > minHealth;
}

int Monster::attack() {
    // Implement attack logic here
    // For simplicity, let's return the attack points directly
    //Need add condition soon to check which Monster it is as attack point may be different
    attackPoints = 2;

    return attackPoints;
}
