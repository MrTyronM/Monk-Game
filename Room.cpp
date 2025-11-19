//
// Created by Tyrese Strafford on 05/04/2024.
//

#include "Room.h"
#include "Player.h"

using namespace std;

Room::Room(const string& roomDescription)
        : description(roomDescription), visited(false) {}

const string& Room::getDescription() const {
    return description;
}



bool Room::isVisited() const {
    return visited;
}

void Room::setVisited(bool value) {
    visited = value;
}
