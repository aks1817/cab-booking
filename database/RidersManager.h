#ifndef RIDERSMANAGER_H
#define RIDERSMANAGER_H

#include <map>
#include <string>
#include "Rider.h"

class RidersManager {
private:
    std::map<std::string, Rider> riders;

public:
    void registerRider(const Rider& rider) {
        if (riders.find(rider.getId()) != riders.end()) {
            throw std::runtime_error("Rider already exists");
        }
        riders[rider.getId()] = rider;
    }

    Rider& getRider(const std::string& id) {
        if (riders.find(id) == riders.end()) {
            throw std::runtime_error("Rider not found");
        }
        return riders[id];
    }
};

#endif
