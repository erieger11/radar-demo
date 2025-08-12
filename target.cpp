#include <iostream>
#include "target.hpp"
#include <cstdlib>


void Target::spawnTarget(){
    
    int zone = rand() % 2;
    double random_Scale = rand() / (double)RAND_MAX;

    if(zone == 0){
        xPosition = -400.0 + random_Scale * 100.0;
     } else {
        xPosition = 300.0 + random_Scale * 100.0;  
    }

    int zone2 = rand() % 2;
    double random_Scale2 = rand() / (double)RAND_MAX;

    if(zone2 == 0){
        yPosition = -400.0 + random_Scale2 * 100.0;
     } else {
        yPosition = 300.0 + random_Scale2 * 100.0;  
    }

}

void Target::trajectory() {
    speed = 101.0 + (rand() / (double)RAND_MAX) * 200.0;


    switch(rand() % 8) {
        case 0: direction = "NW"; break;
        case 1: direction = "N"; break;
        case 2: direction = "NE"; break;
        case 3: direction = "E"; break;
        case 4: direction = "SE"; break;
        case 5: direction = "S"; break;
        case 6: direction = "SW"; break;
        case 7: direction = "W"; break;
        default: std::cout << "Invalid Direction" << std::endl; break;
    }
}
