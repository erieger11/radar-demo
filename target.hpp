#ifndef TARGET_HPP
#define TARGET_HPP
#include <iostream>
#include <vector>
#include <string>

class Target{

private:
   


public:

    int id;
    double xPosition;
    double yPosition;
    double speed;
    std::string direction;
    bool detectionStatus;
    bool previouslyDetected;

    Target(int target_id, double target_xPosition, double target_yPosition, double target_speed, std::string target_direction, 
        bool target_detectionStatus, bool target_previouslyDetected){
        id = target_id;
        xPosition = target_xPosition;
        yPosition = target_yPosition;
        speed = target_speed;
        direction = target_direction;
        detectionStatus = target_detectionStatus;
        previouslyDetected = target_previouslyDetected;

    }

    void trajectory();
    void spawnTarget();

};

#endif 

