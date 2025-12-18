#include "Place.h"
#include <iostream>

Place::Place(const std::string& addr, const std::string& cityName, double areaSize)
    : address(addr), city(cityName), area(areaSize), isOccupied(false) {}

void Place::ReservePlace() {
    if (isOccupied) {
        std::cout << "Место уже занято.\n";
        return;
    }
    isOccupied = true;
    std::cout << "Место зарезервировано: " << address << std::endl;
}

void Place::FreePlace() {
    isOccupied = false;
    std::cout << "Место свободно: " << address << std::endl;
}

void Place::PrintInfo() const {
    std::cout << "Адрес: " << address << ", город: " << city
              << ", площадь: " << area
              << ", занято: " << (isOccupied ? "да" : "нет") << std::endl;
}
