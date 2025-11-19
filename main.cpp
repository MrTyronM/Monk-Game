#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include "Player.h"
#include "Room.h"
#include "Monster.h"
#include "MonsterRoom.h"
#include "EmptyRoom.h"
#include "TreasureRoom.h"

using namespace std;

int generateRandomNumber();
Room* createRandomRoom(Player& player, Monster& monster);

int main() {
    srand(time(nullptr)); // seed for the random number generator
    string name;
    string description;
    vector<Room*> rooms; // Create vector to store the different rooms
    unordered_set<Room*> visitedRooms; // This will keep track of the visited rooms

    cout << "Welcome to the dungeon." << endl;
    cout << "You must escape or suffer the consequences" << endl;
    cout << "Please enter your name: ";
    cin >> name;
    cout << endl;
    cout << "Please write a small description: ";
    cin >> description;
    cout << endl;

    // Create Player
    Player player(name, description);

    cout << "Hello " << player.getPlayerName() << endl;
    cout << "Are you ready to play. Please push any key to begin: " << endl;
    cin.ignore(); // This will ignore any previous inputs
    cin.get(); // Waiting for the users input

    Monster goblin("Goblin", 10, 2);

    // Loop to create and visit random rooms until the treasure room is found
    while (true) {
        Room* room = createRandomRoom(player, goblin);
        rooms.push_back(room); // Add room to vector

        // Handle the case where room is nullptr
        if (room == nullptr) {
            cout << "Error: Could not create room." << endl;
            break;
        }

        cout << "Entering room: " << room->getDescription() << endl;

        // Check if the room is the treasure room
        if (dynamic_cast<TreasureRoom*>(room) != nullptr) {
            dynamic_cast<TreasureRoom*>(room)->enter(player);
            break;
        } else if (dynamic_cast<MonsterRoom*>(room) != nullptr) {
            dynamic_cast<MonsterRoom*>(room)->enter(player);
        } else if (dynamic_cast<EmptyRoom*>(room) != nullptr) {
            dynamic_cast<EmptyRoom*>(room)->enter(player);
        }
        visitedRooms.insert(room); // Mark the room as visited
    }

    cout << "Visited Rooms:" << endl;
    for (const auto& room : visitedRooms) {
        cout << "- " << room->getDescription() << endl;
    }

    // Clean up dynamically allocated memory
    for (Room* room : rooms) {
        delete room;
    }

    return 0;
}

Room* createRandomRoom(Player& player, Monster& monster) {
    int random = generateRandomNumber();

    switch (random) {
        case 1: return new EmptyRoom("A empty room", player);
        case 2: return new MonsterRoom("The monster room", monster);
        case 3: return new TreasureRoom("The treasure room");
        default: return nullptr; // This should never be returned
    }
}

// Function to generate a random number between 1 and 3, allowing 3 only after 1 or 2 has been selected at least 3 times
int generateRandomNumber() {
    static int count1 = 0;
    static int count2 = 0;
    static bool allowThree = false;

    if (!allowThree) {
        int randomNumber = rand() % 2 + 1; // Generate a random number between 1 and 2
        if (randomNumber == 1) {
            count1++;
        } else {
            count2++;
        }

        // Check if both 1 and 2 have been generated at least three times
        if (count1 >= 3 && count2 >= 3) {
            allowThree = true;
        }
        return randomNumber;
    } else {
        return 3; // Allow 3 to be generated
    }
}

