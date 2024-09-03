#ifndef FOURSTARHOTEL_H
#define FOURSTARHOTEL_H

#include "ThreeStarHotel.h"
#include "DeluxRoom.h"

class FourStarHotel : public ThreeStarHotel {
protected: 
    double deluxRoomRate;
public:
    FourStarHotel(const std::string& name, double stdrate, double deluxrate, double breakfastrate, int capacity);
    virtual void print() const override;
    virtual double getRoomRate(int roomNo) const override; // Implemented method
};

#endif
