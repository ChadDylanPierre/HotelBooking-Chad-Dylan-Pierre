#include "DeluxRoom.h"
#include <iostream>

DeluxRoom::DeluxRoom(int number, const std::string& viewType) : Room(number), view(viewType) {}

std::string DeluxRoom::getRoomInfo() const {
    return "Delux Room with " + view + " view";
}

void DeluxRoom::print() const {
    
    Room:: print();
    
    std::cout << "Delux Room with " << view << " view" << std::endl;
}

std::string DeluxRoom::getView() const {
    return view;
}
