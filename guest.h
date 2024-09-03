#ifndef GUEST_H
#define GUEST_H

#include "Date.h"
#include <cstring>
using namespace std;
using std::ostream;
using std::istream;

class Guest {


    friend ostream& operator<<(ostream&, const Guest&);


private: 
    
    string guestName;
    Date checkinDate;
    Date checkoutDate;
    int starRate;
    std::string hotelName;
    std::string roomType;
    bool extraBed;
    std::string view;
    std::string suiteSize;
public:
    Guest(const std::string& name, const Date& checkin, const Date& checkout, int star, const std::string& hotel, const std::string& room, bool extra, const std::string& v, const std::string& size);
    std::string getHotelName() const;
    std::string getRoomType() const;
    Date getCheckinDate() const;
    Date getCheckoutDate() const;
    std::string getName() const;
    int getStarRate()const;
    bool hasExtraBed() const;
    std::string getSuiteSize() const;
    void print()const;
    string getView()const;
};

#endif
