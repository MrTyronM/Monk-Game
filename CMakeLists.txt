cmake_minimum_required(VERSION 3.27)
project(MonkGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(MonkGame main.cpp
        MonsterRoom.cpp
        Room.cpp
        Player.cpp
        Monster.cpp
        EmptyRoom.h
        EmptyRoom.cpp
        TreasureRoom.h
        TreasureRoom.cpp
)
