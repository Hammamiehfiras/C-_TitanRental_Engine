#include "Logger.h"
#include <iostream>

Logger* Logger::instance = nullptr;

Logger* Logger::get() {
    if (!instance) instance = new Logger();
    return instance;
}

void Logger::log(std::string m) {
    std::cout << "[TITAN-LOG]: " << m << std::endl;
}