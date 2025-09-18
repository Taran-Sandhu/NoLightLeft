#include "core/Game.h"
#include "util/StringUtil.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <limits>

Game::Game()
    : player(), roomManager(), currentRoom("crypt") {
    player.setLightLevel(10);
}

void Game::displayIntro() {
    std::ifstream in("assets/intro.txt");
    std::string line;
    while (std::getline(in, line)) {
        std::cout << line << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
}

void Game::drawMap() const {

    int minX = std::numeric_limits<int>::max();
    int maxX = std::numeric_limits<int>::min();
    int minY = std::numeric_limits<int>::max();
    int maxY = std::numeric_limits<int>::min();
    for (auto const& [id, room] : roomManager.getAllRooms()) {
        minX = std::min(minX, room.getX());
        maxX = std::max(maxX, room.getX());
        minY = std::min(minY, room.getY());
        maxY = std::max(maxY, room.getY());
    }


    for (int y = maxY; y >= minY; --y) {
        for (int x = minX; x <= maxX; ++x) {
            std::string symbol = "  ";
            for (auto const& [id, room] : roomManager.getAllRooms()) {
                if (room.getX() == x && room.getY() == y) {
                    if (id == currentRoom)               symbol = " P";
                    else if (visited.count(id))          symbol = " .";
                    else                                  symbol = " ?";
                    break;
                }
            }
            std::cout << symbol;
        }
        std::cout << '\n';
    }
}

void Game::start() {
    displayIntro();
    std::cout << "\nType 'quit' to exit.\n";
    gameLoop();
}

void Game::gameLoop() {
    while (true) {
        visited.insert(currentRoom);
        const Room& room = roomManager.getRoom(currentRoom);

        std::cout << "\n" << room.getDescription() << "\n";
        drawMap();
        std::cout << "Light: " << player.getLightLevel() << "\n> ";

        std::string input;
        std::getline(std::cin, input);
        input = util::trim(input);
        input = util::toLower(input);

        if (input == "quit" || input == "exit") {
            std::cout << "Goodbye.\n";
            break;
        }

        auto parts = util::split(input, ' ');
        std::string cmd = parts.size()>0 ? parts[0] : "";
        std::string arg = parts.size()>1 ? parts[1] : "";
        std::string dir = (cmd=="go"?arg:cmd);

        bool moved = false;
        if (!dir.empty() && roomManager.hasExit(currentRoom, dir)) {
            currentRoom = roomManager.getExit(currentRoom, dir);
            player.decrementLight();
            moved = true;
        }
        if (!moved) std::cout << "You can't do that.\n";

        if (player.getLightLevel() <= 0) {
            std::cout << "\nYour torch has burned out. You are lost in the darkness...\n";
            break;
        }
    }
}
