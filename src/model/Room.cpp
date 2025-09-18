#include "model/Room.h"
#include <stdexcept>

Room::Room(std::string id, std::string description, int x_, int y_)
    : id(std::move(id)), description(std::move(description)), x(x_), y(y_) {}

const std::string& Room::getId() const { return id; }
const std::string& Room::getDescription() const { return description; }
int Room::getX() const { return x; }
int Room::getY() const { return y; }

void Room::setExit(const std::string& direction, const std::string& targetId) {
    exits[direction] = targetId;
}

bool Room::hasExit(const std::string& direction) const {
    return exits.find(direction) != exits.end();
}

const std::string& Room::getExit(const std::string& direction) const {
    auto it = exits.find(direction);
    if (it == exits.end()) {
        throw std::out_of_range("No exit '" + direction + "' in room " + id);
    }
    return it->second;
}

std::map<std::string, std::string> Room::getExits() const {
    return exits;
}