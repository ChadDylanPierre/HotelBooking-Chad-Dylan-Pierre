#include "ReservationManager.h"
#include "ThreeStarHotel.h"
#include "FourStarHotel.h"
#include "FiveStarHotel.h"
#include "Guest.h"
#include "Date.h"
#include <iostream>


int main() {
    ReservationManager manager;

    // Create hotel objects and add them to the manager
    ThreeStarHotel* threeStar = new ThreeStarHotel("Three Star Hotel", 100.0, 20.0, 10);
    FourStarHotel* fourStar = new FourStarHotel("Four Star Hotel", 120.00, 150.0, 16.0, 15);
    FiveStarHotel* fiveStar = new FiveStarHotel("Five Star Hotel", 140.0, 150.0,250.0, 25.0,  20);

    manager.insertHotel(threeStar);
    manager.insertHotel(fourStar);
    manager.insertHotel(fiveStar);
    
    manager.print();
    
    // Create guest objects and make reservations
    Date checkin(7, 26, 2024);
    Date checkout(8, 3, 2024);
    Guest guest1("John", checkin, checkout, 5, "Five Star Hotel", "suite", false, "", "large");
    Guest guest2("Jane", checkin, checkout, 3, "Three Star Hotel", "stdRoom", true, "", "");

    int reservationNo1 = manager.makeReservation(guest1);
    
    std::cout<<"Reservation for "<< guest1.getName()<<", "<<std::endl;
    if (reservationNo1 != 0) {
        std::cout << "Reservation successful, number: " << reservationNo1 << std::endl;
    } else {
        std::cout << "Reservation failed." << std::endl;
    }

    int reservationNo2 = manager.makeReservation(guest2);
    std::cout<<"Reservation for "<< guest2.getName()<< ","<<std::endl;
    if (reservationNo2 != 0) {
        std::cout << "Reservation successful, number: " << reservationNo2 << std::endl;
    } else {
        std::cout << "Reservation failed." << std::endl;
    }

    // Demonstrate other functionalities
    std::cout<< " Searching for reservation and printing it, "<<std::endl;
    manager.search(reservationNo2);

    


    std::cout<< " Canceling a reservation, " <<std::endl;
    manager.cancelReservation(reservationNo2);
    
    std::cout<< " Searching for the cancelled reservation, "<<std::endl;
    manager.search(reservationNo2);



    cout << endl<<endl<<endl<< "Now we will save expired reservation in textfile Archive" << endl;

    ofstream outfile("Archive.txt");
    outfile.close();

    Date d(9, 23, 2024);
    manager.save("Archive.txt", d);
    cout << "Searching for reservation 1 in the textfile" << endl;

    manager.searchReservation("Archive.txt", 1);

 

    return 0;
}
