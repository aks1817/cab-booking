#ifndef DEFAULTPRICINGSTRATEGY_H
#define DEFAULTPRICINGSTRATEGY_H

#include "PricingStrategy.h"

class DefaultPricingStrategy : public PricingStrategy {
public:
    double calculateFare(const Location& start, const Location& end) override {
        double distance = start.distanceTo(end);
        return distance * 10.0; // Fare: 10 units per distance
    }
};

#endif
