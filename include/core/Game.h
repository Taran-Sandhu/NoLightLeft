#pragma once

#include <string>
#include <set>
#include "manager/RoomManager.h"
#include "model/Player.h"


class Game {
public:
    Game();
    void start();

private:
    Player      player;
    RoomManager roomManager;
    std::string currentRoom;
    std::set<std::string> visited;

    void displayIntro();
    void drawMap() const;
    void gameLoop();
};
