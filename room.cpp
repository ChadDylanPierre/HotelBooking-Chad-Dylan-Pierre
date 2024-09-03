#include "Room.h"
#include <iostream>

using  namespace std;

Room::Room(int number) : roomNo(number) {
    for (int i = 0; i < 360; ++i) {
        availabilityArray[i] = true; // Initialize all days as available
    }
}

Room::~Room() {}

bool Room::isAvailable(int start, int end) const {
    for (int i = start; i < end; ++i) {
        if (!availabilityArray[i]) {
            return false;
        }
    }
    return true;
}

void Room::book(int checkin, int checkout) {
    for (int i = checkin; i < checkout; ++i) {
        availabilityArray[i] = false;
    }
}

int Room::getRoomNo() const {
    return roomNo;
}

void Room::print() const {
    cout<< "Room no is "<< roomNo << ", ";
}
