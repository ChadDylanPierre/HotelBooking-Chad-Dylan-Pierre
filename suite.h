#ifndef SUITE_H
#define SUITE_H

#include "Room.h"
#include <string>

class Suite : public Room {
    private: 
        std::string suiteSize; // "small", "medium", "large"
public:
    Suite(int number, const std::string& size);
    virtual std::string getRoomInfo() const override;
    virtual void print() const override;
    std::string getSize() const;
};

#endif
