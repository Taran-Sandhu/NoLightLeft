
#pragma once

#include <string>
#include <map>


class Room {
public:
    Room() = default;
    Room(std::string id, std::string description, int x, int y);

    const std::string& getId() const;
    const std::string& getDescription() const;
    int getX() const;
    int getY() const;

    void setExit(const std::string& direction, const std::string& targetId);
    bool hasExit(const std::string& direction) const;
    const std::string& getExit(const std::string& direction) const;
    std::map<std::string, std::string> getExits() const;

private:
    std::string id;
    std::string description;
    int x{};
    int y{};
    std::map<std::string, std::string> exits;
};