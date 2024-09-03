#ifndef STDROOM_H
#define STDROOM_H

#include "room.h"

class StdRoom : public Room {
private: 
    bool extraBed;
public:
    StdRoom(int number);
    virtual std::string getRoomInfo() const override;
    virtual void print() const override;
    void setExtraBed(bool extra);
    bool hasExtraBed() const;
};

#endif
