#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include "GeoLocation.h"

class Vehicle {
protected:
    std::string plate, brand;
    double basePrice;
    GeoLocation loc;
public:
    Vehicle(std::string p, std::string b, double pr, GeoLocation l);
    virtual ~Vehicle() {}
    virtual double calculatePrice(int days) const = 0;

    // DESSA TVÅ RADER FIXAR FELET:
    std::string getPlate() const { return plate; }
    double getBasePrice() const { return basePrice; } // Denna saknades!

    std::string getBrand() const { return brand; }
    GeoLocation getLoc() const { return loc; }
};
#endif