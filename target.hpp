#include <iostream>
#include <vector>

class Target{

private:
    int id;
    double xPosition;
    double yPosition;
    double speed;


public:
    Target(int target_id, double target_xPosition, double target_yPosition, double target_speed){
    id = target_id;
    xPosition = target_xPosition;
    yPosition = target_yPosition;
    speed = target_speed;

    }
    void trajectory();
    void spawnTarget();

};