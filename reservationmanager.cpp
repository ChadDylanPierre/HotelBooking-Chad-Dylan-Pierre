#include "ReservationManager.h"
#include "ThreeStarHotel.h"
#include "FourStarHotel.h"
#include "FiveStarHotel.h"
#include "StdRoom.h"
#include "DeluxRoom.h"
#include "Suite.h"
#include <iostream>
#include "Date.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;



ReservationManager::ReservationManager() : noReservation(0) {
    for (int i = 0; i < 200; ++i) {
        hotelArray[i] = nullptr;
    }
    for (int i = 0; i < 1000; ++i) {
        reservationArray[i] = nullptr;
    }
}

bool ReservationManager::insertHotel(Hotel* hotel) {
    for (int i = 0; i < 200; i++) {
        if (hotelArray[i] == nullptr) {
            hotelArray[i] = hotel;
            return true;
        }
    }
    return false;
}

int ReservationManager::makeReservation(const Guest& guest) {
    // Iterate over all hotels to find the matching hotel
    for (int i = 0; i < 200; ++i) {
        if (hotelArray[i] != nullptr && hotelArray[i]->getHotelName() == guest.getHotelName()) {
            // Iterate over the rooms in the hotel to find a matching and available room
            for (int j = 0; j < hotelArray[i]->getRoomCapacity(); ++j) {
                Room* room = hotelArray[i]->getRoom(j);

                if (guest.getRoomType() == "stdRoom" && dynamic_cast<StdRoom*>(room)) {
                    if (room->isAvailable(guest.getCheckinDate().toDayNumber(), guest.getCheckoutDate().toDayNumber())) {
                        // Make the reservation
                        room->book(guest.getCheckinDate().toDayNumber(), guest.getCheckoutDate().toDayNumber());
                        double rate = hotelArray[i]->getRoomRate(room->getRoomNo());
                        Reservation* reservation = new Reservation(guest, room->getRoomNo(), rate);
                        insert(reservation);
                        return reservation->getReservationNo();
                    }
                }
                else if (guest.getRoomType() == "deluxRoom" && dynamic_cast<DeluxRoom*>(room)) {
                    if (room->isAvailable(guest.getCheckinDate().toDayNumber(), guest.getCheckoutDate().toDayNumber())) {
                        // Make the reservation
                        room->book(guest.getCheckinDate().toDayNumber(), guest.getCheckoutDate().toDayNumber());
                        double rate = hotelArray[i]->getRoomRate(room->getRoomNo());
                        Reservation* reservation = new Reservation(guest, room->getRoomNo(), rate);
                        insert(reservation);
                        return reservation->getReservationNo();
                    }
                }
                else if (guest.getRoomType() == "suite" && dynamic_cast<Suite*>(room)) {
                    if (room->isAvailable(guest.getCheckinDate().toDayNumber(), guest.getCheckoutDate().toDayNumber())) {
                        // Make the reservation
                        room->book(guest.getCheckinDate().toDayNumber(), guest.getCheckoutDate().toDayNumber());
                        double rate = hotelArray[i]->getRoomRate(room->getRoomNo());
                        Reservation* reservation = new Reservation(guest, room->getRoomNo(), rate);
                        insert(reservation);
                        return reservation->getReservationNo();
                    }
                }
            }
        }
    }
    // No matching or available room found
    return 0;
}

bool ReservationManager::insert(Reservation* reservation) {
    if (noReservation < 1000) {
        reservationArray[noReservation++] = reservation;
        return true;
    }
    return false;
}

void ReservationManager::search(int reservationNo) {
    for (int i = 0; i < noReservation; ++i) {
        if (reservationArray[i]->getReservationNo() == reservationNo) {
            cout << reservationArray[i];
            return;
        }
    }
    std::cout << "Reservation not found." << std::endl;
}

bool ReservationManager::cancelReservation(int reservationNo) {
    for (int i = 0; i < noReservation; ++i) {
        if (reservationArray[i]->getReservationNo() == reservationNo) {
            delete reservationArray[i];
            reservationArray[i] = reservationArray[noReservation - 1];
            reservationArray[noReservation - 1] = nullptr;
            noReservation--;
            return true;
        }
    }
    return false;
}

void ReservationManager::print() {
    for (int i = 0; i < 200; i++)
        if (hotelArray[i] != nullptr)
            hotelArray[i]->print();
}


bool ReservationManager::openFile(ofstream& file, string Archive) {

    file.open(Archive, ios::app);
    if (!file)
        throw FileNotOpen();



}
void ReservationManager::save(const string& Archive, Date date) {

    ofstream outFile;

    int deadlineDate = date.toDayNumber();

    for (int i = 0; i < noReservation; i++) {

        if (date > reservationArray[i]->getGuest().getCheckoutDate()) {


            try {
                openFile(outFile, Archive);

            }

            catch (FileNotOpen& file) {

                cout << "Exception occured : " << file.what() << endl;
                exit(1);
            }






           


            outFile << reservationArray[i]->getReservationNo() << "  "
                << reservationArray[i]->getGuest().getName() << "  "
                << reservationArray[i]->getRoomNo() << "  "
                << reservationArray[i]->getBaseRate() << "  "
                << reservationArray[i]->getExtraBedFee() << "  "
                << reservationArray[i]->getPerdayCost() << "  "
                << reservationArray[i]->getTotalCost() << "  "
                << (reservationArray[i]->getGuest().hasExtraBed() ? 1 : 0) << "  "
                << reservationArray[i]->getGuest().getCheckinDate() << "  "
                << reservationArray[i]->getGuest().getCheckoutDate() << "  "
                << reservationArray[i]->getGuest().getStarRate() << "  "
                << reservationArray[i]->getGuest().getHotelName() << "  "
                << reservationArray[i]->getGuest().getRoomType() << "  "
                << reservationArray[i]->getGuest().getView() << "  "
                << reservationArray[i]->getGuest().getSuiteSize() << endl; 
            outFile.close();
        }


    }
}

bool ReservationManager::searchReservation(const string& Archive, int reservationNo) {
    
    ifstream outFile(Archive);

    if (!outFile) {
        cerr << "File could not be opened" << endl;
        return false;
    }
    int resNo, roomNo, starRate;
    double baseRate, extraBedFee, perdayCost, totalCost;
    string guestName, hotelName, roomType, view, suiteSize;
    bool extraBed;
    int checkinMonth, checkinDay, checkinYear;
    int checkoutMonth, checkoutDay, checkoutYear;


    while (outFile >> resNo >> guestName >> roomNo >> baseRate >> extraBedFee >> perdayCost >> totalCost >> extraBed
        >> checkinMonth >> checkinDay >> checkinYear
        >> checkoutMonth >> checkoutDay >> checkoutYear
        >> starRate >> hotelName >> roomType >> view >> suiteSize) {




        if (resNo == reservationNo) {
            cout << "Reservation found in textfile" << endl;

            Date checkinDate(checkinMonth, checkinDay, checkinYear);
            Date checkoutDate(checkoutMonth, checkoutDay, checkoutYear);

            Guest guest(guestName, checkinDate, checkoutDate, starRate, hotelName, roomType, extraBed, view, suiteSize);
            Reservation* res = new Reservation(guest, roomNo, baseRate);
            res->setReservationNo(reservationNo);

            cout << *res << endl;
            delete res;
            outFile.close();
            return true;
        }




        
    }
    return false;
}