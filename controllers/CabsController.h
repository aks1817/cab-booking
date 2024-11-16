#ifndef CABSCONTROLLER_H
#define CABSCONTROLLER_H

#include <iostream>
#include "../database/CabsManager.h"

class CabsController {
private:
    CabsManager& cabsManager;

public:
    CabsController(CabsManager& manager) : cabsManager(manager) {}

    void registerCab(const std::string& cabId, const Location& location) {
        try {
            cabsManager.registerCab(Cab(cabId, location));
            std::cout << "Cab " << cabId << " registered successfully.\n";
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << "\n";
        }
    }

    void updateCabLocation(const std::string& cabId, const Location& location) {
        try {
            Cab& cab = cabsManager.getCab(cabId);
            cab.setLocation(location);
            std::cout << "Cab location updated.\n";
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << "\n";
        }
    }

    void toggleCabAvailability(const std::string& cabId, bool isAvailable) {
        try {
            Cab& cab = cabsManager.getCab(cabId);
            cab.setAvailability(isAvailable);
            std::cout << "Cab availability updated.\n";
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << "\n";
        }
    }
};

#endif
