#include "radar.hpp"
#include <cmath>

// Advance radar sweep
void Radar::sweep() {
    currentAngle += sweepStep;
    if (currentAngle >= 360.0) currentAngle -= 360.0;
}

// Detect targets within radar sweep arc
std::vector<Target*> Radar::detection(std::vector<Target>& all_targets) {
    double startAngle = currentAngle - sweepWidth / 2.0;
    double endAngle = currentAngle + sweepWidth / 2.0;

    std::vector<Target*> detected;

    for (auto& t : all_targets) {
        double distance = std::sqrt(t.xPosition * t.xPosition + t.yPosition * t.yPosition);
        if (distance > detectionDepth) {
            t.detectionStatus = false;
            continue;
        }

        double angleDegrees = atan2(t.yPosition, t.xPosition) * 180.0 / M_PI;
        if (angleDegrees < 0) angleDegrees += 360.0;

        bool wrapsAround = false;
        double adjStart = startAngle, adjEnd = endAngle;

        if (startAngle < 0) { adjStart += 360; adjEnd += 360; }
        else if (endAngle > 360) { wrapsAround = true; adjEnd -= 360; }

        bool insideArc = !wrapsAround ?
            (angleDegrees >= adjStart && angleDegrees <= adjEnd) :
            (angleDegrees >= adjStart || angleDegrees <= adjEnd);

        t.detectionStatus = insideArc;
        if (insideArc) detected.push_back(&t);
    }

    return detected;
}

// Update previouslyDetected for next sweep
void Radar::updateDetectionHistory(std::vector<Target>& all_targets) {
    for (auto& t : all_targets) {
        t.previouslyDetected = t.detectionStatus;
    }
}

// Log the status of a target
std::string Radar::logTarget(const Target& t) {
    double angleDegrees = atan2(t.yPosition, t.xPosition) * 180.0 / M_PI;
    if (angleDegrees < 0) angleDegrees += 360.0;

    std::string message;

    if (t.detectionStatus && !t.previouslyDetected) message = "Target has been spotted!\n";
    else if (t.detectionStatus && t.previouslyDetected) message = "Target location updated.\n";
    else if (!t.detectionStatus && t.previouslyDetected) message = "Target lost from radar.\n";
    else return ""; // invisible, skip logging

    message += "ID - " + std::to_string(t.id) + "\n" +
               "X coord - " + std::to_string(t.xPosition) + "\n" +
               "Y coord - " + std::to_string(t.yPosition) + "\n" +
               "Target angle - " + std::to_string(angleDegrees) + " degrees\n" +
               "Speed - " + std::to_string(t.speed) + "\n" +
               "Direction - " + t.direction;

    return message;
}
