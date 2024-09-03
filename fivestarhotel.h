#ifndef FIVESTARHOTEL_H
#define FIVESTARHOTEL_H

#include "FourStarHotel.h"
#include "Suite.h"

class FiveStarHotel : public FourStarHotel {
protected: 
    double suiteRate;
public:
    FiveStarHotel(const std::string& name, double stdrate,double deluxrate, double srate, double brate, int capacity);
    virtual void print() const override;
    virtual double getRoomRate(int roomNo) const override; // Implemented method
};

#endif
