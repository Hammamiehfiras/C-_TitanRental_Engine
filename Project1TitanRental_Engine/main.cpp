#include <iostream>
#include <vector>
#include <memory>
#include <clocale>
#include <string>
#include "FleetManager.h"
#include "ElectricVehicle.h"
#include "Logger.h"

int main() {
    std::setlocale(LC_ALL, "Swedish");
    FleetManager fm;
    fm.loadFromFile("vagnpark.txt");

    int val = 0;
    while (val != 5) {
        std::cout << "\n--- TITAN RENTAL ADMIN PANEL ---\n";
        std::cout << "1. Registrera nytt fordon\n2. Visa sorterad vagnpark\n3. Ta bort fordon\n4. Spara\n5. Avsluta\nVal: ";
        std::cin >> val;
        std::cin.ignore(); // Rensar Enter-tryckningen ur kön

        if (val == 1) {
            std::string id, marke; double pris;
            std::cout << "Reg-nummer: "; std::getline(std::cin, id);
            std::cout << "Märke (t.ex. Peugeot 208): "; std::getline(std::cin, marke);
            std::cout << "Pris: "; std::cin >> pris;
            fm.add(std::make_shared<ElectricVehicle>(id, marke, pris, GeoLocation(59.3, 18.0)));
        }
        else if (val == 2) {
            fm.sortByPrice(); // KÖR SORTERINGEN!
            auto bilar = fm.search(GeoLocation(59.3, 18.0), 500.0);
            std::cout << "\nLISTA (Billigast först):\n";
            for (const auto& v : bilar) {
                std::cout << "- " << v->getBrand() << " [" << v->getPlate() << "] Pris: " << v->getBasePrice() << " kr\n";
            }
        }
        else if (val == 3) {
            std::string id; std::cout << "ID att radera: "; std::getline(std::cin, id);
            if (fm.remove(id)) std::cout << "Raderad.\n";
        }
        else if (val == 4) {
            fm.saveToFile("vagnpark.txt");
            std::cout << "Sparat!\n";
        }
    }
    return 0;
}