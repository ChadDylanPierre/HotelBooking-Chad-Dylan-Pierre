#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
protected:
    int roomNo;
    bool availabilityArray[360]; // Array representing availability for each day of the year
public:
    Room(int number);
    virtual ~Room();
    virtual std::string getRoomInfo() const = 0; // Pure virtual function
    virtual void print() const; //  virtual function
    bool isAvailable(int start, int end) const; // Declaration only
    void book(int checkin, int checkout); // Declaration only
    int getRoomNo() const; // Added method
};

#endif
