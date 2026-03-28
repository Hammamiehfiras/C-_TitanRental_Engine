#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H
#include <memory>
#include "Vehicle.h"
#include "Customer.h"
class BookingSystem {
public:
    void createBooking(std::shared_ptr<Customer> c, std::shared_ptr<Vehicle> v);
};
#endif