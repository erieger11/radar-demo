#include "logging.hpp"
#include <iostream>
#include <fstream>

Logging::Logging(const std::string& fName) : fileName(fName) {}

void Logging::writeToFile(const std::string& text) {
    std::ofstream outFile(fileName); 
    if (outFile.is_open()) {
        outFile << text << std::endl;
        outFile.close();
        std::cout << "Wrote to file: " << fileName << std::endl;
    } else {
        std::cerr << "Error opening file to write" << std::endl;
    }
}

void Logging::readFromFile() {
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Error opening file to read" << std::endl;
    }
}
