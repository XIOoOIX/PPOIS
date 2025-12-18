#include "SteelConstruction.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

SteelConstruction::SteelConstruction(const std::string& addr, double area, int floors, double frameW)
    : Building(addr, area, floors), frameWeight(frameW), assembled(false) {}

void SteelConstruction::AssembleFrame() {
    assembled = true;
    std::cout << "Металлический каркас собран.\n";
}

void SteelConstruction::Dismantle() {
    if (!assembled) throw InvalidAccessException("Конструкция не собрана, разборка невозможна.");
    assembled = false;
    std::cout << "Конструкция разобрана.\n";
}

void SteelConstruction::PrintBuildingInfo() const {
    std::cout << "Металлическая конструкция: площадь " << totalArea
              << " м², вес каркаса " << frameWeight << " кг.\n";
}
