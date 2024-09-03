#ifndef THREESTARHOTEL_H
#define THREESTARHOTEL_H

#include "Hotel.h"
#include "StdRoom.h"

class ThreeStarHotel : public Hotel {
protected:
    double stdRoomRate;
    double breakfastrate;
public:
    ThreeStarHotel(const std::string& name, double stdrate, double brate, int capacity);
    virtual double getBreakfastRate() const override;
    virtual void print() const override;
    virtual double getRoomRate(int roomNo) const override; 
};

#endif
