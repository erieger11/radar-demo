#ifndef RADAR_HPP
#define RADAR_HPP
#include <iostream>
#include <vector>
#include "target.hpp"

class Radar{

private:
    int radarNumber = 1;
    double currentAngle = 0.0;
    double sweepStep = 10.0;
    double detectionDepth = 300.0;
    double sweepWidth = 10.0;


public:

    void sweep();
    std::vector<Target> detection(const std::vector<Target> & all_targets);
    std::string logTarget(const Target& target);

};

#endif 
