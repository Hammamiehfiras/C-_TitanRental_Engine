#ifndef RENTALEXCEPTION_H
#define RENTALEXCEPTION_H

#include <exception>
#include <string>

class RentalException : public std::exception {
private:
    std::string msg; // Detta är variabeln som saknades (C2065)
public:
    // Konstruktor
    RentalException(std::string m);

    // override för what() - märk att den är 'const noexcept'
    const char* what() const noexcept override;
};

#endif