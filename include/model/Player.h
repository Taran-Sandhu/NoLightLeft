
#pragma once

#include <vector>
#include <string>


class Player {
public:
    Player();


    void addItem(const std::string& item);


    bool hasItem(const std::string& item) const;


    const std::vector<std::string>& getInventory() const;


    void setLightLevel(int level);


    int getLightLevel() const;


    void decrementLight();

private:
    std::vector<std::string> inventory;
    int lightLevel{0};
};
