
#pragma once
#include <vector>
#include <string>

struct FanCommand {
    int layer;
    int speed; // 0-255 PWM
    std::string comment;
};

class FanControlManager {
public:
    FanControlManager();

    void registerExtrusionMove(double x, double y, double z, double e, double speed);
    void registerTravelMove(double x, double y, double z, double speed);
    void startNewLayer(int layer);
    void finalizeLayer();
    void applyFanLogic(std::vector<std::string>& gcode_lines);

private:
    int current_layer;
    double last_e;
    int current_fan_speed;
    std::vector<FanCommand> fan_commands;

    void updateFanSpeed(int new_speed, const std::string& reason);
};
