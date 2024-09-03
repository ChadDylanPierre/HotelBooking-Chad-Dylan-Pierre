#include "Date.h"
#include <iostream>

Date::Date(int m, int d, int y) : month(m), day(d), year(y) {}

int Date::toDayNumber() const {
    return (month - 1) * 30 + day;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}


void Date::print()const
{
    std::cout << this->day << "/" << this->month << "/" << this->year;
}


ostream& operator<<(ostream&output, const Date&date) {

    output << date.month<<" " << date.day<<" " << date.year;
    return output;


 }


bool Date::operator>(const Date&other)const {

    return (toDayNumber() > other.toDayNumber());
        


}