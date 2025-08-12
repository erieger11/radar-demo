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

    Target(int target_id, double target_xPosition, double target_yPosition, double target_speed, std::string target_direction){
        id = target_id;
        xPosition = target_xPosition;
        yPosition = target_yPosition;
        speed = target_speed;
        direction = target_direction;

    }

    void trajectory();
    void spawnTarget();

};

#endif 