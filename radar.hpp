#ifndef RADAR_HPP
#define RADAR_HPP
#include <iostream>
#include <vector>
#include "target.hpp"

class Radar{

private:
    std::string configFileName;
    std::string logFileName;


public:

    Radar(const std::string& configFile, const std::string& logFile);

    int maxTargets = 0;  
    int maxTicks = 0; 
    int tickDurationMs = 0;

    int radarNumber = 1;
    double currentAngle = 0.0;
    double sweepStep = 10.0;
    double detectionDepth = 1000.0;
    double sweepWidth = 10.0;
    

    void radarSettings();
    void sweep();
    std::vector<Target*> detection(std::vector<Target>& all_targets);
    void logTarget(const Target& target);

};

#endif 
