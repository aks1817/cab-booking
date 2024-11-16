#ifndef PRICINGSTRATEGY_H
#define PRICINGSTRATEGY_H

#include "../model/Location.h"

class PricingStrategy {
public:
    virtual double calculateFare(const Location& start, const Location& end) = 0;
};

#endif
