#include <iostream>
#include <cmath>
#include "radar.hpp"
#include "target.hpp"

void Radar::sweep(){
    currentAngle += sweepStep;
    if(currentAngle > 360.0){
        currentAngle -= 360.0;
    }
}


std::vector<Target> Radar::detection(const std::vector<Target> & all_targets){
    double startAngle = currentAngle - sweepWidth / 2.0;
    double endAngle = currentAngle + sweepWidth / 2.0;

    std::vector<Target> detectedTargets;

    for (const auto& t : all_targets) {
    double distance = std::sqrt(std::pow(t.xPosition, 2) + std::pow(t.yPosition, 2));

    if (distance > detectionDepth) {
        continue;
    }

    double angleRadians = atan2(t.yPosition, t.xPosition);
    double angleDegrees = angleRadians * 180.0 / M_PI;
    if(angleDegrees < 0){
        angleDegrees+= 360.0;
    }
    
    bool wrapsAround = false;
    double adjustedStart = startAngle;
    double adjustedEnd = endAngle;

    if(startAngle < 0){
        adjustedStart += 360.0;
        adjustedEnd += 360.0;
    }else if(endAngle > 360.0){
        wrapsAround = true;
        adjustedEnd -= 360.0;
    }

    bool insideArc = false;
    if(!wrapsAround){
        insideArc = (angleDegrees >= adjustedStart && angleDegrees <= adjustedEnd);
    }else{
        insideArc = (angleDegrees >= adjustedStart || angleDegrees <= adjustedEnd);
    }

    if(insideArc){
        detectedTargets.push_back(t);
    }
 }

 return detectedTargets;

}

std::string Radar::logTarget(const Target& spottedTarget){

    std::string message = "Target has been spotted!\n"
                           "X cord - " + std::to_string(spottedTarget.xPosition) + "\n"
                           "Y cord - " + std::to_string(spottedTarget.yPosition) + "\n"
                           "Speed - " + std::to_string(spottedTarget.speed) + "\n"
                           "Direction - " + spottedTarget.direction;

    return message;

}