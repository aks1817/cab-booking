#ifndef CABMATCHINGSTRATEGY_H
#define CABMATCHINGSTRATEGY_H

#include <vector>
#include "../model/Cab.h"

class CabMatchingStrategy {
public:
    virtual Cab* findCab(const std::vector<Cab>& availableCabs, const Location& riderLocation) = 0;
};

#endif
