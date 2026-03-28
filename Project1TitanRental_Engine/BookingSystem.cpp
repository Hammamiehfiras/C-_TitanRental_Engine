#include "BookingSystem.h"
#include "Logger.h"
#include <iostream>
void BookingSystem::createBooking(std::shared_ptr<Customer> c, std::shared_ptr<Vehicle> v) {
    Logger::get()->log("Skapar bokning...");
    std::cout << "Bokning bekräftad: " << c->getName() << " hyr " << v->getPlate() << "\n";
}