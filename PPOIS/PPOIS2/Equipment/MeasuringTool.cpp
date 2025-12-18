#include "MeasuringTool.h"
#include <iostream>

MeasuringTool::MeasuringTool(const std::string& name, double cost, double weight, double acc)
    : Tool(name, cost, weight, false), accuracy(acc) {}

void MeasuringTool::MeasureDistance(double meters) {
    std::cout << "Измерено расстояние: " << meters << " м с точностью " << accuracy << "%.\n";
}

void MeasuringTool::PrintInfo() const {
    std::cout << "Измерительный инструмент: " << name
              << ", точность " << accuracy << "%.\n";
}
