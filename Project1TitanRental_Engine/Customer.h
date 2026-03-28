#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
class Customer {
    std::string name;
public:
    Customer(std::string n);
    std::string getName() const { return name; }
};
#endif