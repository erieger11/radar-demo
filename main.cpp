#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "target.hpp"
#include "radar.hpp"

int main() {
    srand(time(NULL));

    Radar radar("radar_config.txt", "radar_logs_3.txt");
    radar.radarSettings();  

    std::vector<Target> all_targets;

    int tick = 0;
    bool running = true;

    while (running) {

        radar.sweep();
        std::cout << "Radar current Angle: " << radar.currentAngle << std::endl;

        if (rand() % 2 == 0 && all_targets.size() < radar.maxTargets) {
            int newId = all_targets.size() + 1;
            Target target(newId, 0.0, 0.0, 0.0, "", false, false);
            target.spawnTarget();
            all_targets.push_back(target);

            std::cout << "Target spawn --- ID: " << target.id
                      << ", Position: (" << target.xPosition << ", " << target.yPosition << ")"
                      << ", Speed: " << target.speed
                      << " MPH, Direction: " << target.direction << std::endl;
        }

        for(Target& t : all_targets){
                t.trajectory();
        }

        std::vector<Target*> detectedTargets = radar.detection(all_targets);
        for (Target* dt : detectedTargets) {
            radar.logTarget(*dt);
        }

        tick++;
        if (tick >= radar.maxTicks) {
            running = false;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(radar.tickDurationMs));
        std::cout << "-------------------------------------\n";
    }

    std::cout << "Simulation complete!" << std::endl;
    return 0;
}
