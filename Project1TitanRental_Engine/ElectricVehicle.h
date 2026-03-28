#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H
#include "Vehicle.h"
class ElectricVehicle : public Vehicle {
public:
    ElectricVehicle(std::string p, std::string b, double pr, GeoLocation l);
    double calculatePrice(int days) const override;
};
#endif