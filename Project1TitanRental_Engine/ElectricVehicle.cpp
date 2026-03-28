#include "ElectricVehicle.h"
ElectricVehicle::ElectricVehicle(std::string p, std::string b, double pr, GeoLocation l)
    : Vehicle(p, b, pr, l) {
}
double ElectricVehicle::calculatePrice(int d) const { return (basePrice * d) * 0.9; }