#include <iostream>
#include <vector>
#include <thread>     
#include <chrono>     
#include <cstdlib>    
#include <ctime>      
#include "target.hpp"
#include "radar.hpp"
#include "logging.hpp"

int main() {
    srand(time(NULL));

    Logging logger("example.txt");
    Radar radar;

    std::vector<Target> all_targets;
    const int maxTargets = 3;  
    const int maxTicks = 72; 
    const int tickDurationMs = 1000;

    int tick = 0;
    bool running = true;

while(running){
    int spawnFlag = rand() % 2; 
    radar.sweep();

    if (spawnFlag == 0 && all_targets.size() < maxTargets) {
        int newId = all_targets.size() + 1;
        Target target(newId, 0.0, 0.0, 0.0, "", false, false);
        target.spawnTarget();
        target.trajectory();
        all_targets.push_back(target);

        std::cout << "Target spawn --- ID: " << target.id
                  << ", Position: (" << target.xPosition << ", " << target.yPosition << ")"
                  << ", Speed: " << target.speed
                  << " MPH, Direction: " << target.direction << std::endl;
    }

    std::cout << "Radar current Angle : " << radar.currentAngle << std::endl;

    tick++;

    std::vector<Target*> detectedTargets = radar.detection(all_targets);

    radar.updateDetectionHistory(all_targets);

    for(const Target* dt : detectedTargets){
        std::string msg = radar.logTarget(*dt);
        if(!msg.empty()){  
            std::cout << msg << std::endl;
        }
    }

    if(tick >= maxTicks){
        running = false;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(tickDurationMs));
    std::cout << "-------------------------------------\n";
}

    logger.writeToFile("Hello, this is a test log!");
    logger.readFromFile();
    
    std::cout << "Simulation complete!" << std::endl;

    return 0;
}

