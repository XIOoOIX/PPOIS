#include "Workwear.h"
#include <iostream>

Workwear::Workwear(const std::string& name, double cost, const std::string& s, const std::string& c)
    : Equipment(name, cost), size(s), color(c), clean(true) {}

void Workwear::Wash() {
    clean = true;
    std::cout << name << " выстирана и готова к использованию.\n";
}

void Workwear::CheckClean() {
    std::cout << name << " состояние: " << (clean ? "чистая" : "грязная") << ".\n";
}

void Workwear::PrintInfo() const {
    std::cout << "Спецодежда: " << name << ", размер " << size
              << ", цвет " << color << ".\n";
}
