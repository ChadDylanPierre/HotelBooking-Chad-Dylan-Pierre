#ifndef DELUXROOM_H
#define DELUXROOM_H

#include "Room.h"
#include <string>

class DeluxRoom : public Room {
private:
    std::string view; // "mountain" or "lake"
public:
    DeluxRoom(int number, const std::string& viewType);
    virtual std::string getRoomInfo() const override;
    virtual void print() const override;
    std::string getView() const;
};

#endif
