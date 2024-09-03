#include "StdRoom.h"
#include <iostream>

StdRoom::StdRoom(int number) : Room(number), extraBed(false) {}

std::string StdRoom::getRoomInfo() const {
    return extraBed ? "Standard Room with extra bed" : "Standard Room";
}

void StdRoom::print() const {
    
    Room::print();
    
    std::cout << "Extra bed is " << extraBed << std::endl;
}

void StdRoom::setExtraBed(bool extra) {
    extraBed = extra;
}

bool StdRoom::hasExtraBed() const {
    return extraBed;
}
