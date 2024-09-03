#include "Suite.h"
#include <iostream>

Suite::Suite(int number, const std::string& size) : Room(number), suiteSize(size) {}

std::string Suite::getRoomInfo() const {
    return "Suite size: " + suiteSize;
}

void Suite::print() const {
    
    Room::print();
    
    std::cout << "Suite size: " << suiteSize << std::endl;
}

std::string Suite::getSize() const {
    return suiteSize;
}
