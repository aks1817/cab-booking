#ifndef TRIP_H
#define TRIP_H

#include <string>
#include "Location.h"

enum class TripStatus { ONGOING, COMPLETED };

class Trip {
private:
    std::string cabId;
    std::string riderId;
    Location startLocation;
    Location endLocation;
    TripStatus status;

public:
    Trip(const std::string& cabId, const std::string& riderId, const Location& start, const Location& end)
        : cabId(cabId), riderId(riderId), startLocation(start), endLocation(end), status(TripStatus::ONGOING) {}

    const std::string& getCabId() const { return cabId; }
    const std::string& getRiderId() const { return riderId; }
    TripStatus getStatus() const { return status; }

    void endTrip() { status = TripStatus::COMPLETED; }
};

#endif
