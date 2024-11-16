#ifndef RIDERSCONTROLLER_H
#define RIDERSCONTROLLER_H

#include <iostream>
#include "../database/RidersManager.h"
#include "../database/TripsManager.h"
#include "../strategies/CabMatchingStrategy.h"
#include "../strategies/PricingStrategy.h"

class RidersController {
private:
    RidersManager& ridersManager;
    TripsManager& tripsManager;

public:
    RidersController(RidersManager& rManager, TripsManager& tManager)
        : ridersManager(rManager), tripsManager(tManager) {}

    void registerRider(const std::string& riderId, const std::string& name) {
        try {
            ridersManager.registerRider(Rider(riderId, name));
            std::cout << "Rider " << name << " registered successfully.\n";
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << "\n";
        }
    }

    void bookCab(const std::string& riderId, const Location& start, const Location& end,
                 CabsManager& cabsManager, CabMatchingStrategy& matchingStrategy, PricingStrategy& pricingStrategy) {
        try {
            Rider& rider = ridersManager.getRider(riderId);

            // Find the best cab
            Cab* cab = matchingStrategy.findCab(cabsManager.getAvailableCabs(), start);
            if (!cab) {
                throw std::runtime_error("No cabs available.");
            }

            double fare = pricingStrategy.calculateFare(start, end);
            cab->setAvailability(false);

            Trip trip(cab->getId(), rider.getId(), start, end);
            tripsManager.addTrip(trip);
            rider.addTrip(trip);

            std::cout << "Cab booked successfully. Fare: " << fare << "\n";
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << "\n";
        }
    }

    void endTrip(const std::string& riderId) {
        try {
            Rider& rider = ridersManager.getRider(riderId);
            if (rider.getTripHistory().empty()) {
                throw std::runtime_error("No ongoing trips.");
            }

            Trip& trip = const_cast<Trip&>(rider.getTripHistory().back());
            if (trip.getStatus() == TripStatus::COMPLETED) {
                throw std::runtime_error("Trip already completed.");
            }

            trip.endTrip();
            std::cout << "Trip ended successfully.\n";
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << "\n";
        }
    }
};

#endif
