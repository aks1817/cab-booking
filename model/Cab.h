#ifndef CAB_H
#define CAB_H

#include <string>
#include "Location.h"

class Cab {
private:
    std::string id;
    Location location;
    bool isAvailable;

public:
    Cab() : id("default_id"), location(Location(0.0, 0.0)), isAvailable(true) {} // Default constructor
    Cab(const std::string& id, const Location& loc) : id(id), location(loc), isAvailable(true) {}

    const std::string& getId() const { return id; }
    const Location& getLocation() const { return location; }
    bool getAvailability() const { return isAvailable; }

    void setLocation(const Location& loc) { location = loc; }
    void setAvailability(bool availability) { isAvailable = availability; }
};

#endif
