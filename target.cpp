#include "target.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>


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

    speed = 101.0 + (rand() / (double)RAND_MAX) * 200.0;
    int dir = rand() % 8;
    direction = directionFromInt(dir);       
    angleRad = angleFromDirection(direction); 
    prevX = xPosition;
    prevY = yPosition;

}


void Target::trajectory() {
    prevX = xPosition;
    prevY = yPosition;

    double tickScale = 0.05;
    xPosition += speed * tickScale * cos(angleRad);
    yPosition += speed * tickScale * sin(angleRad);
}

std::string Target::directionFromInt(int dir) {
    switch(dir) {
        case 0: return "NW";
        case 1: return "N";
        case 2: return "NE";
        case 3: return "E";
        case 4: return "SE";
        case 5: return "S";
        case 6: return "SW";
        case 7: return "W";
        default: return "N";
    }
}

double Target::angleFromDirection(const std::string& dir) {
    if(dir == "NW") return 3 * M_PI / 4;
    if(dir == "N")  return M_PI / 2;
    if(dir == "NE") return M_PI / 4;
    if(dir == "E")  return 0;
    if(dir == "SE") return -M_PI / 4;
    if(dir == "S")  return -M_PI / 2;
    if(dir == "SW") return -3 * M_PI / 4;
    if(dir == "W")  return M_PI;
    return 0;
}

