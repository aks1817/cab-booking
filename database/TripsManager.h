#ifndef TRIPSMANAGER_H
#define TRIPSMANAGER_H

#include <vector>
#include "Trip.h"

class TripsManager {
private:
    std::vector<Trip> trips;

public:
    void addTrip(const Trip& trip) { trips.push_back(trip); }
    const std::vector<Trip>& getTrips() const { return trips; }
};

#endif
