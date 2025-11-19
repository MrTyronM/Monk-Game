//
// Created by Tyrese Strafford on 05/04/2024.
//
#include <iostream>
#include "Player.h"

Player::Player(const std::string &playerName, const std:: string& description)
        : playerName(playerName), description(description), maxHealth(15), minHealth(0), currentHealth(15), attackPoints(3) {}

const string& Player::getPlayerName() const {
    return playerName;
}

void Player::setName(const std::string &newName) {
    playerName = newName;
}

void Player::setDescription(const std::string &newDescription) {
    description = newDescription;
}

bool Player::isAlive() const {
    return currentHealth > minHealth;
}

void Player::takeDamage(int damage) {
    currentHealth -= damage;
    if (currentHealth <= minHealth) {
        //Add game over function Monster wins
    }
}

int Player::attack() {
    // Implement attack logic here
    // For simplicity, let's return the attack points directly
    //Need add condition soon to check which Monster it is as attack point may be different
    attackPoints = 3;

    return attackPoints;
}

void Player::defend() {
    currentHealth ++;
}

int Player::getCurrentHealth() const {
    return currentHealth;
}

int Player::getMaxHealth() const {
    return maxHealth;
}

void Player::setCurrentHealth(int newCurrentHealth) {
    currentHealth = newCurrentHealth;
}

void Player::pray() {
    std::cout << playerName << " is praying......." << std::endl;
    currentHealth = maxHealth;
    std::cout << "Your health has been fully restored." << std::endl;
}

