#include "Building.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Building::Building(const std::string& addr, double area, int fl)
    : address(addr), totalArea(area), floors(fl), completed(false), project(nullptr) {}

void Building::BuildFoundation() {
    std::cout << "Закладка фундамента по адресу: " << address << ".\n";
}

void Building::Construct() {
    if (completed) throw InvalidAccessException("Здание уже построено.");
    completed = true;
    std::cout << "Строительство завершено на объекте: " << address << ".\n";
}

void Building::Paint(const std::string& color) {
    std::cout << "Здание покрашено в цвет: " << color << ".\n";
}

void Building::PrintBuildingInfo() const {
    std::cout << "Адрес: " << address
              << ", этажей: " << floors
              << ", площадь: " << totalArea
              << ", статус: " << (completed ? "готово" : "строится") << ".\n";
}
