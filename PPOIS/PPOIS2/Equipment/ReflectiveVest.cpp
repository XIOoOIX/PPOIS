#include "ReflectiveVest.h"
#include <iostream>

ReflectiveVest::ReflectiveVest(const std::string& name, double cost, const std::string& size, const std::string& color)
    : Workwear(name, cost, size, color), reflectiveActive(false) {}

void ReflectiveVest::ActivateReflection() {
    reflectiveActive = true;
    std::cout << name << " отражающий слой активирован.\n";
}

void ReflectiveVest::DeactivateReflection() {
    reflectiveActive = false;
    std::cout << name << " отражающий слой выключен.\n";
}

void ReflectiveVest::PrintInfo() const {
    std::cout << "Жилет " << name << ", светоотражение: "
              << (reflectiveActive ? "включено" : "выключено") << ".\n";
}
