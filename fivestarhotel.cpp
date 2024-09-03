#include "FiveStarHotel.h"
#include <iostream>
#include <cstdlib>

FiveStarHotel::FiveStarHotel(const std::string& name, double stdrate, double deluxrate, double srate, double brate, int capacity)
    : FourStarHotel(name, stdrate, deluxrate, brate, capacity), suiteRate(srate) {
        
// Delete rooms created by the constructor of FourStarHotel and create rooms for FiveStarHotel
        for (int i = 0; i < capacity; ++i) {
            
            delete roomArray[i];
            double u = static_cast<double>(rand()) / RAND_MAX;
            if (u < 0.5) {
                roomArray[i] = new StdRoom(i);
            } else if (u < 0.8) {
                roomArray[i] = new DeluxRoom(i, "lake"); // Example, could be dynamic
            } else {
                roomArray[i] = new Suite(i, "medium"); // Example, could be dynamic
            }
          }
    }


void FiveStarHotel::print() const {
    
    FourStarHotel::print();
    
    std::cout<< "Suite rate "<< suiteRate << std::endl;

}

double FiveStarHotel::getRoomRate(int roomNo) const {
    Room* room = getRoom(roomNo);
    if (dynamic_cast<Suite*>(room)) {
        return suiteRate;
    }
    return FourStarHotel::getRoomRate(roomNo);
}
