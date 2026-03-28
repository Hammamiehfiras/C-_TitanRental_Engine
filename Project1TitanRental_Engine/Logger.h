#ifndef LOGGER_H
#define LOGGER_H
#include <string>

class Logger {
private:
    static Logger* instance;
    Logger() {}
public:
    static Logger* get(); // Måste heta exakt 'get'
    void log(std::string m);
};
#endif