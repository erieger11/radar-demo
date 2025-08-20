#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <string>

class Logging {
private:
    std::string fileName;

public:
    Logging(const std::string& fName);

    void writeToFile(const std::string& text);
    void readFromFile();
};

#endif
