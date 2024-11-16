#ifndef DEFAULTCABMATCHINGSTRATEGY_H
#define DEFAULTCABMATCHINGSTRATEGY_H

#include "CabMatchingStrategy.h"

class DefaultCabMatchingStrategy : public CabMatchingStrategy {
public:
    Cab* findCab(const std::vector<Cab>& availableCabs, const Location& riderLocation) override {
        Cab* closestCab = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (const auto& cab : availableCabs) {
            double distance = cab.getLocation().distanceTo(riderLocation);
            if (distance < minDistance) {
                minDistance = distance;
                closestCab = const_cast<Cab*>(&cab);
            }
        }

        return closestCab;
    }
};

#endif
