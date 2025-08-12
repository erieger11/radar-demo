#include <iostream>
#include "target.hpp"
#include "radar.hpp"

int main() {
    srand(time(NULL));

    std::vector<Target> all_targets;

    for(int i = 0 ; i < rand() % 11 ; i ++){
        Target target(i + 1, 0.0, 0.0, 0.0, "");
        target.spawnTarget();
        target.trajectory();
        all_targets.push_back(target);
    }


    for (const auto& target : all_targets) {
        std::cout << "ID: " << target.id
                  << ", Position: (" << target.xPosition << ", " << target.yPosition << ")"
                  << ", Speed: " << target.speed
                  << " MPH, Direction: " << target.direction << std::endl;
    }

    return 0;
}

