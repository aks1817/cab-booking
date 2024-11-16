#include <iostream>
#include "controllers/CabsController.h"
#include "controllers/RidersController.h"
#include "strategies/DefaultCabMatchingStrategy.h"
#include "strategies/DefaultPricingStrategy.h"

int main() {
    CabsManager cabsManager;
    RidersManager ridersManager;
    TripsManager tripsManager;

    CabsController cabsController(cabsManager);
    RidersController ridersController(ridersManager, tripsManager);

    DefaultCabMatchingStrategy matchingStrategy;
    DefaultPricingStrategy pricingStrategy;

    // Register cabs
    cabsController.registerCab("CAB001", Location(0, 0));
    cabsController.registerCab("CAB002", Location(10, 10));

    // Register riders
    ridersController.registerRider("RIDER001", "John Doe");

    // Update cab location
    cabsController.updateCabLocation("CAB001", Location(5, 5));

    // Book a cab
    ridersController.bookCab("RIDER001", Location(2, 2), Location(8, 8), cabsManager, matchingStrategy, pricingStrategy);

    // End the trip
    ridersController.endTrip("RIDER001");

    return 0;
}
