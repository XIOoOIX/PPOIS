#include "Apartment.h"
#include <iostream>

Apartment::Apartment(const std::string& addr, double area, int floors, int count)
    : Building(addr, area, floors), apartmentsCount(count), hasElevator(false) {}

void Apartment::AddApartment() {
    apartmentsCount++;
    std::cout << "Добавлена новая квартира. Всего: " << apartmentsCount << ".\n";
}

void Apartment::InstallElevator() {
    hasElevator = true;
    std::cout << "Установлен лифт.\n";
}

void Apartment::PrintBuildingInfo() const {
    std::cout << "Многоквартирное здание: " << apartmentsCount
              << " квартир, этажей: " << floors
              << ", лифт: " << (hasElevator ? "есть" : "нет") << ".\n";
}
