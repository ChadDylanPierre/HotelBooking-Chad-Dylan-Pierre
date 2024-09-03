#ifndef RESERVATION_H
#define RESERVATION_H

#include "Guest.h"

class Reservation {

    friend ostream& operator<<(ostream&, const Reservation&);

private:
    
    static int counter;
    int reservationNo;
    Guest guest;
    int roomNo;
    double baseRate;
    double extraBedFee;
    double perdayCost;
    double totalCost;
public:
    Reservation(const Guest& guest, int roomNo, double rate);
    void setReservationNo(int);
    int getReservationNo() const;
    int getRoomNo()const;
    double getBaseRate()const;
    double getExtraBedFee()const;
    double getPerdayCost()const;
    double getTotalCost()const;
    void print() const;
    Guest getGuest()const;
};

#endif
