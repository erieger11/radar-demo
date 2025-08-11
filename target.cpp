#include <iostream>
#include "target.hpp"
#include <cstdlib>


void Target::spawnTarget(){
    id = 1;
    xPosition = 101.0 + (rand() / (double)RAND_MAX) * 400.0;
    yPosition = 101.0 + (rand() / (double)RAND_MAX) * 400.0;

    
}

void Target::trajectory() {
    speed = 101.0 + (rand() / (double)RAND_MAX) * 200.0;


    switch(rand() % 8) {
        case 0: direction = "NW"; break;
        case 1: direction = "NW"; break;
        case 2: direction = "NW"; break;
        case 3: direction = "NW"; break;
        case 4: direction = "NW"; break;
        case 5: direction = "NW"; break;
        case 6: direction = "NW"; break;
        case 7: direction = "NW"; break;
        default: std::cout << "Invalid Direction" << std::endl; break;
    }
}
