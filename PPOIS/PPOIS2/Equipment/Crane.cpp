#include "Crane.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Crane::Crane(const std::string& name, double cost, double load, double height)
    : Vehicle(name, cost, load), maxHeight(height), isExtended(false) {}

void Crane::ExtendArm(double meters) {
    if (meters > maxHeight) throw EquipmentOverloadException("Превышена максимальная высота крана!");
    isExtended = true;
    std::cout << name << " выдвинул стрелу на " << meters << " м.\n";
}

void Crane::LiftLoad(double weight) {
    if (weight > maxLoad) throw EquipmentOverloadException("Перегруз крана!");
    std::cout << name << " поднял груз массой " << weight << " кг.\n";
}

void Crane::RetractArm() {
    isExtended = false;
    std::cout << "Стрела крана опущена.\n";
}

void Crane::PrintInfo() const {
    std::cout << "Кран: " << name << ", высота " << maxHeight << " м, "
              << "нагрузка " << maxLoad << " кг.\n";
}
