
#include "model/Player.h"
#include <algorithm>

Player::Player()
    : lightLevel(0)
{}

void Player::addItem(const std::string& item) {
    inventory.push_back(item);
}

bool Player::hasItem(const std::string& item) const {
    return std::find(inventory.begin(), inventory.end(), item) != inventory.end();
}

const std::vector<std::string>& Player::getInventory() const {
    return inventory;
}

void Player::setLightLevel(int level) {
    lightLevel = level;
}

int Player::getLightLevel() const {
    return lightLevel;
}

void Player::decrementLight() {
    if (lightLevel > 0) {
        --lightLevel;
    }
}
