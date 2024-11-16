#ifndef RIDER_H
#define RIDER_H

#include <string>
#include <vector>
#include "Trip.h"

class Rider {
private:
    std::string id;
    std::string name;
    std::vector<Trip> tripHistory;

public:
    Rider() : id("default_id"), name("default_name") {}  // Default constructor
    Rider(const std::string& id, const std::string& name) : id(id), name(name) {}

    const std::string& getId() const { return id; }
    const std::string& getName() const { return name; }

    void addTrip(const Trip& trip) { tripHistory.push_back(trip); }
    const std::vector<Trip>& getTripHistory() const { return tripHistory; }
};

#endif
