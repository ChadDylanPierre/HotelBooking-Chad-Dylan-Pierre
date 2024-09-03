#include "Guest.h"

Guest::Guest(const string& name, const Date& checkin, const Date& checkout, int star, const std::string& hotel, const std::string& room, bool extra, const std::string& v, const std::string& size)
    : guestName(name), checkinDate(checkin), checkoutDate(checkout), starRate(star), hotelName(hotel), roomType(room), extraBed(extra), view(v), suiteSize(size) {}

std::string Guest::getHotelName() const {
    return hotelName;
}

std::string Guest::getRoomType() const {
    return roomType;
}

Date Guest::getCheckinDate() const {
    return checkinDate;
}

Date Guest::getCheckoutDate() const {
    return checkoutDate;
}

std::string Guest::getName() const {
    return guestName;
}

bool Guest::hasExtraBed() const {
    return extraBed;
}

std::string Guest::getSuiteSize() const {
    return suiteSize;
}

void Guest::print() const {
    std::cout << "Guest: " << guestName << ", Check-in: ";
    checkinDate.print();
    std::cout << ", Check-out: ";
    checkoutDate.print();
    std::cout << ", Star Rate: " << starRate << ", Hotel Name: " << hotelName << ", Room Type: " << roomType;
    if (roomType == "stdRoom") {
        std::cout << ", Extra Bed: " << (extraBed ? "Yes" : "No");
    }
    else if (roomType == "deluxRoom") {
        std::cout << ", View: " << view;
    }
    else if (roomType == "suite") {
        std::cout << ", Suite Size: " << suiteSize;
    }
    std::cout << std::endl;
}

ostream& operator<<(ostream&output, const Guest& guest) {

    output<< "Guest: " << guest.guestName<< ", Check-in: ";
    guest.checkinDate.print();
    std::cout << ", Check-out: ";
    guest.checkoutDate.print();
    std::cout << ", Star Rate: " << guest.starRate << ", Hotel Name: " << guest.hotelName << ", Room Type: " << guest.roomType;
    if (guest.roomType == "stdRoom") {
        std::cout << ", Extra Bed: " << (guest.extraBed ? "Yes" : "No");
    }
    else if (guest.roomType == "deluxRoom") {
        std::cout << ", View: " << guest.view;
    }
    else if (guest.roomType == "suite") {
        std::cout << ", Suite Size: " << guest.suiteSize;
    }
    std::cout << std::endl;

    return output;
}

int Guest::getStarRate()const {

    return starRate;
}

string Guest::getView()const {


    return view;
}