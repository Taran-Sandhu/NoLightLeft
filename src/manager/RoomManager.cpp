#include "manager/RoomManager.h"
#include <stdexcept>

#include "manager/MapGenerator.h"

RoomManager::RoomManager() {
    loadRooms();
}

void RoomManager::loadRooms() {
    MapGenerator gen(10, 10, 20);
    auto roomList = gen.generateRooms();
    auto exitList = gen.generateExits();

    rooms.clear();
    for (auto& room : roomList) {
        rooms.emplace(room.getId(), std::move(room));
    }
    for (auto& [from, dir, to] : exitList) {
        rooms.at(from).setExit(dir, to);
    }

}

const Room& RoomManager::getRoom(const std::string& id) const {
    auto it = rooms.find(id);
    if (it == rooms.end()) throw std::out_of_range("No room with ID: " + id);
    return it->second;
}

bool RoomManager::hasExit(const std::string& roomId, const std::string& direction) const {
    return getRoom(roomId).hasExit(direction);
}

std::string RoomManager::getExit(const std::string& roomId, const std::string& direction) const {
    return getRoom(roomId).getExit(direction);
}

std::map<std::string, std::string> RoomManager::getExits(const std::string& roomId) const {
    return getRoom(roomId).getExits();
}

const std::map<std::string, Room>& RoomManager::getAllRooms() const {
    return rooms;
}
