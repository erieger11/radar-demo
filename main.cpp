#include <iostream>
#include "target.hpp"
#include "radar.hpp"

int main() {
    srand(time(NULL));


    Target targetA(0, 0.0, 0.0, 0.0,"");


    targetA.spawnTarget();
    targetA.trajectory();

    std::cout << "ID: " << targetA.id
              << ", Position: (" << targetA.xPosition << ", " << targetA.yPosition << ")"
              << ", Speed: " << targetA.speed
              << " MPH, Direction: " << targetA.direction << std::endl;


    return 0;
}

