#ifndef CABSMANAGER_H
#define CABSMANAGER_H

#include <map>
#include <string>
#include "Cab.h"

class CabsManager {
private:
    std::map<std::string, Cab> cabs;

public:
    void registerCab(const Cab& cab) {
        if (cabs.find(cab.getId()) != cabs.end()) {
            throw std::runtime_error("Cab already exists");
        }
        cabs[cab.getId()] = cab;
    }

    Cab& getCab(const std::string& id) {
        if (cabs.find(id) == cabs.end()) {
            throw std::runtime_error("Cab not found");
        }
        return cabs[id];
    }

    std::vector<Cab> getAvailableCabs() const {
        std::vector<Cab> availableCabs;
        for (const auto& [id, cab] : cabs) {
            if (cab.getAvailability()) {
                availableCabs.push_back(cab);
            }
        }
        return availableCabs;
    }
};

#endif
