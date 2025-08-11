#include <iostream>
#include "target.hpp"
#include "radar.hpp"

int main() {
    srand(time(NULL));


    Target targetA(1, 0.0, 0.0, 0.0,0);
    targetA.spawnTarget();
    targetA.trajectory();
    return 0;
}

