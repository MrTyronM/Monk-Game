//
// Created by Tyrese Strafford on 05/04/2024.
//

#ifndef MONKGAME_ROOM_H
#define MONKGAME_ROOM_H

#include <vector>
#include <string>
using namespace std;

class Player;


class Room {
private:
    string description;
    bool visited;
public:

    Room(const string& roomDecription);

//    virtual ~Room(); // Virtual destructor to ensure proper cleanup
    virtual void enter(Player& player) = 0; // Pure virtual function for entering the room


    //Getters/ Setters
    const string& getDescription() const;
    bool isVisited() const;
    void setVisited(bool value);
};


#endif //MONKGAME_ROOM_H
