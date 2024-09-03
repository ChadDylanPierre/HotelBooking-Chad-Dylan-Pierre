#include "ThreeStarHotel.h"
#include <iostream>

ThreeStarHotel::ThreeStarHotel(const std::string& name, double stdrate, double brate, int capacity)
    : Hotel(name, capacity), stdRoomRate(stdrate), breakfastrate(brate) {
        for(int j=0; j < capacity; j++)
        {roomArray[j] = new StdRoom (j+1);}
}

double ThreeStarHotel::getBreakfastRate() const {
    return breakfastrate;
}

void ThreeStarHotel::print() const {
    
    Hotel::print();
    
    std::cout<< "Standard room rate is " << stdRoomRate << ", "<< "breakfast rate is " << breakfastrate << std::endl;
    
    for (int i = 0; i < roomCapacity; ++i) {
        roomArray[i]->print();
    }
}

double ThreeStarHotel::getRoomRate(int roomNo) const {
    return stdRoomRate;
}
