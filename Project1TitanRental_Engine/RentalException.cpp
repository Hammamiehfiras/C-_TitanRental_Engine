#include "RentalException.h"

// Konstruktorn: Tar emot ett felmeddelande och sparar det
RentalException::RentalException(std::string m) : msg("TITAN-ERROR: " + m) {
}

// what(): Returnerar felmeddelandet till systemet
const char* RentalException::what() const noexcept {
    return msg.c_str();
}