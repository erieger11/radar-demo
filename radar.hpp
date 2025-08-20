#ifndef RADAR_HPP
#define RADAR_HPP
#include <iostream>
#include <vector>
#include "target.hpp"

class Radar{

public:

    int radarNumber = 1;
    double currentAngle = 0.0;
    double sweepStep = 10.0;
    double detectionDepth = 1000.0;
    double sweepWidth = 10.0;

    void sweep();
    std::vector<Target*> detection(std::vector<Target>& all_targets);
    std::string logTarget(const Target& target);
    void updateDetectionHistory(std::vector<Target>& all_targets);

};

#endif 
