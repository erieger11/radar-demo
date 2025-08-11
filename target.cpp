#include <iostream>
#include "target.hpp"
#include <cstdlib>


void Target::spawnTarget(){

    xPosition = 101 + rand() % 400;
    yPosition = 101 + rand() % 400;
    speed = rand() % 10;
    direction = 0;

    std::cout << "X: "<< xPosition << "\n";
    std::cout << "Y: "<< yPosition << "\n";
    std::cout << "Speed: "<< speed << "\n";

}

void Target::trajectory() {
    direction = rand() % 8;
    switch(direction) {
        case 0: std::cout << "Target Direction: NW" << std::endl; break;
        case 1: std::cout << "Target Direction: N" << std::endl; break;
        case 2: std::cout << "Target Direction: NE" << std::endl; break;
        case 3: std::cout << "Target Direction: E" << std::endl; break;
        case 4: std::cout << "Target Direction: SE" << std::endl; break;
        case 5: std::cout << "Target Direction: S" << std::endl; break;
        case 6: std::cout << "Target Direction: SW" << std::endl; break;
        case 7: std::cout << "Target Direction: W" << std::endl; break;
        default: std::cout << "Invalid Direction" << std::endl; break;
    }
}
