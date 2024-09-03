#include "Reservation.h"
#include <iostream>

int Reservation::counter = 1;

Reservation::Reservation(const Guest& g, int room, double rate)
    : guest(g), roomNo(room), baseRate(rate), extraBedFee(0), perdayCost(rate) {
    reservationNo = counter++;
    
    // Adjust perdayCost for extra bed if it's a standard room
    if (guest.getRoomType() == "stdRoom" && guest.hasExtraBed()) {
        extraBedFee = 0.1 * rate;
        perdayCost += extraBedFee; // 10% of the standard room rate is added for the extra bed
    }

    // Adjust perdayCost for suite size
    if (guest.getRoomType() == "suite") {
        if (guest.getSuiteSize() == "medium") {
            perdayCost *= 1.5; // 50% more for medium suite
        } else if (guest.getSuiteSize() == "large") {
            perdayCost *= 2.0; // 100% more for large suite
        }
    }

    int days = (guest.getCheckoutDate().toDayNumber() - guest.getCheckinDate().toDayNumber());
    totalCost = perdayCost * days;
}

int Reservation::getReservationNo() const {
    return reservationNo;
}

void Reservation::print() const {
    std::cout << "Reservation No: " << reservationNo << "\n"
              << "Guest: " << guest.getName() << "\n"
              << "Room No: " << roomNo << "\n"
              << "Check-in Date: " << guest.getCheckinDate().getMonth() << "/" << guest.getCheckinDate().getDay() << "/" << guest.getCheckinDate().getYear() << "\n"
              << "Check-out Date: " << guest.getCheckoutDate().getMonth() << "/" << guest.getCheckoutDate().getDay() << "/" << guest.getCheckoutDate().getYear() << "\n"
              << "Regular cost per day: " << baseRate << "\n"
              << "Extra bed fee: " << extraBedFee << "\n"
              << "Cost per day: " << perdayCost << "\n"
              << "Total cost: " << totalCost << "\n"
              << "Extra bed: " << (guest.hasExtraBed() ? "Yes" : "No") << std::endl;
}

ostream& operator<<(ostream&output, const Reservation&reservation) {

    output<< "Reservation No: " << reservation.reservationNo << "\n"
        << "Guest: " << reservation.guest.getName() << "\n"
        << "Room No: " << reservation.roomNo << "\n"
        << "Check-in Date: " << reservation.guest.getCheckinDate().getDay() << "/" << reservation.guest.getCheckinDate().getMonth() << "/" << reservation.guest.getCheckinDate().getYear() << "\n"
        << "Check-out Date: " << reservation.guest.getCheckoutDate().getMonth() << "/" << reservation.guest.getCheckoutDate().getDay() << "/" << reservation.guest.getCheckoutDate().getYear() << "\n"
        << "Regular cost per day: " << reservation.baseRate << "\n"
        << "Extra bed fee: " << reservation.extraBedFee << "\n"
        << "Cost per day: " << reservation.perdayCost << "\n"
        << "Total cost: " << reservation.totalCost << "\n"
        << "Extra bed: " << (reservation.guest.hasExtraBed() ? "Yes" : "No") << std::endl;

    return output;

 }

Guest Reservation::getGuest()const {

    return guest;
}

int Reservation::getRoomNo()const {
    return roomNo;

}
double Reservation::getBaseRate()const {
    return baseRate;

}
double Reservation::getExtraBedFee()const {
    return extraBedFee;

}
double Reservation::getPerdayCost()const {
    return perdayCost;

}
double Reservation::getTotalCost()const {
    return totalCost;

}

void Reservation::setReservationNo(int resNo) {

    this->reservationNo = resNo;
}