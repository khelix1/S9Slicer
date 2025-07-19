
#include "fan_control.h"
#include <iostream>

FanControlManager::FanControlManager()
    : current_layer(0), last_e(0.0), current_fan_speed(0) {}

void FanControlManager::registerExtrusionMove(double x, double y, double z, double e, double speed) {
    if ((e - last_e) > 0.01) {
        updateFanSpeed(255, "Extruding");
    }
    last_e = e;
}

void FanControlManager::registerTravelMove(double x, double y, double z, double speed) {
    updateFanSpeed(64, "Travel move");
}

void FanControlManager::startNewLayer(int layer) {
    current_layer = layer;
}

void FanControlManager::finalizeLayer() {
    fan_commands.push_back({current_layer, current_fan_speed, "Layer complete"});
}

void FanControlManager::updateFanSpeed(int new_speed, const std::string& reason) {
    if (new_speed != current_fan_speed) {
        current_fan_speed = new_speed;
        std::cout << "; Fan speed change: " << new_speed << " due to " << reason << std::endl;
    }
}

void FanControlManager::applyFanLogic(std::vector<std::string>& gcode_lines) {
    for (const auto& cmd : fan_commands) {
        gcode_lines.push_back("; Applying fan command at layer " + std::to_string(cmd.layer));
        gcode_lines.push_back("M106 S" + std::to_string(cmd.speed) + " ; " + cmd.comment);
    }
}
