#include "radar.hpp"
#include <cmath>
#include <iostream>
#include <fstream>

Radar::Radar(const std::string& configFile, const std::string& logFile)
    : configFileName(configFile), logFileName(logFile) {}

// Reads simulation settings from config file
void Radar::radarSettings() {
    std::ifstream inFile(configFileName);

    if (inFile.is_open()) {
        std::string line;

        while (std::getline(inFile, line)) {
            int equalPosition = line.find('=');

            if (equalPosition == std::string::npos) {
                // skip lines without '='
                continue;
            }

            std::string key = line.substr(0, equalPosition);
            std::string value = line.substr(equalPosition + 1);

            if (key == "maxTargets") {
                maxTargets = std::stoi(value);
            } else if (key == "maxTicks") {
                maxTicks = std::stoi(value);
            } else if (key == "tickDurationMs") {
                tickDurationMs = std::stoi(value);
            }
        }

        inFile.close();
        std::cout << "Loaded radar settings from: " << configFileName << std::endl;
    } else {
        std::cerr << "Error opening config file: " << configFileName << std::endl;
    }
}

// Moves the radar sweep
void Radar::sweep() {
    currentAngle += sweepStep;
    if (currentAngle >= 360.0) currentAngle -= 360.0;
}

// Detects targets within sweep area
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

// Logs target info to the log file
void Radar::logTarget(const Target& t) {
    double angleDegrees = atan2(t.yPosition, t.xPosition) * 180.0 / M_PI;
    if (angleDegrees < 0) angleDegrees += 360.0;

    std::string message;

    if (t.detectionStatus && !t.previouslyDetected) message = "Target has been spotted!\n";
    else if (t.detectionStatus && t.previouslyDetected) message = "Target location updated.\n";
    else if (!t.detectionStatus && t.previouslyDetected) message = "Target lost from radar.\n";
    else message = "";

    message += "ID - " + std::to_string(t.id) + "\n" +
               "X coord - " + std::to_string(t.xPosition) + "\n" +
               "Y coord - " + std::to_string(t.yPosition) + "\n" +
               "Target angle - " + std::to_string(angleDegrees) + " degrees\n" +
               "Speed - " + std::to_string(t.speed) + "\n" +
               "Direction - " + t.direction + "\n";

    std::ofstream outFile(logFileName, std::ios::app);
    if (outFile.is_open()) {
        outFile << message << std::endl;
        outFile.close();
        std::cout << "Wrote to file: " << logFileName << std::endl;
    } else {
        std::cerr << "Error opening file to write" << std::endl;
    }
}
