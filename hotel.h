#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include "Room.h"

class Hotel {
protected:
    std::string hotelName;
    int roomCapacity;
    Room** roomArray; 
public:
    Hotel(std::string name, int capacity);
    virtual ~Hotel();
    virtual double getBreakfastRate() const = 0; // Pure virtual function
    virtual void print() const; // virtual function
    Room* getRoom(int index) const;
    int getRoomCapacity() const;
    std::string getHotelName() const;
    void setroomArray(int, Room *);
    virtual double getRoomRate(int roomNo) const = 0; // Added method
};

#endif
