#include "Tool.h"
#include <iostream>

Tool::Tool(const std::string& name, double cost, double w, bool poweredTool)
    : Equipment(name, cost), weight(w), powered(poweredTool) {}

void Tool::UseTool() {
    std::cout << name << " используется на объекте.\n";
}

void Tool::Repair() {
    powered = true;
    std::cout << name << " отремонтирован.\n";
}

void Tool::CheckCondition() const {
    std::cout << "Инструмент " << name << ": " << (powered ? "исправен" : "неисправен") << ".\n";
}

void Tool::PrintInfo() const {
    std::cout << "Инструмент: " << name << ", масса " << weight << " кг.\n";
}
