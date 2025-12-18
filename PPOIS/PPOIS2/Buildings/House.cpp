#include "House.h"
#include <iostream>

House::House(const std::string& addr, double area, int floors, const std::string& owner)
    : Building(addr, area, floors), hasGarden(false), rooms(3), ownerName(owner) {}

void House::BuildGarden() {
    hasGarden = true;
    std::cout << "У дома построен сад.\n";
}

void House::AddRoom() {
    rooms++;
    std::cout << "Добавлена комната. Всего комнат: " << rooms << ".\n";
}

void House::Paint(const std::string& color) {
    std::cout << "Дом покрашен хозяином " << ownerName << " в цвет " << color << ".\n";
}

void House::PrintBuildingInfo() const {
    std::cout << "Дом (" << floors << " этажей, " << rooms
              << " комнат), владелец: " << ownerName
              << ", сад: " << (hasGarden ? "есть" : "нет") << ".\n";
}
