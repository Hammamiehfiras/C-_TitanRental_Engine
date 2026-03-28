#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H
#include <vector>
#include <memory>
#include <string>
#include "Vehicle.h"
#include "GeoLocation.h"

class FleetManager {
    std::vector<std::shared_ptr<Vehicle>> cars;
public:
    void add(std::shared_ptr<Vehicle> v);
    std::vector<std::shared_ptr<Vehicle>> search(GeoLocation l, double r);
    bool remove(std::string plate);
    void saveToFile(std::string filename);
    void loadFromFile(std::string filename);

    // NY ALGORITM: Sortering
    void sortByPrice();
};
#endif