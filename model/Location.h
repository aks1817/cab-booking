#ifndef LOCATION_H
#define LOCATION_H

class Location {
private:
    double x;
    double y;

public:
    Location(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    double distanceTo(const Location& other) const {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

#endif
