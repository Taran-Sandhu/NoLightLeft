
#pragma once
#include <vector>
#include <tuple>
#include <string>
#include "model/Room.h"

class MapGenerator {
public:
    MapGenerator(int width, int height, int roomCount);
    std::vector<Room> generateRooms();
    std::vector<std::tuple<std::string, std::string, std::string>> generateExits();
};
