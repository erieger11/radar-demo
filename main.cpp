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

    Radar radar;

    std::vector<Target> all_targets;
    const int maxTargets = 10;  
    const int maxTicks = 20; 
    const int tickDurationMs = 2000;

    int tick = 0;
    bool running = true;

    while(running){
        int spawnFlag = rand() % 2; 
        radar.sweep();

        if (spawnFlag == 0 && all_targets.size() < maxTargets) {
            int newId = all_targets.size() + 1;
            Target target(newId, 0.0, 0.0, 0.0, "");
            target.spawnTarget();
            target.trajectory();
            all_targets.push_back(target);


        }
        
        std::cout << "Tick #" << tick + 1 << std::endl;

        for(Target& t : all_targets){
            //t.trajectory();
            std::cout << "ID: " << t.id
                  << ", Position: (" << t.xPosition << ", " << t.yPosition << ")"
                  << ", Speed: " << t.speed
                  << " MPH, Direction: " << t.direction << std::endl;
        }
        
        tick++;
        std::vector<Target> detectedTargets = radar.detection(all_targets);
        for(const Target& dt : detectedTargets){
            std::cout << radar.logTarget(dt) <<std::endl;
        }

        if(tick >= maxTicks){
            running = false;
        }
                std::this_thread::sleep_for(std::chrono::milliseconds(tickDurationMs));
                std::cout << "-------------------------------------\n";
    }

    std::cout << "Simulation complete!" << std::endl;

    return 0;
}

