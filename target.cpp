#include <iostream>
#include "target.hpp"
#include <cstdlib>


void Target::spawnTarget(){
    srand(time(NULL));

    xPosition = 101 + rand() % 400;
    yPosition = 101 + rand() % 400;
    speed = rand() % 10;

    std::cout << "X: "<< xPosition << "\n";
    std::cout << "Y: "<< yPosition << "\n";
    std::cout << "Speed: "<< speed << "\n";

}

void Target::trajectory(){

}