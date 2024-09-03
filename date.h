#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
using std::ostream;
using std::istream;


class Date {

    friend ostream& operator<<(ostream&, const Date&);
   

private:
    int month;
    int day;
    int year;
public:
    Date(int m, int d, int y);

    
    bool operator>(const Date&)const;
    int toDayNumber() const;
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    void print()const;
    

};

#endif
