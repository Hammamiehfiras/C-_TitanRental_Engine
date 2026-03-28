#include "FleetManager.h"
#include "ElectricVehicle.h"
#include "Logger.h"
#include <fstream>
#include <algorithm> // Krävs för std::sort

void FleetManager::add(std::shared_ptr<Vehicle> v) { cars.push_back(v); }

// Sorterings-algoritm med Lambda-uttryck
void FleetManager::sortByPrice() {
    std::sort(cars.begin(), cars.end(), [](const std::shared_ptr<Vehicle>& a, const std::shared_ptr<Vehicle>& b) {
        return a->getBasePrice() < b->getBasePrice(); // Jämför priser
        });
    Logger::get()->log("Vagnparken sorterad efter lägsta pris.");
}

std::vector<std::shared_ptr<Vehicle>> FleetManager::search(GeoLocation l, double r) {
    std::vector<std::shared_ptr<Vehicle>> res;
    for (auto& v : cars) if (l.distanceTo(v->getLoc()) <= r) res.push_back(v);
    return res;
}

bool FleetManager::remove(std::string plate) {
    auto it = std::remove_if(cars.begin(), cars.end(), [&](auto v) { return v->getPlate() == plate; });
    if (it != cars.end()) { cars.erase(it, cars.end()); return true; }
    return false;
}

void FleetManager::saveToFile(std::string f) {
    std::ofstream file(f);
    for (auto& v : cars) file << v->getPlate() << "|" << v->getBrand() << "|" << v->getBasePrice() << "|" << v->getLoc().lat << "|" << v->getLoc().lon << "\n";
}

void FleetManager::loadFromFile(std::string f) {
    std::ifstream file(f);
    std::string p, b, line; double pr, lt, ln;
    // Vi använder en säkrare inläsning här för att hantera mellanslag i filen
    while (std::getline(file, line)) {
        size_t p1 = line.find('|'); size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1); size_t p4 = line.find('|', p3 + 1);
        if (p1 != std::string::npos) {
            p = line.substr(0, p1);
            b = line.substr(p1 + 1, p2 - p1 - 1);
            pr = std::stod(line.substr(p2 + 1, p3 - p2 - 1));
            lt = std::stod(line.substr(p3 + 1, p4 - p3 - 1));
            ln = std::stod(line.substr(p4 + 1));
            add(std::make_shared<ElectricVehicle>(p, b, pr, GeoLocation(lt, ln)));
        }
    }
}