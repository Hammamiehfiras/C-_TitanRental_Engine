#include "Vehicle.h"
Vehicle::Vehicle(std::string p, std::string b, double pr, GeoLocation l)
    : plate(p), brand(b), basePrice(pr), loc(l) {
}