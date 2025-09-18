#pragma once

#include <map>
#include <string>
#include "model/Room.h"


class RoomManager {
public:
    RoomManager();
    void loadRooms();
    const Room& getRoom(const std::string& id) const;
    bool hasExit(const std::string& roomId, const std::string& direction) const;
    std::string getExit(const std::string& roomId, const std::string& direction) const;
    std::map<std::string, std::string> getExits(const std::string& roomId) const;


    const std::map<std::string, Room>& getAllRooms() const;

private:
    std::map<std::string, Room> rooms;
};
