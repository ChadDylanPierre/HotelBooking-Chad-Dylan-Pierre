#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H
#include <fstream>
using namespace std;
#include<iostream>
#include <exception>
using std::exception;

#include "Hotel.h"
#include "Reservation.h"
#include "FileNotOpen.h"

class ReservationManager {
private:Hotel* hotelArray[200];
    Reservation* reservationArray[1000];
    int noReservation;
public:
    ReservationManager();
    bool insertHotel(Hotel* hotel);
    int makeReservation(const Guest& guest);
    bool insert(Reservation* reservation);
    void search(int reservationNo);
    bool cancelReservation(int reservationNo);
    void print(); // print hotel information
    void save(const string &, Date);
    bool searchReservation(const string &,int);
    bool openFile(ofstream&,string );
};

#endif
