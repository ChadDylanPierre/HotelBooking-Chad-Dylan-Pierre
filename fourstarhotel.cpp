#include "FourStarHotel.h"
#include <iostream>
#include <cstdlib>

FourStarHotel::FourStarHotel(const std::string& name, double stdrate, double deluxrate, double brate, int capacity)
    : ThreeStarHotel(name, stdrate, brate, capacity), deluxRoomRate(deluxrate) {
        
        // Delete rooms created by the constructor of ThreeStarHotel and create rooms for FourStarHotel
        for (int i = 0; i < capacity; ++i) {
            delete roomArray[i];
            if (static_cast<double>(rand()) / RAND_MAX < 0.6) {
                roomArray[i] = new StdRoom(i);
            } else {
                roomArray[i] = new DeluxRoom(i, "mountain"); // Example, could be dynamic
            }
        }
}


void FourStarHotel::print() const {
    
    ThreeStarHotel::print();
    
    std::cout << "Delux room rate " << deluxRoomRate << std::endl;
    
}


double FourStarHotel::getRoomRate(int roomNo) const {
    Room* room = getRoom(roomNo);
    if (dynamic_cast<DeluxRoom*>(room)) {
        return deluxRoomRate;
    }
    return ThreeStarHotel::getRoomRate(roomNo);
}
