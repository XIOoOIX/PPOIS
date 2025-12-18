#include "Equipment.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Equipment::Equipment(const std::string& equipName, double equipCost)
    : name(equipName), cost(equipCost), working(false), assignedToSite(false) {}

void Equipment::Start() {
    if (working) throw EquipmentOverloadException("Оборудование уже работает!");
    working = true;
    std::cout << name << " запущено.\n";
}

void Equipment::Stop() {
    if (!working) throw InvalidAccessException("Попытка остановить неработающее оборудование.");
    working = false;
    std::cout << name << " остановлено.\n";
}

void Equipment::AssignToSite() {
    assignedToSite = true;
    std::cout << name << " направлено на строительную площадку.\n";
}

void Equipment::PrintInfo() const {
    std::cout << "Оборудование: " << name << ", стоимость: " << cost
              << ", статус: " << (working ? "работает" : "остановлено") << std::endl;
}
